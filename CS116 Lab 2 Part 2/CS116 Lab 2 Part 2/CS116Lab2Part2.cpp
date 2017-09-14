// CS116Lab2Part2.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

//Global Variables
int numStudents, numTests;


// Struct Definitions
struct CourseGrade
{
	string StudentName, Grade;
	int IDNumber;
	double Average;
	double* TestScores;
};


// Function Prototypes
void getData(struct CourseGrade a[], int b, int c);
string calcLtr(double a);
void printReport(struct CourseGrade a[], int b, int c);


int main()
{
	
	// Get number of students.
	cout << "Enter number of students: ";
	cin >> numStudents;
	cout << endl;
	// Input validation for numStudents (type).
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please enter a valid number. " << endl;
			cin >> numStudents;
			cout << endl;
		}
		if (!cin.fail())
		{
			break;
		}
	}
	// Input validation for numStudents (value).
	while (numStudents <= 0)
	{
		cout << "Number of students must be positive!" << endl;
		cin >> numStudents;
		cout << endl;
	}


	// Get number of tests.
	cout << "Enter number of tests: ";
	cin >> numTests;
	
	// Input validation for numTests (type).
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please enter a valid number. " << endl;
			cin >> numTests;
			cin.ignore();
		}
		if (!cin.fail())
		{
			break;
		}
	}
	// Input validation for numTests (value).
	while (numTests < 2)
	{
		cout << "Must have more than 1 test!" << endl;
		cin >> numTests;
	}
	cout << "------------------------------------------" << endl;
	
	// Create a new instance of our CourseGrade struct, dynamically allocated with numStudents amount of elements
	CourseGrade* Students = new CourseGrade[numStudents];

	// Get the data on the students and their scores
	getData(Students, numStudents, numTests);
	cin.ignore();

	// Prints out all of our student's data
	printReport(Students, numStudents, numTests);


	// Delete our dynamically allocated structure
	delete[] Students;

	cout << "Press enter to exit application." << endl;
	
	cin.ignore();
    return 0;
}


// Function Definitions

/*	
	Takes an array of structures and two ints as input.
	Gets user input for student names, id numbers, and test scores.
	Calculates average test scores for each student then assigns them a letter grade.
	a: array of CourseGrade struct, b: number of students, c: number of tests 
*/
void getData(struct CourseGrade a[], int b, int c)
{
	double TotalScore, AvgScore;
	
	for (int i = 0; i < b; i++)
	{
		// Get student name & ID number.
		cout << "Student " << i + 1 << endl;
		cout << "Enter name: ";
		cin.ignore();
		getline(cin, a[i].StudentName);
		cout << endl;
		cout << "Enter student ID number: ";
		cin >> a[i].IDNumber;
		cout << endl;
		// Input validation for IDNumber (type).
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error, please enter a valid number. " << endl;
				cin >> a[i].IDNumber;
				cin.ignore();
			}
			if (!cin.fail())
			{
				break;
			}
		}
		// Input validation for IDNumber (value).
		while (a[i].IDNumber < 0) 
		{
			cout << "Please enter a valid number." << endl;
			cin >> a[i].IDNumber;
		}
		
		// Create new pointer array for this student's test scores.
		double* TestScores = new double[c];
		a[i].TestScores = TestScores;

		// Resets the total test score to zero for this student.
		TotalScore = 0;

		// Loop for inputting student's test scores.
		for (int i = 0; i < c; i++)
		{

			cout << "Enter test score " << i + 1 << ": ";
			cin >> TestScores[i];
			cout << endl;
			// Input validation
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Error, please enter a valid number. " << endl;
					cin >> TestScores[i];
					cin.ignore();
				}
				if (!cin.fail())
				{
					break;
				}
			}
			// Input validation for data value
			while ((TestScores[i] < 0) || (TestScores[i] > 100))
			{
				cout << "Please enter a valid test score." << endl;
				cin >> TestScores[i];
			}

			// Adds the input test score to the total test score.
			TotalScore += TestScores[i];
		}
		
		// Finds the student's average test score.
		AvgScore = TotalScore / c;
		a[i].Average = AvgScore;

		// Puts the average score through the calcLtr function which determines a letter grade.
		a[i].Grade = calcLtr(a[i].Average);

		/* Print out student's average test score and letter grade
		cout << "Average Score: " << fixed << setprecision(2) << a[i].Average << endl;
		cout << "Grade: " << a[i].Grade << endl;*/

		cout << "------------------------------------------" << endl;
	}

}

/*	Takes a double as input to assign a letter grade.
	a: score which we will assign a letter grade to
*/
string calcLtr(double a)
{
	string LetterGrade;
	if (a > 89)
	{
		LetterGrade = "A";
	}
	else if (a > 79)
	{
		LetterGrade = "B";
	}
	else if (a > 69)
	{
		LetterGrade = "C";
	}
	else if (a > 59)
	{
		LetterGrade = "D";
	}
	else
	{
		LetterGrade = "F";
	}
	return LetterGrade;
}

/*	
	Takes our array of structures and two ints as input
	Prints out all the data contained within the array of structures
	Prints out name, id number, average test score, and letter grade
	a: array of CourseGrade struct, b: number of students, c: number of tests
*/
void printReport(struct CourseGrade a[], int b, int c)
{
	cout << "Name" << fixed << setw(21) << "ID" << setw(22) << "Avg" << setw(22) << "Grade" << endl;
	
	for (int i = 0; i < b; i++)
	{
		cout << a[i].StudentName << fixed << setw(25 - a[i].StudentName.length()) << a[i].IDNumber << setw(25-(to_string(a[i].IDNumber).length())) 
			<< setprecision(1) << a[i].Average << setw(25-to_string(a[i].IDNumber).length()) << a[i].Grade << endl;
		
	}
}
