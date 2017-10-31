#include "stdafx.h"
#include "Worker.h"
#include <string>
#include <iostream>
using namespace std;



// Parameterized Constructor
Worker::Worker(string workerName, double payRate)
{
	name = workerName;
	// Validation for payrate
	while ((!payRate) || (payRate < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid slary: ";
		cin >> payRate;
		cin.ignore();
	}
	baseSalary = payRate;
}

// Set Functions
void Worker::setName()
{
	cout << "Enter worker name: ";
	getline(cin, name);

}

void Worker::setBaseSalary()
{
	cout << "Enter worker's monthly salary: ";
	cin >> baseSalary;
	cin.ignore();
	// Input validation
	while ((!baseSalary) || (baseSalary < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a salary: ";
		cin >> baseSalary;
		cin.ignore();
	}
}
