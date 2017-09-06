// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{

	char string1[30] = "In the Garden";

	char string2[15] = "of Eden";

	strcat_s(string1, string2);

	cout << string1;

	cin.ignore();
	return 0;
}

