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
using System.Runtime.InteropServices;
using Microsoft.Win32.SafeHandles;


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
    public bool error; 
}

class SproutClient
{
    const int THREAD_COUNT = 9;

    static String useUpnp = "";
    static String configPath; 
    static String cypher;
    static String secretKey;

////static String cypherTemp = "aACZfGGL8R";
////static String secretKeyTemp = "ePsYDJbtxC";
    static int sleepTime;

    static SproutList packetsReceived;
    static SproutList packetsReceivedDay2;

    static SproutList packetsMissed;
    static SproutList packetsMissedDay2;

    static SproutList reSentPackets;
    static SproutList reSentPacketsDay2; 

    static SproutQueue sproutQueue; 
    static SproutQueue unprocessedQueue;

    static int port = 0;
    static String currentDate;
    static String nextDate;
    static bool dateReceived = false;
    static String apiKey = ""; 

    static Config dbConfig;

    [DllImport("kernel32.dll")]
    static extern bool SetConsoleCtrlHandler(ConsoleEventHandlerDelegate
    handlerProc, bool add);


    delegate bool ConsoleEventHandlerDelegate();

    static ConsoleEventHandlerDelegate consoleHandler;

    public static void Main(String[] args)
    {
        //Used for when the program terminates
        consoleHandler = new ConsoleEventHandlerDelegate(ConsoleEventHandler);
        SetConsoleCtrlHandler(ConsoleEventHandler, true);

        configPath = AppDomain.CurrentDomain.BaseDirectory + "//2sprout.conf"; //May be changed by CLA

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
        packetsReceived = new SproutList();
        packetsReceivedDay2 = new SproutList();
        packetsMissed = new SproutList();
        packetsMissedDay2 = new SproutList();
        reSentPackets = new SproutList();
        reSentPacketsDay2 = new SproutList();

        unprocessedQueue = new SproutQueue();
        sproutQueue = new SproutQueue(); 
        currentDate = "";
        nextDate = "";
        dateReceived = false;

        dbConfig = ReadConfig();

        if (dbConfig.error) //Exit the program if the configuration file has an error. 
        {
            Console.ReadLine(); 
            return;
        }
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
        myThreads[7] = new Thread(new ThreadStart(StandardInput)); 

        if (dbConfig.useDb)
        {
            myThreads[8] = new Thread(new ThreadStart(InsertIntoDb));
        }
        else
        {
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


    //Will run when user directly terminates program. 
    static bool ConsoleEventHandler()
    {
        String url = "http://2sprout.com/disconnect/" + port + "/" + apiKey + "/";
        WebClient webClient = new WebClient();
        webClient.DownloadData(url);

        Console.WriteLine("Program Terminated."); 
        return (false);
    }

    //Will run when the API terminates program
    public static void StandardInput()
    {
        String stdIn; 
        for(; ; )
        {
            stdIn = Console.ReadLine();
            if (stdIn.Equals("EXIT"))
            {
                ConsoleEventHandler();
                System.Environment.Exit(0); 
            }
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
        Console.WriteLine("Optional: [-h help][-v version] [-d test database]");
    }


    //Will return false if, for any reason, the client could not be registered. 
    public static bool RegisterClient()
    {
        WebClient webClient = new WebClient();
        UTF8Encoding utfObj;
        String input = null; 
        String[] keys;
        byte[] reqHTML = null; 

        //Will be appended as server is developed. 
        String url = "http://2sprout.com/connect/" + port + "/" + apiKey + "/"; 

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

        try
        {
            input = utfObj.GetString(reqHTML);
        }
        catch (ArgumentNullException e)
        {
            Console.WriteLine(e.Message);
            return false; 
        }

        if (input.Equals("0000"))
        {
            Console.WriteLine("Client already exists in database"); 
            return false; 
        }

        input = Convert.DecodeFrom64(input);
        input = Convert.EncryptDecrypt(input, "2#sPr0uT5!");
        keys = input.Split(new String[1] { "^" }, 3, StringSplitOptions.None);
        Console.WriteLine("Init: {0}  {1}  {2}", keys[0], keys[1], keys[2]);

        if (keys.Length == 3 && keys[0] != "" && keys[1] != "" && keys[2] != "" && int.TryParse(keys[2], out sleepTime))
        {
            cypher = keys[0];
            secretKey = keys[1];
            sleepTime *= 1000;
            Console.WriteLine("Client Sucessfully Registered");
            return true;
        }
        else
        {
            Console.WriteLine("Client could not be registered.");
            return false; 
        }
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
        FileInfo sourceFile; 
        try
        {
            sourceFile = new FileInfo(configPath); //"2sprout.conf"
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
            myConfig.error = true; 
            return myConfig;
        }

        try
        {
            stream = sourceFile.OpenText();
        }
        catch (FileNotFoundException e)
        {
            Console.WriteLine(e.Message);
            myConfig.error = true; 
            return myConfig;
        }
        catch (Exception e)
        {
            Console.WriteLine(e.Message);
            myConfig.error = true; 
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
                    numOfArgsFound++;
                }
                else if (firstSub == "usedb")
                {
                    if (secondSub == "true")
                        myConfig.useDb = true;
                    else
                        myConfig.useDb = false;

                    numOfArgsFound++;
                }
                else if (firstSub == "dbtype")
                {
                    myConfig.dbType = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "dbhost")
                {
                    myConfig.dbHost = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "dbport")
                {
                    if (!int.TryParse(secondSub, out myConfig.dbPort))
                    {
                        myConfig.dbPort = 0;
                    }
                    numOfArgsFound++;
                }
                else if (firstSub == "dbname")
                {
                    myConfig.dbName = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "dbuser")
                {
                    myConfig.dbUser = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "dbpassword")
                {
                    myConfig.dbPassword = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "dbtable")
                {
                    myConfig.dbTable = secondSub;
                    numOfArgsFound++;

                }
                else if (firstSub == "dbcol")
                {
                    myConfig.dbCol = secondSub;
                    numOfArgsFound++;
                }
                else if (firstSub == "apiKey")
                {
                    apiKey = secondSub;

                    if (apiKey.Length != 10)
                    {
                        Console.WriteLine("API Key is not a valid length, check configuration file");
                        myConfig.error = true;
                        return myConfig;
                    }

                    for (int i = 0; i < apiKey.Length; i++)
                    {
                        if (!char.IsLetterOrDigit(apiKey[i]))
                        {
                            Console.WriteLine("Invalid API key, check configuration file.");
                            myConfig.error = true;
                            return myConfig;
                        }
                    }
                    numOfArgsFound++;
                }
            }
        }

        stream.Close(); 
        if (numOfArgsFound != 11)
        {
            Console.WriteLine("Problem: 2sprout.conf corrupted.");
            myConfig.error = true;
            return myConfig; 
        }

        myConfig.error = false; 
        return myConfig; 
    }

    //Will obtain the cypher and secret key from 2sprout. 
    public static void GetSecretKey()
    { 
        WebClient webClient = new WebClient();
        UTF8Encoding utfObj;
        String input; 
        String[] keys = null;
        byte[] reqHTML = null; 

        for (; ; )
        {
            Thread.Sleep(sleepTime);
            try
            {
                reqHTML = webClient.DownloadData("http://2sprout.com/refresh/" + port + "/" + apiKey + "/");
            }
            catch (WebException e)
            {
                Console.WriteLine(e.Message);
            }
            
            utfObj = new UTF8Encoding();

            try
            {
                input = utfObj.GetString(reqHTML);
                input = Convert.DecodeFrom64(input); 
                input = Convert.EncryptDecrypt(input, cypher);
                keys = input.Split(new String[1] { "^" }, 3, StringSplitOptions.None);
            }
            catch (ArgumentNullException e)
            {
                keys = null; 
                Console.WriteLine(e.Message);
            }
            
            if (keys != null && keys.Length == 3 && keys[0] != "" && keys[1] != "" && keys[2] != "" && int.TryParse(keys[2], out sleepTime))
            {
                cypher = keys[0];
                secretKey = keys[1];
                sleepTime *= 1000; 
                Console.WriteLine("{0}  {1}  {2}", keys[0], keys[1], keys[2]);
            }
            else
            {
                sleepTime = 30000;
                Console.WriteLine("Cypher/Secret Key Corrupted");
            }
        }

    }

    //Return true if database test is successful. 
    public static bool TestDataBase()
    {
        dbConfig = ReadConfig();
        if (dbConfig.error) //Will be unable to test database if config file is corrupted. 
            return false; 
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
                    Console.WriteLine("Problem: MySQL failed to connect.");
                    Console.WriteLine(e.Message);
                    return;
                }
                Console.WriteLine("Ready to insert into MySQL database");
                for (; ; )
                {
                    if (sproutQueue.Count > 0)
                    {
                        query = sproutQueue.Dequeue();
                        query = query.Replace("\\", "\\\\");
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
                            Console.WriteLine("Problem: MySQL failed to insert data.");
                            Console.WriteLine(e.Message);
                            //return; 
                        }
                    }
                    else
                    {
                        Thread.Sleep(100);
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

                Console.WriteLine("Ready to insert into postgres database");
                for (; ; )
                {

                    if (sproutQueue.Count > 0)
                    {
                        query = sproutQueue.Dequeue();
                        query = query.Replace("\\", "\\\\");
                        query = query.Replace("'", "\\'");
                        query = String.Format("INSERT INTO \"{0}\" (\"{1}\") VALUES('{2}')", dbConfig.dbTable, dbConfig.dbCol, query);
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
                    else
                    {
                        Thread.Sleep(100);
                    }
                }
            }
            else //No database was selected
            {
                Console.WriteLine("No DBMS Selected.");
                return; 
            }
        }
    }


