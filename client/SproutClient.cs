using System;
using System.Collections.Generic;
using System.Text;
using System.Threading; 
using System.Net;
using System.Net.Sockets;
using System.IO; 
using MySql.Data.MySqlClient;
using Npgsql;
using NATUPNPLib; 

public struct Config
{
    public bool useDb;
    public String dbType;
    public String dbHost;
    public int dbPort;
    public String dbName;
    public String dbUser;
    public String dbPassword;
    public String dbTable;
    public String dbCol;
}

class SproutClient
{
    const int THREAD_COUNT = 9;

    static String useUpnp = ""; 
    static String configPath = "2sprout.conf"; 
    static String cypher;
    static String secretKey;
    static String cypherTemp = "AosIMELjRx"; 
    static String secretKeyTemp = "what";
    static int sleepTime; 

    static List<int> packetsReceived;
    static List<int> packetsReceivedDay2;

    static List<int> packetsMissed;
    static List<int> packetsMissedDay2;

    static List<int> reSentMissedPackets;
    static List<int> reSentMissedPacketsDay2; 

    static Queue<String> sproutQueue; 
    static Queue<String> unprocessedQueue;

    static int port = 0;
    static String currentDate;
    static String nextDate;
    static bool dateReceived = false;

    static Config dbConfig; 


    public static void Main(String[] args)
    {

        if (!ParseArguments(args))
        {
            //Console.ReadLine(); 
            return;
        }

        if (port == 0)
        {
            port = 4950; 
        }

        Console.WriteLine("Port: " + port.ToString()); 

        //Global variables. 
        packetsReceived = new List<int>();
        packetsReceivedDay2 = new List<int>();
        packetsMissed = new List<int>();
        packetsMissedDay2 = new List<int>();
        reSentMissedPackets = new List<int>();
        reSentMissedPacketsDay2 = new List<int>(); 
    
        unprocessedQueue = new Queue<String>();
        sproutQueue = new Queue<String>();
        currentDate = "";
        nextDate = "";
        dateReceived = false;

        dbConfig = ReadConfig();
        if (useUpnp.Equals("true", StringComparison.OrdinalIgnoreCase))
        {
            SetUpnp();
        }
        if (!RegisterClient())
        {
            //Console.ReadLine();
            return; 
        }
        
        //# of threads will change as program evolves. 
        Thread [] myThreads = new Thread[THREAD_COUNT];

        myThreads[0] = new Thread(new ThreadStart(GetSecretKey));
        myThreads[1] = new Thread(new ThreadStart(CastListener));
        myThreads[2] = new Thread(new ThreadStart(CheckPacketReliability));
        myThreads[3] = new Thread(new ThreadStart(CheckLostPackets)); 
        myThreads[4] = new Thread(new ThreadStart(CheckLostPacketsDay2)); 
        myThreads[5] = new Thread(new ThreadStart(ReplaceLostPackets));
        myThreads[6] = new Thread(new ThreadStart(ReplaceLostPacketsDay2)); 

        if (dbConfig.useDb)
        {
            myThreads[7] = new Thread(new ThreadStart(InsertIntoDb));
            myThreads[8] = null;
        }
        else
        {
            myThreads[7] = new Thread(new ThreadStart(CreateAndReadPipe));
            myThreads[8] = new Thread(new ThreadStart(GetFeed)); 
        }      

        for (int i = 0; i < THREAD_COUNT; i++)
        {
            if(myThreads[i] != null)
                myThreads[i].Start(); 
        }

        for (int i = 0; i < THREAD_COUNT; i++)
        {
            if (myThreads[i] != null)
                myThreads[i].Join(); 
        }
    }

