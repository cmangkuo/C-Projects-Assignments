// CS 102 Lab 11
// Author : Chris Mangkuorahardjo

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

// Declaration of Student structure
struct Student
{
	
	// 1) Student name
	string FirstName;
	string LastName;
	// 2) Student ID number
	int StudentID;
	// 3) Pointer to array of test scores
	double TestScores[100];
	
	// 4) Average test score
	double AvgScore;
	// 5) Course grade
	char CourseGrade;
};

// Function prototypes
Student *initArrays(int, int);
void getInfo(Student[], int, int);
void showInfo(Student[], int, int);

int main()
{
	int numStudents; // Number of students
	int numTests; // Number of tests
	Student *list = nullptr; // Pointer to Student array

							 // Get the number of students.
	cout << "How many students? ";
	cin >> numStudents;

	// Get the number of tests per student.
	cout << "How many tests per student? ";
	cin >> numTests;

	

	// Create an array of Students
	list = initArrays(numStudents, numTests);

	
	

	// Populate the array with data.
	getInfo(list, numStudents, numTests);


	cout << "--------------------------------------------------------" << endl;


	// Display the data.
	showInfo(list, numStudents, numTests);
	
	cout << "Press Any Key to exit." << endl;
	cin.ignore();
	
	return 0;
}

//**************************************************
// Function initArrays *
// This function dynamically allocates an array *
// of Student structures and for each element in *
// the array, allocates an array of ints to hold *
// tests scors. The parameter s is the number of *
// element to allocate for the array of structures *
// and the parameter t is the number of elements *
// allocate for each array of ints. *
//**************************************************
Student *initArrays(int s, int t)
{
	Student *ptr = nullptr;

	// Allocate the array of Student structures.
	ptr = new Student[s];

	// Allocate an array of ints (to hold test scores)
	// for each element of the array of Student structures.
	for (int i = 0; i < s; i++)
	{
		ptr[i].TestScores[t];
	}
	// Return a pointer to the array of structures.
	return ptr;
}

//*****************************************************
// Function getInfo *
// This function populates the Student array s with *
// data entered by the user. The paramater ns is the *
// number of students and nt is the number of tests. *
//*****************************************************

void getInfo(Student s[], int ns, int nt)
{
	double total;
	
	// Get the data for each student.
	for (int i = 0; i < ns; i++)
	{
		total = 0;
		int score;
		cout << "--------------------------------------------------------" << endl;
		cout << "Info for Student " << (i + 1) << "." << endl;
		

		cout << "Enter first name: ";
		cin >> s[i].FirstName;
		cout << endl;

		cout << "Enter last name: ";
		cin >> s[i].LastName;
		cout << endl;

		cout << "Enter student ID: ";
		cin >> s[i].StudentID;
		cout << endl;

		for (int j = 0; j < nt; j++)
		{
			cout << "Enter test score " << (j + 1) << ": ";
			
			cin >> score;
			while (score < 0 || score > 100)
			{
				cout << "Please enter a valid score. ";
				cin >> score;
				cout << endl;
			}
			s[i].TestScores[j] = score;

			cout << endl;
			total += score;
		}

		

		s[i].AvgScore = total / nt;
		if (s[i].AvgScore > 89)
		{
			s[i].CourseGrade = 'A';
		}
		else if (s[i].AvgScore > 79)
		{
			s[i].CourseGrade = 'B';
		}
		else if (s[i].AvgScore > 69)
		{
			s[i].CourseGrade = 'C';
		}
		else if (s[i].AvgScore > 59)
		{
			s[i].CourseGrade = 'D';
		}
		else 
		{
			s[i].CourseGrade = 'F';
		}
	}
}

//*****************************************************
// Function showInfo *
// This function displays all of the data in the *
// array s. The paramater ns is the number of *
// students and nt is the number of tests. *
//*****************************************************
void showInfo(Student s[], int ns, int nt)
{
	// Displays all of the data in the array s
	
	for (int i = 0; i < ns; i++)
	{
		cout << "Student " << i + 1 << endl;
		cout << "Name: " << s[i].FirstName << " " << s[i].LastName << endl;
		cout << "Student ID: " << s[i].StudentID << endl;
		cout << "Test Scores: ";
		for (int j = 0; j < nt; j++)
		{
			cout << s[i].TestScores[j];
			if (j+1 < nt)
			{
				cout << ", ";
			}
			else
			{
				cout << ".";
			}
		}
		cout << endl;
		cout << "Average Score: " << fixed << setprecision(2) <<s[i].AvgScore << endl;
		cout << "Course Grade: " << s[i].CourseGrade << endl;
		cout << "--------------------------------------------------------" << endl;

	}
	cin.ignore();

}
