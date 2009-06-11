using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Threading; 

namespace FileServer
{
    class ApiTestServer
    {
        static void Main(string[] args)
        {
            String path = @"c:\kingHippo\data.dat";
            FileInfo source;
            StreamReader reader;

            Console.WriteLine("Starting API Test Server"); 
            for (; ; )
            { 
                try
                {
                    source = new FileInfo(path);
                    reader = source.OpenText();
                    while(!reader.EndOfStream)
                        Console.WriteLine(reader.ReadLine());
                    reader.Close();
                    source.Delete();
                }
                catch (Exception)
                {
                    Thread.Sleep(4);
                }
            }

        }
    }
}