    //Returns true if arguments are acceptable, otherwise false. 
    public static bool ParseArguments(String [] args)
    {
        for (int i = 0; i < args.Length; i++)
        {
            if (args[i].Equals("-p", StringComparison.OrdinalIgnoreCase))   //Set Port Number
            {
                i++; 
                if(i >= args.Length || !int.TryParse(args[i], out port))
                {
                    ShowHelp(args);
                    return false; 
                }
                if (port <= 1024)
                {
                    Console.WriteLine("Port Number is Reserved, must be greater than 1024: " + port.ToString());
                    return false;
                }
            }
            else if (args[i].Equals("-c", StringComparison.OrdinalIgnoreCase))  //Set configuration file path
            {
                i++;
                if (i >= args.Length || args[i].Length < 1)
                {
                    ShowHelp(args);
                    return false; 
                }
                configPath = args[i]; 
            }
            else if (args[i].Equals("-h", StringComparison.OrdinalIgnoreCase))  //Show help info
            {
                ShowHelp(args);
                return false; 
            }
            else if (args[i].Equals("-v", StringComparison.OrdinalIgnoreCase))  //Show version #
            {
                Version myVersion = System.Reflection.Assembly.GetExecutingAssembly().GetName().Version;
                Console.WriteLine("Version: {0}.{1}   Build: {2}.{3}", myVersion.Major, myVersion.Minor, myVersion.Build, myVersion.Revision);
                return false; 
            }
            else if (args[i].Equals("-d", StringComparison.OrdinalIgnoreCase))  //Test Database
            {
                if (TestDataBase())
                {
                    Console.WriteLine("Database Connection Successful"); 
                }
                else
                {
                    Console.WriteLine("Unable to connect to Database. Please check configuration."); 
                }
                return false; 
            }
            else
            {
                ShowHelp(args);
                return false;
            }
        }
        return true; 
    }


    public static void ShowHelp(String [] args)
    {
        Console.WriteLine("Usage: SproutClient.exe [-p port_number] [-c configuration_path]");
        Console.WriteLine("Optional: [-h help][-v version]");
    }


    //Will return false if, for any reason, the client could not be registered. 
    public static bool RegisterClient()
    {
        WebClient webClient = new WebClient();
        UTF8Encoding utfObj;
        String input; 
        String[] keys;
        byte[] reqHTML = null; 

        //Will be appended as server is developed. 
        String url = "http://2sprout.com/r/8573/Frer8n4drE"; 

        try
        {
            reqHTML = webClient.DownloadData(url);
        }
        catch (WebException e)
        {
            Console.WriteLine(e.Message);
            return false; 
        }

        utfObj = new UTF8Encoding();
        input = utfObj.GetString(reqHTML);

        if (input.Equals("0000"))
        {
            Console.WriteLine("Client already exists in database"); 
            return false; 
        }

        input = Convert.DecodeFrom64(input);
        input = Convert.EncryptDecrypt(input, "2#sPr0uT5!");
        keys = input.Split(new String[1] { "^" }, 3, StringSplitOptions.None);
        Console.WriteLine("Init: {0}  {1}  {2}", keys[0], keys[1], keys[2]);

        if (keys.Length == 3 && keys[0] != "" && keys[1] != "" && keys[2] != "")
        {
            cypher = keys[0]; 
            secretKey = keys[1];
            sleepTime = int.Parse(keys[2]); 
        }

        Console.WriteLine("Client Sucessfully Registered");
        return true; 
    }

    //Will be called from Main
    public static Config ReadConfig()
    {
        int numOfArgsFound = 0;
        String line;
        int foundPos = 0; 
        String firstSub = ""; 
        String secondSub = "";  
        Config myConfig = new Config();
        StreamReader stream = null;
        FileInfo sourceFile = new FileInfo(configPath); //"2sprout.conf"
        try
        {
            stream = sourceFile.OpenText();
        }
        catch (FileNotFoundException e)
        {
            Console.WriteLine(e.Message);
            myConfig.useDb = false;  
            return myConfig; 
        }

        while (!stream.EndOfStream)
        {
            line = stream.ReadLine();
            foundPos = line.IndexOf('=');
            if (foundPos != -1)
            {
                firstSub = line.Substring(0, foundPos);
                secondSub = line.Substring(foundPos + 1);
                if (firstSub == "upnp")
                {
                    useUpnp = secondSub; 
                }
                else if (firstSub == "usedb" && secondSub == "false")
                {
                    myConfig.useDb = false;
                    stream.Close(); 
                    return myConfig; 
                }
                else if (firstSub == "usedb" && secondSub == "true")
                {
                    myConfig.useDb = true; 
                    numOfArgsFound++;
                }

                if (firstSub == "dbtype" && secondSub != "")
                {
                    myConfig.dbType = secondSub;
                    numOfArgsFound++;
                }
                if (firstSub == "dbhost" && secondSub != "")
                {
                    myConfig.dbHost = secondSub;
                    numOfArgsFound++;
                }
                if (firstSub == "dbport" && secondSub != "")
                {
                    myConfig.dbPort = int.Parse(secondSub); 
                    numOfArgsFound++;
                }
                if (firstSub == "dbname" && secondSub != "")
                {
                    myConfig.dbName = secondSub;
                    numOfArgsFound++;
                }
                if (firstSub == "dbuser" && secondSub != "")
                {
                    myConfig.dbUser = secondSub;
                    numOfArgsFound++;
                }
                if (firstSub == "dbpassword" && secondSub != "")
                {
                    myConfig.dbPassword = secondSub;
                    numOfArgsFound++;
                }
                if (firstSub == "dbtable" && secondSub != "")
                {
                    myConfig.dbTable = secondSub;
                    numOfArgsFound++;

                }
                if (firstSub == "dbcol" && secondSub != "")
                {
                    myConfig.dbCol = secondSub;
                    numOfArgsFound++;
                }
            }
        }

        stream.Close(); 
        if (numOfArgsFound != 9)
        {
            Console.WriteLine("Problem: 2sprout.conf corrupted.");
            throw new FormatException(); 
        }

        return myConfig; 
    }

