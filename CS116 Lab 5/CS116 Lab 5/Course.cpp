#include "stdafx.h"
#include "Course.h"
#include <string>
#include <iostream>
using namespace std;

// Default Constructor
Course::Course()
{
	// Set default parameters
	CourseID = "Class";
	Grade = 'A';
	Credits = 4;
}

// Constructor with parameters
Course::Course(string course, int credits, char grade)
{
	CourseID = course;
	// Check if credits parameter is valid
	while ((!credits)||(credits < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Invalid credits value, please re-enter: ";
		cin >> credits;
		cin.ignore();
	}

	// Set class attributes
	Credits = credits;
	Grade = grade;

}

void Course::setCourse()
{
	cout << "Enter course name: ";
	getline(cin, CourseID);

}

void Course::setCredits()
{
	int tempCredits;
	cout << "Enter number of course credits: ";
	cin >> tempCredits;
	cin.ignore();
	// Input validation
	while ((!tempCredits) || (tempCredits < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Invalid value, please re-enter: ";
		cin >> tempCredits;
		cin.ignore();
	}
	// Set class attributes
	Credits = tempCredits;

}

void Course::setGrade()
{
	char tempGrade;
	bool GradeSet = false;
	cout << "Enter course grade: ";
	cin >> tempGrade;
	cin.ignore();
	while (!GradeSet)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		// Check validity of grade input
		switch (tempGrade)
		{
			// Sets grade to an uppercase character
			case 'A': case 'a': case 'B': case 'b': case 'C': case 'c': case 'D': case 'd': case 'F': case 'f':
				tempGrade = toupper(tempGrade);
				Grade = tempGrade;
				GradeSet = true;
				break;
			default:
				cout << "Invalid grade, please re-enter: ";
				cin >> tempGrade;
				cin.ignore();
				break;
		}
	}	
}
