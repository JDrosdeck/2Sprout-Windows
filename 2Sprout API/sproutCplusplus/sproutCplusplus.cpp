// sproutCplusplus.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string jsonString;


__declspec(dllexport) char * getSproutItem()
{
	string Json;
	string line;

	ifstream myfile("example.txt");
	if(myfile.is_open())
	{
		while(!myfile.eof())
		{
			getline(myfile,line);
			Json += line;
			line.erase( line.begin() , line.end() );
			
		}
		//This will empty out the file
		ifstream myfile("example.txt",ios_base::out|ios_base::trunc);
		myfile.close();
	}
	cout << Json << endl;
	jsonString = Json;

  return (char *)jsonString.c_str();
}