    //Will obtain the cypher and secret key from 2sprout. 
    public static void GetSecretKey()
    { 
        WebClient webClient = new WebClient();
        UTF8Encoding utfObj;
        String input; 
        String[] keys;
        byte[] reqHTML = null; 

        for (; ; )
        {
            Thread.Sleep(sleepTime);
            try
            {
                reqHTML = webClient.DownloadData("http://2sprout.com/u/8573/Frer8n4drE/");
            }
            catch (WebException e)
            {
                Console.WriteLine(e.Message); 
            }
            utfObj = new UTF8Encoding();
            input = utfObj.GetString(reqHTML);
            input = Convert.DecodeFrom64(input); 

            //The key will change to the previous obtained key.
            input = Convert.EncryptDecrypt(input, cypher); 
            keys = input.Split(new String[1] { "^" }, 3, StringSplitOptions.None);

            Console.WriteLine("{0}  {1}  {2}", keys[0], keys[1], keys[2]);
            if (keys.Length == 3 && keys[0] != "" && keys[1] != "" && keys[2] != "")
            {
                cypher = keys[0];
                secretKey = keys[1];
                sleepTime = int.Parse(keys[2]); 
            }
        }

    }

    //Return true if database test is successful. 
    public static bool TestDataBase()
    {
        dbConfig = ReadConfig();
        if (dbConfig.dbType == "mysql")
        {
            MySqlConnection connection;
            String connect = String.Format("server={0};database={1};uid={2};password={3};port={4}",
                dbConfig.dbHost, dbConfig.dbName, dbConfig.dbUser, dbConfig.dbPassword, dbConfig.dbPort);
            try
            {
                connection = new MySqlConnection(connect);
                connection.Open();
            }
            catch (Exception e)
            {
                Console.WriteLine("Problem: mysql failed to connect.");
                Console.WriteLine(e.Message);
                return false;
            }
            connection.Close();
            return true; 
        }
        else if (dbConfig.dbType == "postgres")
        {
            NpgsqlConnection connection;

            string connstring = String.Format("Server={0};Port={1};" +
                "User Id={2};Password={3};Database={4};",
                dbConfig.dbHost, dbConfig.dbPort, dbConfig.dbUser,
                dbConfig.dbPassword, dbConfig.dbName);

            try
            {
                connection = new NpgsqlConnection(connstring);
                connection.Open();
            }
            catch (Exception e)
            {
                Console.WriteLine("Problem: postgres failed to connect.");
                Console.WriteLine(e.Message);
                return false;
            }
            connection.Close();
            return true; 
        }
        return false; 
    }


