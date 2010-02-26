#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string jsonString;
char * getSproutItem()
{
	//Obtain temp file directory. 
	char* tPath = getenv("TEMP"); 
	char* tFile = "\\spr138.txt"; 
	char* filepath = (char*)malloc((strlen(tPath) + strlen(tFile)) * sizeof(char));	
	if(filepath == NULL)
	{
		printf("Can not obtain filepath for spr138.txt\n");
		exit(1); 
	}

	strcpy(filepath, tPath); 
	strcat(filepath, tFile); 

	FILE *myFile; 
	int c, i; 

	for(; ; )
	{
		//Allow time for client to write new data to spr138.
		Sleep(25); 

		//Open file		
		if((myFile = fopen(filepath, "r")) == NULL)
		{
			printf("Can not access spr138.txt in temp directory. Is the client running?\n");
			printf("%s\n", filepath); 
			exit(1); 
		}

		//determine file size
		for(i = 1; getc(myFile) != EOF; i++){}
		

		//If File is not empty, clear file & return its contents. 
		if(i > 1)
		{
			rewind(myFile); 
			char* output = (char*)malloc(i * sizeof(char)); 
			if(output == NULL)
			{ 
				printf("Memory Error in API\n");  
				exit(1); 
			}
			
			//Get each character from file
			for(i = 0; (c = getc(myFile)) != EOF; i++)
			{
				*(output + i) = c; 
			}
			*(output + i) = '\0';  

			//Delete file contents
			freopen(filepath, "w", myFile); 
			 
			fclose(myFile);
			free(filepath); 
			return output;
		}
		fclose(myFile);
	}
}