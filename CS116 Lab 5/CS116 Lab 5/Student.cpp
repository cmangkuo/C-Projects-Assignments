#include "stdafx.h"
#include "Student.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student()
{
	name = " ";
	idNumber = 0;
}

Student::Student(string studentname, int number)
{
	name = studentname;
	while (number < 1)
	{
		cout << "Please enter a valid id number: ";
		cin >> number;
		cin.ignore();
	}
	idNumber = number;
}

void Student::setName()
{
	string tempName;
	cout << "Enter student name: ";
	getline(cin,tempName);
	name = tempName;
}

void Student::setID()
{
	int tempID;
	cout << "Enter ID number: ";
	cin >> tempID;
	cin.ignore();
	while ((!tempID) || (tempID < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid ID number: ";
		cin >> tempID;
		cin.ignore();
	}
	idNumber = tempID;
}

void Student::setID(int a)
{
	idNumber = a;
}

void Student::addCourse()
{
	int size = VectorOfCourses.size() + 1;
	int index = size - 1;
	VectorOfCourses.resize(size);
	VectorOfCourses[index].setCourse();
	VectorOfCourses[index].setCredits();
	VectorOfCourses[index].setGrade();
}

double Student::getGPA()
{
	int size = VectorOfCourses.size();
	double totalCredits = 0;
	double totalGradepoints = 0;
	double GPA;
	char tempGrade;
	int tempCredits;
	for (int i = 0; i < size; i++)
	{
		tempCredits = VectorOfCourses[i].getCredits();
		totalCredits += tempCredits;
		tempGrade = VectorOfCourses[i].getGrade();
		switch (tempGrade)
		{
		case 'A':
			tempCredits *= 4;
			break;
		case 'B':
			tempCredits *= 3;
			break;
		case 'C':
			tempCredits *= 2;
			break;
		case 'D':
			break;
		case 'F':
			tempCredits *= 0;
			break;
		}
		totalGradepoints += tempCredits;
	}
	GPA = totalGradepoints / totalCredits;
	return GPA;
}

void Student::printTranscript()
{
	cout << "Course" << fixed << setw(19) << "Grade" << endl;
	for (unsigned int i = 0; i < VectorOfCourses.size(); i++)
	{
		cout << VectorOfCourses[i].getCourse() << fixed << setw(25 - VectorOfCourses[i].getCourse().size())
			<< VectorOfCourses[i].getGrade() << endl;
	}
	cout << "GPA: " << fixed << setprecision(2) << getGPA() << endl;
}

