#include <iostream>
#include <conio.h>
#include <windows.h>
#include "SproutCpp.h"

#pragma comment(lib,"SproutCpp.lib") 

using namespace std; 

int main()
{
	cout << "Starting Feed:" << endl;
	for(; ; )
	{
		cout << Sprout::getSproutItem() << endl; 
	}
   return 0;
}