    public static void InsertIntoDb()
    {
        String query = "";

        if (dbConfig.useDb)
        {
            if (dbConfig.dbType == "mysql")         //Inserting into mysql database. 
            {
                MySqlConnection connection;
                String connect = String.Format("server={0};database={1};uid={2};password={3};port={4}",
                    dbConfig.dbHost, dbConfig.dbName, dbConfig.dbUser, dbConfig.dbPassword, dbConfig.dbPort);
                try
                {
                    connection = new MySqlConnection(connect);
                    connection.Open();
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                    return;
                }

                for (; ; )
                {
                    Monitor.Enter(sproutQueue);
                    if (sproutQueue.Count == 0)
                    {
                        Monitor.Exit(sproutQueue);
                        Thread.Sleep(100);
                    }
                    else
                    {
                        while (sproutQueue.Count > 0)
                        {
                            query = sproutQueue.Dequeue().Replace("\\", "\\\\");
                            query = query.Replace("'", "\\'");
                            query = String.Format("INSERT INTO {0} (`{1}`) VALUES('{2}')", dbConfig.dbTable, dbConfig.dbCol, query);
                            MySqlCommand insertData = new MySqlCommand(query, connection);

                            try
                            {
                                insertData.ExecuteNonQuery();
                                Console.WriteLine("MySQL insert successful");
                            }
                            catch (Exception e)
                            {
                                Console.WriteLine(e.Message);
                                //return; 
                            }
                        }
                        Monitor.Exit(sproutQueue);
                    }
                }
            }
            else if (dbConfig.dbType == "postgres")  //Inserting into postgres database
            {
                NpgsqlConnection connection;

                string connstring = String.Format("Server={0};Port={1};" +
                    "User Id={2};Password={3};Database={4};",
                    dbConfig.dbHost, dbConfig.dbPort, dbConfig.dbUser,
                    dbConfig.dbPassword, dbConfig.dbName);

                try
                {
                    connection = new NpgsqlConnection(connstring);
                    connection.Open();
                }
                catch (Exception e)
                {
                    Console.WriteLine("Problem: postgres failed to connect.");
                    Console.WriteLine(e.Message);
                    return;
                }
                for (; ; )
                {
                    Monitor.Enter(sproutQueue);
                    if (sproutQueue.Count == 0)
                    {
                        Monitor.Exit(sproutQueue);
                        Thread.Sleep(100);
                    }
                    else
                    {
                        while (sproutQueue.Count > 0)
                        {
                            query = sproutQueue.Dequeue().Replace("\\", "\\\\");
                            query = query.Replace("'", "\\'");
                            query = String.Format("INSERT INTO {0} ({1}) VALUES('{2}')", dbConfig.dbTable, dbConfig.dbCol, query);
                            NpgsqlCommand insertData = new NpgsqlCommand(query, connection);

                            try
                            {
                                insertData.ExecuteNonQuery();
                                Console.WriteLine("postgres insert successful");
                            }
                            catch (Exception e)
                            {
                                Console.WriteLine("Problem: postgres failed to insert data.");
                                Console.WriteLine(e.Message);
                                //return; 
                            }
                        }
                        Monitor.Exit(sproutQueue);
                    }
                }
            }
        }
    }



    public static void CastListener()
    {
        byte[] inBytes;
        String inData;

        IPEndPoint myEndPoint = new IPEndPoint(IPAddress.Any, port);
        UdpClient myClient;

        try
        {
            myClient = new UdpClient(myEndPoint);
        }
        catch (SocketException e)
        {
            Console.WriteLine(e.ToString());
            return;
        }

        Console.WriteLine("Entering Listener");

        for (; ; )
        {
            try
            {
                inBytes = myClient.Receive(ref myEndPoint);
            }
            catch (ObjectDisposedException e)
            {
                Console.WriteLine(e.ToString());
                return;
            }
            catch (SocketException e)
            {
                Console.WriteLine(e.ToString());
                return;
            }

            Console.WriteLine("Receive From " + myEndPoint.Address.ToString());

            inData = Encoding.ASCII.GetString(inBytes);

            Monitor.Enter(unprocessedQueue); 
                unprocessedQueue.Enqueue(inData);
            Monitor.Exit(unprocessedQueue); 
        }

    }



