// CS116 Lab 5.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include "Course.h"
#include "Student.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<Student> VectorOfStudents;
	VectorOfStudents.resize(1);
	// Create loop to run until user ends
	while (1)
	{
		int choice;
		
		// Display main menu options
		cout << "Main Menu" << endl;
		cout << "1: Register New Student" << endl;
		cout << "2: Returning Students" << endl;
		cout << "3: Quit" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "Enter an option: ";
		cin >> choice;
		cin.ignore();
		while ((!choice) || (choice < 1) || (choice > 3))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid option: ";
			cin >> choice;
			cin.ignore();

		}
		
		
		
		// Add new student
		if (choice == 1)
		{
			string name;
			int idnumber;
			int size = VectorOfStudents.size();
			VectorOfStudents.resize(size + 1);
			idnumber = 1000 + size;
			int index = size - 1;
			// Populate vector with name and id
			VectorOfStudents[index].setID(idnumber);
			VectorOfStudents[index].setName();
			cout << VectorOfStudents[index].getName() << " successfully registered!" << endl;
			cout << "Student ID: " << VectorOfStudents[index].getID() << endl;
			cout << "-------------------------------------------------------" << endl;

		}



		// Returning Student
		else if (choice == 2)
		{
			int id, index;
			bool validID = false;
			// Get student ID
			cout << "Enter ID: ";
			cin >> id;
			cin.ignore();
			// Check if ID matches any student
			for (unsigned int i = 0; i < VectorOfStudents.size(); i++)
			{
				int tempID = VectorOfStudents[i].getID();
				if (id == tempID)
				{
					index = i;
					validID = true;
					cout << "Welcome " << VectorOfStudents[i].getName() << "!" << endl;
				}
				if ((i == VectorOfStudents.size() - 1) && (validID == false))
				{
					cout << "ID not found." << endl;
				}
			}
			cout << "-------------------------------------------------------" << endl;
			
			// Student Menu
			while (validID)
			{
				cout << "Student Menu" << endl;
				cout << "1: Add Class" << endl;
				cout << "2: Calculate GPA" << endl;
				cout << "3: Print Transcript" << endl;
				cout << "4: Quit" << endl;
				cout << "-------------------------------------------------------" << endl;
				cout << "Enter an option: ";
				cin >> choice;
				cin.ignore();
				
				while ((!choice) || (choice < 1) || (choice > 4))
				{
					cout << "Please enter a valid option: ";
					cin >> choice;
					cin.ignore();
				}
				cout << "-------------------------------------------------------" << endl;

				// Add Course
				if (choice == 1)
				{
					VectorOfStudents[index].addCourse();
					cout << "-------------------------------------------------------" << endl;
				}

				// Check GPA
				else if (choice == 2)
				{
					cout << "GPA: " << VectorOfStudents[index].getGPA() << endl;
					cout << "-------------------------------------------------------" << endl;
				}
				// Print Transcript
				else if (choice == 3)
				{
					VectorOfStudents[index].printTranscript();
					cout << "-------------------------------------------------------" << endl;
				}
				// Exit Student Menu
				else
				{
					break;
				}
			}
			
		}
		

		// Quit Main Menu
		else
		{
			break;
		}

	}
	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

