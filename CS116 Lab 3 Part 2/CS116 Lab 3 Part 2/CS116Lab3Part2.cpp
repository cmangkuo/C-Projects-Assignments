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
		double getPay();

		// Calls for employee attributes and returns them
		double getHours() { return HoursWorked; }
		double getRate() { return HourlyRate; }
		string getName() { return name; }

};



int main()
{
	int choice;
	Employee Test;
	// Main loop
	while (1)
	{
		// Sets the attributes for the employee
		Test.setName();
		Test.setHours();
		Test.setRate();

		// Print out the payroll data for the employee
		cout << "Name: " << Test.getName() << endl;
		cout << "Hours Worked: " << Test.getHours() << endl;
		cout << "Hourly Rate: $" << fixed << setprecision(2) << Test.getRate() << " / hr." << endl;
		cout << "Gross Pay: $" << fixed << setprecision(2) << Test.getPay() << endl;
		cout << "----------------------------------------------------------------" << endl;
		
		// Asks user if they want to add another employee
		cout << "Another employee? 1-Yes 2-No" << endl;
		cin >> choice;
		// Input validation, loops until input is an acceptable value
		while ((!choice) || ((choice < 1) || (choice > 2)))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid value: ";
			
			cin >> choice;
			
			
		}
		cin.ignore();
		cout << "----------------------------------------------------------------" << endl;

		// Break out of loop if user does not have another employee
		if (choice == 2)
		{
			break;
		}
	}
	
	
	cout << "Press enter to exit program." << endl;
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
}

// Input employee pay rate
void Employee::setRate()
{
	cout << "Enter hourly pay rate: ";
	cin >> HourlyRate;

	// Input validation
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

	// Input validation
	while ((!HoursWorked) || (HoursWorked < 0))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Please enter a valid value: ";
		cin >> HoursWorked;
	}
}

// Calculate gross pay then returns it
double Employee::getPay()
{
	double grossPay;
	// Case for overtime
	if (HoursWorked > 40)
	{
		grossPay = (40 * HourlyRate) + ((HoursWorked - 40)*1.5*HourlyRate);
	}
	// Case for regular time
	else
	{
		grossPay = HoursWorked * HourlyRate;
	}
	return grossPay;
}
