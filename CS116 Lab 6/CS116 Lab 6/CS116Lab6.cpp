// CS116Lab6.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include "Fraction.h"
#include <iostream>
using namespace std;

int main()
{
	cout << "Fraction Calculator" << endl;
	cout << "===================================================" << endl;
	// Menu loop
	while (1)
	{
		Fraction one;
		Fraction two;
		Fraction three;
		int choice;
		cout << "1 - Addition" << endl;
		cout << "2 - Subtraction" << endl;
		cout << "3 - Multiplication" << endl;
		cout << "4 - Division" << endl;
		cout << "5 - Compare" << endl;
		cout << "6 - Exit" << endl;
		cout << "Enter option: ";
		cin >> choice;
		cin.ignore();
		while ((!choice) || (choice < 1) || (choice > 6))
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
		cout << "===================================================" << endl;

		// Addition
		if (choice == 1)
		{
			cout << "Addition" << endl;
			cout << "1 - ";
			cin >> one;
			cout << "2 - ";
			cin >> two;
			three = one + two;
			cout << "Result: " << three << endl;
			cout << "===================================================" << endl;
		}

		// Subtraction
		if (choice == 2)
		{
			cout << "Subtraction (Fraction 1 - Fraction 2)" << endl;
			cout << "1 - ";
			cin >> one;
			cout << "2 - ";
			cin >> two;
			three = one - two;
			cout << "Result: " << three << endl;
			cout << "===================================================" << endl;
		}

		// Multiplication
		if (choice == 3)
		{
			cout << "Muliplication" << endl;
			cout << "1 - ";
			cin >> one;
			cout << "2 - ";
			cin >> two;
			three = one * two;
			cout << "Result: " << three << endl;
			cout << "===================================================" << endl;
		}

		// Division
		if (choice == 4)
		{
			cout << "Division (Fraction 1 / Fraction 2)" << endl;
			cout << "1 - ";
			cin >> one;
			cout << "2 - ";
			cin >> two;
			three = one / two;
			cout << "Result: " << three << endl;
			cout << "===================================================" << endl;
		}
		// Comparison
		if (choice == 5)
		{
			cout << "Comparison" << endl;
			cout << "1 - ";
			cin >> one;
			cout << "2 - ";
			cin >> two;
			if (one == two)
			{
				cout << "The fractions are equal" << endl;
			}
			else if (one > two)
			{
				cout << one << " is greater than " << two << endl;
			}
			else
			{
				cout << one << " is less than " << two << endl;
			}
			cout << "===================================================" << endl;
		}
		// Exit
		if (choice == 6)
		{
			break;
		}

	}
	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

