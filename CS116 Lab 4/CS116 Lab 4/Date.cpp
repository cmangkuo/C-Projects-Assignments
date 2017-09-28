#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
// Default Constructor, set date to 1/1/2000
Date::Date()
{
	month = 1;
	day = 1;
	year = 2000;
	cout << "Date sucessfully set as 01/01/2000." << endl;
}

// Check number of days in the month
int Date::checkDays(int m, int y)
{
	int numDays;
	while ((m < 1) || (m > 12))
	{
		cout << "Month value is invalid, please re-enter (1-12): ";
		cin >> m;
		cin.ignore();
		while (!m)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize> ::max(), '\n');
			}
			cout << "Please enter a valid month: ";
			cin >> m;
			cin.ignore();
		}
	}
	while (y < 0)
	{
		cout << "Year cannot be negative, please re-enter: ";
		cin >> y;
		cin.ignore();
		while (!y)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid year: ";
			cin >> y;
			cin.ignore();
		}
	}
	switch (m)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			numDays = 31;
			break;
		case 4: case 6: case 9: case 11:
			numDays = 30;
			break;
		case 2:
			if (y % 4 == 0)
			{
				numDays = 29;
			}
			else
			{
				numDays = 28;
			}
			break;
		
	}
	return numDays;
}

// Set a specific date, defaults to 1/1/2000 if input is invalid
Date::Date(int m, int d , int y)
{
	bool valid = true;
	int numDays;
	// Check if month/year are valid
	if ((m < 1) || (m > 12) || (y < 0))
	{
		valid = false;
	}
	// If month/year are valid, check if day is valid
	if (valid)
	{
		numDays = checkDays(m, y);
		if ((d < 1) || (d > numDays))
		{
			valid = false;
		}
	}
	// If all valid, change date
	if (valid)
	{
		month = m;
		day = d;
		year = y;
		cout << "Successfully set date as: " << setfill('0') << setw(2) << month << "/" << day << "/" << year << "." << endl;
	}
	// If not valid, set to default date
	else if (!valid)
	{
		cout << "Invalid date value(s), setting date to 01/01/2000." << endl;
		month = 1;
		day = 1;
		year = 2000;
	}
}


bool Date::setDate(int m, int d, int y)
{
	// Check for number of days in month
	bool valid = true;
	int numDays;
	

	// Check month/year for validity
	if ((m < 1) || (m > 12) || (y < 0))
	{
		valid = false;
	}
	// If month/year are valid, check if day is valid
	if (valid)
	{
		numDays = checkDays(m, y);
		if ((d < 1) || (d > numDays))
		{
			valid = false;
		}
	}
	// If valid, set the date
	if (valid)
	{
		month = m;
		day = d;
		year = y;
		cout << "Successfully set date as: " << setfill('0') << setw(2) << month << "/" << day << "/" << year << "." << endl;
	}
	// If invalid, dont change date
	else if (!valid)
	{
		cout << "Invalid value(s), date has not been changed." << endl;
		printShort();
	}
	// Return boolean value
	return valid;
}

// Display the date
void Date::getDate(int&refmonth, int&refday, int&refyear)
{
	refmonth = month;
	refday = day;
	refyear = year;
	cout << "Date is: " << setfill('0') << setw(2) << refmonth << "/" << refday << "/" << refyear << "." << endl;

}


// Print date in short form
void Date::printShort()
{
	cout << "Date is: " << setfill('0') << setw(2) << month << "/" << day << "/" << year << "." << endl;
}


// Print date in long form
void Date::printLong()
{
	string monthName;
	
	switch (month)
	{
	case 1:
		monthName = "January";
		break;
	case 2:
		monthName = "February";
		break;
	case 3:
		monthName = "March";
		break;
	case 4:
		monthName = "April";
		break;
	case 5:
		monthName = "May";
		break;
	case 6:
		monthName = "June";
		break;
	case 7:
		monthName = "July";
		break;
	case 8:
		monthName = "August";
		break;
	case 9:
		monthName = "September";
		break;
	case 10:
		monthName = "October";
		break;
	case 11:
		monthName = "November";
		break;
	case 12:
		monthName = "December";
		break;
	}

	cout << "Date is: " << monthName << " " << day << ", " << year << endl;

}


// Check if date is equal to another date
bool Date::isEqual(Date a)
{
	bool isEqual;
	if ((month != a.month) || (day != a.day) || (year != a.year))
	{
		isEqual = false;
		cout << "Dates are not equal." << endl;
	}
	else if ((month == a.month) && (day == a.day) && (year == a.year))
	{
		isEqual = true;
		cout << "Dates are equal." << endl;
	}
	return isEqual;
}
// Add 1 to day value, account for changes in month/year
void Date::increment()
{
	// Check number of days in month
	int numDays;
	numDays = checkDays(month, year);
	// Add 1 to day value
	day++;
	// If day exceeds max, set day to 1 and increment month, same for months/years
	if (day > numDays)
	{
		day = 1;
		month++;
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
	cout << "Date successfully changed!" << endl;
	printShort();
}
// Decrease day value by 1, account for changes in month/year
void Date::decrement()
{
	// Boolean for whether we need to check the number of days if the month/year changes
	bool setDay = false;
	// Decrease day by 1
	day--;
	// Check if we need to go back a month
	if (day == 0)
	{
		month--;
		setDay = true;
	}
	// Check if we need to go back a year
	if (month == 0)
	{
		month = 12;
		year--;
		setDay = true;
	}
	if (setDay)
	{
		day = checkDays(month, year);
	}
	cout << "Date successfully changed!" << endl;
	printShort();
}
