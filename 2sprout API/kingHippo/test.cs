

using System;
using System.IO; 

public class test {
	public static void Main(String [] args)
	{
		String data; 
		String path = @"c:\kingHippo\output.txt";
                StreamWriter writer; 


		Console.WriteLine("Starting Feed"); 
		for(; ; )
		{
			data = sprout.getSproutItem(); 
			if(data != null && !data.Equals(""))
			{	
				try
				{
					writer = new StreamWriter(path, true); 
					writer.WriteLine(data);
					Console.WriteLine(data);  
					writer.Close(); 
					writer.Dispose(); 
				}
				catch(Exception)
				{
					Console.WriteLine("END IT ALL"); 
					return; 
				}
			}
		}
	}
}
