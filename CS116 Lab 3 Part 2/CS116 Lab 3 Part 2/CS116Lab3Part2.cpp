// CS116Lab3Part2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

// Class Definitions
class Employee
{
	private:
		string name;
		double HoursWorked, HourlyRate;
	public:
		void setName();
		void setRate();
		void setHours();

		// Calculates pay then returns it
		double getPay() { return HoursWorked*HourlyRate; }

		// Calls for employee attributes and returns them
		double getHours() { return HoursWorked; }
		double getRate() { return HourlyRate; }
		string getName() { return name; }

};



int main()
{
	Employee Test;
	Test.setRate();
	cout << "Hooray!" << endl;
	cin.ignore();
	cin.ignore();
    return 0;
}



// Class Functions
// Input employee name
void Employee::setName()
{
	cout << "Enter employee name: ";
	getline(cin, name);
	cout << endl;
}

// Input employee pay rate
void Employee::setRate()
{
	cout << "Enter hourly pay rate: ";
	cin >> HourlyRate;
	while ((!HourlyRate) || (HourlyRate < 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid value: ";
		cin >> HourlyRate;
		
	}
}

// Input hours worked
void Employee::setHours()
{
	cout << "Enter hours worked: ";
	cin >> HoursWorked;
	while ((!HoursWorked) || (HoursWorked < 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid value: ";
		cin >> HoursWorked;
		
	}
}