    //Listen to port and place incoming packets into queue
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

            inData = Convert.DecodeFrom64(inData);
            inData = Convert.EncryptDecrypt(inData, cypher); //CYPHER TEMPORARY POSITION

            if(inData.Length > 9 && inData.Substring(0, 10).Equals(secretKey))//SECRET KEY TEMPORARY POSITION
            {
                unprocessedQueue.Enqueue(inData.Substring(10, inData.Length - 10));  
            }
            else 
            {
                Console.WriteLine("Problem: Secret Key Failed");
            }
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
                tempList = packetsReceived.GetAndClear();   

                tempList.Sort();
                lastPacket = tempList[tempList.Count - 1];

                packetsReceived.Add(lastPacket);

                sizeOfVector = packetsMissed.Count;
                sizeOfNewPackets = tempList.Count;

                //If packet numbers aren't consecutive then add to packetsMissed
                for (int i = 0; i < sizeOfNewPackets - 1; i++) 
                {

                    remainder = tempList[i + 1] - tempList[i];

                    if (remainder != 1)
                    {
                        Console.WriteLine("There is a missing packet day 1: " + tempList[i].ToString());

                        for (int j = 1; j < remainder; j++)
                        {
                            packetsMissed.Add(tempList[i] + j);
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
        String path = @"c:\kingHippo\example.txt"; //Temporary location; 
        String data = ""; 

        StreamWriter writer;

        Console.WriteLine("Starting Feed at GetFeed");
        FileInfo info;


        if (!Directory.Exists(@"c:\kingHippo\"))
            Directory.CreateDirectory(@"c:\kingHippo\"); 

        if(!File.Exists(path)) //Create the buffer file if it doesn't exist. 
            File.Create(path);

        int tempCounter = 0; 
        for (; ; )
        {

            if (sproutQueue.Count > 0 || !data.Equals(""))
            {
                try
                {
                    info = new FileInfo(path);
                    if (info.Length == 0)
                    {
                        if(data.Equals(""))
                        {
                            data = sproutQueue.Dequeue(); 
                        }
                        writer = new StreamWriter(path, true);
                        writer.WriteLine(data); 
                        writer.Close();
                        writer.Dispose();
                        Console.WriteLine("Data successfully written to API. " + tempCounter++);
                        data = ""; 
                    }
                }
                catch (Exception)
                {
                    Console.WriteLine("ERROR, COULDN'T WRITE PACKET"); 
                    Thread.Sleep(10);
                }
            }
            else
            {
                Thread.Sleep(40);
            }
        }
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
        String castMinusCheckSum;
        int section2; 

        for (; ; )
        {
            if (unprocessedQueue.Count > 0)
            {
                token = unprocessedQueue.Dequeue();

                //PACKET FORMAT: CheckSum^Date^Packet#^0/1^data
                section = token.Split(new String[1] { "^" }, 5, StringSplitOptions.None);

                if (section.Length != 5 || section[0].Equals("") || section[1].Equals("") || section[2].Equals("")
                    || section[3].Equals("") || section[4].Equals(""))
                {
                    Console.WriteLine("Problem: not all data received");
                }
                else //input has the correct # of sections
                {
                    castMinusCheckSum = "^" + section[1] + "^" + section[2] + "^" + section[3] + "^" + section[4];

                    if (!Convert.CalcCheckSum(castMinusCheckSum).Equals(section[0]))
                    {
                        Console.WriteLine("Problem: CheckSum mismatch");
                        Console.WriteLine("Expected Checksum: " + section[0]);
                        Console.WriteLine("Calculated Check : " + Convert.CalcCheckSum(castMinusCheckSum)); 
                    }
                    else//CheckSum is good to go
                    {
                        if (currentDate.Equals(""))
                        {
                            currentDate = section[1];
                        }
                        if (!section[1].Equals(currentDate) && nextDate.Equals(""))
                        {
                            nextDate = section[1];
                        }

                        //Parse out packet Number
                        if (!int.TryParse(section[2], out section2))
                        {
                            Console.WriteLine("Problem: Bad Packet Number");
                        }
                        else//Packet Number parsed OK
                        {

                            if (section[1].Equals(currentDate) && section[3] != "0")
                            {
                                reSentPackets.Add(section2);
                            }
                            if (section[1].Equals(currentDate) && section[3] == "0")
                            {
                                packetsReceived.Add(section2);
                            }
                            if (section[1].Equals(nextDate) && section[3] != "0")
                            {
                                reSentPacketsDay2.Add(section2);
                            }
                            if (section[1].Equals(nextDate) && section[3] == "0")
                            {
                                packetsReceivedDay2.Add(section2);
                            }

                            if (!section[1].Equals(currentDate) && !section[1].Equals(nextDate) && !dateReceived)
                            {
                                if (packetsMissed.Count > 0)
                                    packetsMissed.Clear();

                                if (packetsReceived.Count > 0)
                                    packetsReceived.Clear();

                                currentDate = section[1];
                                packetsReceived.Add(section2);
                            }
                            else if (!section[1].Equals(currentDate) && !section[1].Equals(nextDate) && dateReceived)
                            {
                                if (packetsMissedDay2.Count > 0)
                                    packetsMissedDay2.Clear();

                                if (packetsReceivedDay2.Count > 0)
                                    packetsReceivedDay2.Clear();


                                currentDate = section[1];

                                packetsReceived.Add(section2);
                               
                                dateReceived = false;
                            }

                            Console.WriteLine("Packet Passed! " + section[2]); //delete after testing

                            //Everything checks out, add the packet messasge to sproutQueue. 
                            sproutQueue.Enqueue(section[4]);
                        }
                        
                    }
                }
            }
            else
            {
                Thread.Sleep(100); 
            }
        }
    }
}