    public static void CheckLostPackets()
    {
        List<int> tempList = new List<int>();
        int sizeOfReceived;
        int lastPacket;
        int sizeOfVector;
        int sizeOfNewPackets;
        int remainder; 

        Console.WriteLine("Checking lost packets."); 

        for (; ; )
        {
            Thread.Sleep(15); 
            sizeOfReceived = packetsReceived.Count;

            if (sizeOfReceived > 1)
            {
                Monitor.Enter(packetsReceived); 
                    tempList.AddRange(packetsReceived);        
                    packetsReceived.Clear();
                Monitor.Exit(packetsReceived); 

                tempList.Sort();
                lastPacket = tempList[tempList.Count - 1];

                Monitor.Enter(packetsReceived); 
                    packetsReceived.Add(lastPacket);
                Monitor.Exit(packetsReceived); 

                sizeOfVector = packetsMissed.Count;
                sizeOfNewPackets = tempList.Count;

                for (int i = 0; i < sizeOfNewPackets - 1; i++) 
                {

                    remainder = tempList[i + 1] - tempList[i];

                    if (remainder != 1)
                    {
                        Console.WriteLine("There is a missing packet day 1: " + tempList[i].ToString());

                        for (int j = 1; j < remainder; j++)
                        {
                            Monitor.Enter(packetsMissed); 
                                packetsMissed.Add(tempList[i] + j);
                            Monitor.Exit(packetsMissed); 
                        }
                    }
                }
                tempList.Clear(); 
            }
        }
    }

    public static void ReplaceLostPackets()
    {
        //Thread.Sleep(int.MaxValue); //TO BE REMOVED UPON IMPLEMENTATION
    }
    public static void CheckLostPacketsDay2()
    {
        //Thread.Sleep(int.MaxValue); //TO BE REMOVED UPON IMPLEMENTATION
    }

    public static void ReplaceLostPacketsDay2()
    {
        //Thread.Sleep(int.MaxValue); //TO BE REMOVED UPON IMPLEMENTATION
    }

    //Uses custom API instead of Mail Slot from 6-2-09
    public static void GetFeed()
    {
        String path = @"c:\kingHippo\data.dat"; //Temporary location
        StreamWriter writer;

        Console.WriteLine("Starting Feed at GetFeed");
        for (; ; )
        {
            Monitor.Enter(sproutQueue);
            if (sproutQueue.Count == 0)
            {
                Monitor.Exit(sproutQueue);
                Thread.Sleep(100);
            }
            else
            {
                try
                {
                    writer = new StreamWriter(path, true);
                    while (sproutQueue.Count > 0)
                    {
                        writer.WriteLine(sproutQueue.Dequeue());
                    }
                    writer.Close();
                    writer.Dispose();
                }
                catch (Exception)
                {
                    Thread.Sleep(10);
                }
                Monitor.Exit(sproutQueue);
                Thread.Sleep(4);
            }
        }
    }

    public static void CreateAndReadPipe()
    {
        //Thread.Sleep(int.MaxValue); //TO BE REMOVED UPON IMPLEMENTATION
    }

    public static void SetUpnp()
    {
        UPnPNATClass upnpnat; 
        try
        {
            upnpnat = new NATUPNPLib.UPnPNATClass();
        }
        catch(Exception e)
        {
            Console.WriteLine(e.Message);
            return; 
        }
        IStaticPortMappingCollection mappings = upnpnat.StaticPortMappingCollection;
        IPHostEntry host = null; 

        if(mappings == null)
        {
            Console.WriteLine("Could not set Upnp support."); 
            return; 
        }

        try
        {
            host = Dns.GetHostEntry(Dns.GetHostName());
        }
        catch (SocketException e)
        {
            Console.WriteLine(e.Message);
            return;
        }
        catch (Exception e)
        {
            Console.WriteLine("Could not obtain local IP address for Upnp.");
            Console.WriteLine(e.Message);
            return;
        }
        String address = ""; 
        if (host.AddressList.Length > 0)
        {
            for (int i = 0; i < host.AddressList.Length; i++)
            {
                address = host.AddressList[i].ToString(); 
                if(Convert.IsIPv4(address))
                {
                    //Console.WriteLine(address);
                    mappings.Add(port, "UDP", port, address, true, "2Sprout");
                }
            }
        }

        //Display all ports that are currently being forwarded using Upnp. 

        Console.WriteLine("Forwarded Ports: "); 
        foreach (IStaticPortMapping portMapping in mappings)
        {
            Console.WriteLine(portMapping.InternalPort);
        }
    }

