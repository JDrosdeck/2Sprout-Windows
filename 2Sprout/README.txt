2Sprout - Windows Client
c 2010 2Sprout
Scotty.Morgan@2sprout.com


-Using the Client-

Open 2Sprout.exe and click Setup to fill out the information for the Network, Database, and Developer Key. 

Network - If UPnP can't be established make sure your router has the UPnP functionality enabled. 

Database - If you're going to place incoming data into a database you must specify which database you're using (MySQL or PostgreSQL) and the corresponding database information. If you're going to use the API (explained in the next section), no other information is required. 

Developer Key - This can be obtained from http://2sprout.com/signup . You must have a developer key to use 2Sprout. 

Once all the information is filled out click Start to begin. If there is any trouble look for ERROR_LOG.txt in the base folder for details. 


-Using the API-

If you're not going to place the data into a database you can access that data directly using either C#, C++, Java, Python, or Ruby; all located in the SproutAPI folder. Each SproutAPI sub-folder contains the required .dll to use the 2sprout API functionality and a simple sample program that demonstrates how the function works. Make sure the client is up and running before testing the API. 


ENJOY!