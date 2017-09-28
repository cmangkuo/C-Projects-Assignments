// CS116Lab4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	cout << "Default date." << endl;
	Date Default;
	cout << "------------------------------------" << endl;
	cout << "Invalid parameters." << endl;
	Date Invalid(13, 32, -1);
	cout << "------------------------------------" << endl;
	cout << "Today's date." << endl;
	Date Today(9, 27, 2017);
	cout << "------------------------------------" << endl;
	cout << "Attempt to manually set date with bad parameters." << endl;
	Today.setDate(13, 32, -1);
	cout << "------------------------------------" << endl;
	cout << "Default date, then set later to tomorrow's date." << endl;
	Date Tomorrow;
	Tomorrow.setDate(9, 28, 2017);
	cout << "------------------------------------" << endl;
	cout << "Get Date of Default." << endl;
	int testmonth, testday, testyear;
	Default.getDate(testmonth, testday, testyear);
	cout << "------------------------------------" << endl;
	cout << "Compare Default with Invalid." << endl;
	Default.isEqual(Invalid);
	cout << "------------------------------------" << endl;
	cout << "Compare Today with Tomorrow." << endl;
	Today.isEqual(Tomorrow);
	cout << "------------------------------------" << endl;
	cout << "Print Today in short form." << endl;
	Today.printShort();
	cout << "------------------------------------" << endl;
	cout << "Print tomorrow in long form." << endl;
	Tomorrow.printLong();
	cout << "------------------------------------" << endl;
	cout << "Decrement Default." << endl;
	Default.decrement();
	cout << "------------------------------------" << endl;
	cout << "Increment Default." << endl;
	Default.increment();
	cout << "------------------------------------" << endl;



	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