    public static void CheckPacketReliability()
    {

        String token;
        String[] section;
        String castMinusMd5;
        int section3; 

        for (; ; )
        {
            Monitor.Enter(unprocessedQueue);
            if (unprocessedQueue.Count == 0)
            {
                Monitor.Exit(unprocessedQueue);
                Thread.Sleep(100);
            }
            else
            {
                token = unprocessedQueue.Dequeue();
                Monitor.Exit(unprocessedQueue);

                //Convert from base 64 and decrypt
                token = Convert.DecodeFrom64(token);
                token = Convert.EncryptDecrypt(token, cypherTemp); 

                section = token.Split(new String[1] { "^" }, 6, StringSplitOptions.None);

                if (section.Length != 6 || section[0].Equals("") || section[1].Equals("") || section[2].Equals("")
                    || section[3].Equals("") || section[4].Equals("") || section[5].Equals(""))
                {
                    Console.WriteLine("Problem: not all data received");
                }
                else //input has the correct # of sections
                {
                    castMinusMd5 = section[1] + "^" + section[2] + "^" + section[3] + "^" + section[4] + "^" + section[5];

                    if (!Convert.GetMD5(castMinusMd5).Equals(section[0]))
                    {
                        Console.WriteLine("Problem: MD5 mismatch"); 
                    }
                    else//MD5 is good to go
                    {
                        if (!section[1].Equals(secretKeyTemp))
                        {
                            Console.WriteLine("Problem: Secret Key Failed"); 
                        }
                        else//Secret Key passes
                        {
                            if (currentDate.Equals(""))
                            {
                                currentDate = section[2]; 
                            }
                            if (!section[2].Equals(currentDate) && nextDate.Equals(""))
                            {
                                nextDate = section[2]; 
                            }
                            
                            //Parse out packet Number
                            if (!int.TryParse(section[3], out section3))
                            {
                                Console.WriteLine("Problem: Bad Packet Number");
                            }
                            else//Packet Number parsed OK
                            {

                                if (section[2].Equals(currentDate) && section[4] != "0")
                                {
                                    Monitor.Enter(reSentMissedPackets); 
                                        reSentMissedPackets.Add(section3);
                                    Monitor.Exit(reSentMissedPackets); 
                                }
                                if (section[2].Equals(currentDate) && section[4] == "0")
                                {
                                    Monitor.Enter(packetsReceived); 
                                        packetsReceived.Add(section3);
                                    Monitor.Exit(packetsReceived); 
                                }
                                if (section[2].Equals(nextDate) && section[4] != "0")
                                {
                                    Monitor.Enter(reSentMissedPacketsDay2); 
                                        reSentMissedPacketsDay2.Add(section3);
                                    Monitor.Exit(reSentMissedPacketsDay2); 
                                }
                                if (section[2].Equals(nextDate) && section[4] == "0")
                                {
                                    Monitor.Enter(packetsReceivedDay2); 
                                        packetsReceivedDay2.Add(section3);
                                    Monitor.Exit(packetsReceivedDay2); 
                                }

                                if (!section[2].Equals(currentDate) && !section[2].Equals(nextDate) && !dateReceived)
                                {
                                    if (packetsMissed.Count > 0)
                                        packetsMissed.Clear();
                                    if (packetsReceived.Count > 0)
                                        packetsReceived.Clear();

                                    currentDate = section[2];

                                    Monitor.Enter(packetsReceived); 
                                        packetsReceived.Add(section3);
                                    Monitor.Exit(packetsReceived); 
                                }
                                else if (!section[2].Equals(currentDate) && !section[2].Equals(nextDate) && dateReceived)
                                {
                                    if (packetsMissedDay2.Count > 0)
                                        packetsMissedDay2.Clear();
                                    if (packetsReceivedDay2.Count > 0)
                                        packetsReceivedDay2.Clear();

                                    currentDate = section[2];

                                    Monitor.Enter(packetsReceived); 
                                        packetsReceived.Add(section3);
                                    Monitor.Exit(packetsReceived); 

                                    dateReceived = false; 
                                }

                                Console.WriteLine("Packet Passed! " + section[0]); //delete after testing

                                //Everything checks out, add the packet messasge to sproutQueue. 
                                Monitor.Enter(sproutQueue);
                                sproutQueue.Enqueue(section[5]);
                                Monitor.Exit(sproutQueue);
                            }
                        }
                    }
                }
            }
        }
    }
}