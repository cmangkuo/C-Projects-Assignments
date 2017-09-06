// Lab Ch 13.cpp : Defines the entry point for the console application.
//




// Chapter 13, Programming Challenge 2: Employee Class
// Author Chris Mangkuorahardjo

#include <iostream>
#include <string>
using namespace std;

// Employee Class Declaration

class Employee
{
private:
	string name; // Employee's name
	int idNumber; // ID number
	string department; // Department name
	string position; // Employee's position
	
public:
	
	Employee(string n, int i, string d, string p);

	Employee(string n, int i);

	Employee();

	void displayEmployee();

	
};

// Constructor #1
Employee::Employee(string n, int i, string d, string p)
{
	
	
	name = n;
	idNumber = i;
	department = d;
	position = p;
	cout << "Successfully entered employee data." << endl;
	cout << "------------------------------------------" << endl;
}

// Constructor #2
Employee::Employee(string n, int i)
{
	
	
	name = n;
	idNumber = i;
	cout << "Enter employee department." << endl;
	getline(cin, department);
	cout << "Enter employee position." << endl;
	getline(cin, position);
	cout << "Successfully entered employee data." << endl;
	cout << "------------------------------------------" << endl;
}

// Constructor #3, default constructor
Employee::Employee()
{
	
	
	
	cout << "Enter employee name." << endl;
	getline(cin, name);
	cout << "Enter employee ID." << endl;
	cin >> idNumber;
	cin.ignore();
	cout << "Enter employee department." << endl;
	
	cin.ignore();
	getline(cin, department);
	cout << "Enter employee position." << endl;
	getline(cin, position);
	cout << "Successfully entered employee data." << endl;
	cout << "------------------------------------------" << endl;
}

void Employee::displayEmployee()
{
	
	cout << "Name: " << name << endl;
	cout << "Id: " << idNumber << endl;
	cout << "Department: " << department << endl;
	cout << "Position: " << position << endl;
	cout << "------------------------------------------" << endl;
}


// Driver program to demonstrate the class
int main()
{
	// Create an Employee object to test constructor obj #1.
	Employee One( "Susan Meyers" , 47899, "Accounting", "Vice President");
	// Create an Employee object to test constructor obj #2.
	Employee Two("Mark Jones", 39119);
	// Create an Employee object to test constructor obj #3.
	Employee Three;

	
	// Display each employee's data.
	
	One.displayEmployee();
	Two.displayEmployee();
	Three.displayEmployee();
	


	cout << "Press any key to exit" << endl;
	cin.ignore();
	return 0;
}



