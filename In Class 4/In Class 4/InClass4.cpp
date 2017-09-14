// InClass4.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;


// Class Definition
class Rectangle
{
	double length, width;
public:
	void setLength();
	void setWidth();
	double getLength() { return length; }
	double getWidth() { return width; }
	double getArea() { return length*width; }
	double getPerimeter() {return ((2 * length) + (2 * width)); }
};

// Function Prototypes
void Menu(Rectangle &a);


int main()
{
	Rectangle test;
	Menu(test);
	cout << "Exiting application, press enter to terminate." << endl;
	cin.ignore();
    return 0;
}




// Class Functions
// Set the length of rectangle
void Rectangle::setLength()
{
	cout << "Enter length: ";
	cin >> length;
	cin.ignore();

	// Input validation
	while (length <= 0)
	{
		cout << "Please enter a valid value: ";
		cin >> length;
		cin.ignore();
	}
}

// Set the width of rectangle
void Rectangle::setWidth()
{
	cout << "Enter width: ";
	cin >> width;
	cin.ignore();

	// Input validation
	while (width <= 0)
	{
		cout << "Please enter a valid value: ";
		cin >> width;
		cin.ignore();
	}
}


// Other Functions
/*	Accepts an object of Rectangle class as an agrument
	Calculates the cost of flooring/fencing material based on the rectangles attributes
*/	
void Menu(Rectangle &a)
{
	int choice;
	double costpersqft, costperft, totalcost;
	double Area, Perimeter;
	// Loops until the user decides to exit
	while (1)
	{
		
		cout << "1: Floor Pricing" << endl;
		cout << "2: Fence Pricing" << endl;
		cout << "3: Exit" << endl;
		cout << "Enter command: ";
		cin >> choice;
		cin.ignore();

		// Input validation
		while ((choice < 1) || (choice > 3))
		{
			cout << "Please enter a valid command: ";
			cin >> choice;
			cin.ignore();
		}

		cout << "-----------------------------------------------------------------" << endl;

		// Switch will take varying actions based on the user's choice
		switch (choice)
		{
		/*	Case 1: Flooring
			Get user input for length/width, and price of flooring per sq. ft
			Use this data to calculate area and total price of materials
		*/
		case 1:
			// Get rectangle attributes and material price
			a.setLength();
			a.setWidth();
			cout << "Enter material cost per sq. ft: $";
			cin >> costpersqft;
			cin.ignore();

			// Input validation
			while (costpersqft <= 0)
			{
				cout << "Please enter a valid value: $";
				cin >> costpersqft;
				cin.ignore();
			}

			// Calculate area and total material cost, then prints it out for user to see
			Area = a.getArea();
			totalcost = Area * costpersqft;
			cout << "Amount of flooring material to buy: " << fixed << setprecision(2) << Area << " sq. ft" << endl;
			cout << "Total Cost: $" << fixed << setprecision(2) << totalcost << endl;
			break;

		/*	Case 2: Fencing
			Get user input for length/width, and price of fencing per ft
			Use this data to calculate perimeter and total price of materials
		*/
		case 2:
			// Get rectangle attributes and material price
			a.setLength();
			a.setWidth();
			cout << "Enter material cost per ft: $";
			cin >> costperft;
			cin.ignore();

			// Input validation
			while (costperft <= 0)
			{
				cout << "Please enter a valid value: $";
				cin >> costperft;
				cin.ignore();
			}

			// Calculate perimeter and total material cost, then prints it out for user to see
			Perimeter = a.getPerimeter();
			totalcost = Perimeter * costperft;
			cout << "Amount of fencing material to buy: " << fixed << setprecision(2) << Perimeter << " ft" << endl;
			cout << "Total Cost: $" << fixed << setprecision(2) << totalcost << endl;
			break;

		/*	Case 3: Exit
			Breaks out of the switch without taking any actions
		*/
		case 3:
			break;
		}
		// Breaks out of the while loop if user chooses to exit
		if (choice == 3)
		{
			break;
		}
		// Outputs some formatting otherwise
		else
		{
			cout << "-----------------------------------------------------------------" << endl;
		}

	}
}
	
