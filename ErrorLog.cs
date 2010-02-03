using System;
using System.Collections.Generic;
using System.Text;
using System.IO; 

class ErrorLog
{
    Object myLockObj;
    const String fileName = "ERROR_LOG.txt"; 

    public ErrorLog()
    {
        myLockObj = new Object(); 
    }

    public void WriteMessage(String msg)
    {
        lock(myLockObj)
        {
            StreamWriter writer;
            StreamReader reader; 
            //Erease old Log file Lines 
            if (File.Exists(fileName))
            {
                FileInfo fi = new FileInfo(fileName);
                if (fi.Length > 512000)
                {
                    //delete top 10 lines
                    try
                    {
                        reader = new StreamReader(fileName);
                        writer = new StreamWriter("tmp" + fileName, true);
                        for (int i = 0; !reader.EndOfStream; i++)
                        {
                            if (i < 10)
                                reader.ReadLine();
                            else
                            {
                                writer.WriteLine(reader.ReadLine()); 
                            }
                        }
                        reader.Close();
                        reader.Dispose(); 
                        writer.Close();
                        File.Delete(fileName);
                        File.Move("tmp" + fileName, fileName); 
                    }
                    catch
                    {
                        return; 
                    }
                }
            }
            try
            {
                writer = new StreamWriter(fileName, true);
                writer.WriteLine(DateTime.Now.ToString() + " : " + msg);
                writer.Flush();
                writer.Close();
                writer.Dispose(); 
            }
            catch
            {
                return; 
            }
        }
    }
}
