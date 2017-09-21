// CS116 Lab 3.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Class Definitions
class HealthProfile
{
private:
	string name, BMIcategory;
	double age, height, weight, BMI;
	
	

public:
	// Set values for class variables
	void setName();
	void setAge();
	void setWeight();
	void setHeight();
	
	// Returns corresponding class variables
	string getName() { return name; }
	double getAge() { return age; }
	double getWeight() { return weight; }
	double getHeight() { return height; }
	int getMaxHR() { return 220 - age; }
	
	// Accesses class variables in order to calculate these attributes
	double getBMI();
	string getCategory();
	
	// Prints out the health data
	void printProfile();

};



int main()
{
	int choice;
	HealthProfile test;
	while (1)
	{
		test.setName();
		test.setAge();
		test.setHeight();
		test.setWeight();
		test.printProfile();
		cout << "Enter another? 1-Yes 2-No" << endl;
		cin >> choice;
		while ((!choice) || ((choice < 1) || (choice > 2)))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid value: ";
			cin >> choice;
		}
		cin.ignore();
		cout << "--------------------------------------------------------" << endl;
		if (choice == 2)
		{
			break;
		}
	}
	


	cout << "Press enter to exit program." << endl;
	cin.ignore();
    return 0;
}



// Class Functions
void HealthProfile::setName()
{
	cout << "Enter name: ";
	getline(cin, name);
	cout << "--------------------------------------------------------" << endl;
}

void HealthProfile::setAge()
{
	cout << "Enter age: ";
	cin >> age;
	cin.ignore();
	while ((!age) || (age < 0))
	{
		if (age == 0)
		{
			break;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid number: ";
		cin >> age;
		cin.ignore();
	}
	cout << "--------------------------------------------------------" << endl;
}

void HealthProfile::setHeight()
{
	// Initialize local variables
	double feet, inches = 0;
	// Resets class variable each time the function is called
	height = 0;

	cout << "Enter height in feet: ";
	cin >> feet;
	cin.ignore();
	while ((!feet) || (feet < 0))
	{
		if (feet == 0)
		{
			break;
		}
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid value: ";
		cin >> feet;
		cin.ignore();
	}
	

	cout << "Enter height in inches: ";
	cin >> inches;
	cin.ignore();
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid value: ";
			cin >> inches;
		}
		if (inches < 0)
		{
			cout << "Please enter a valid value: ";
			cin >> inches;
		}
		if (!cin.fail())
		{
			break;
		}
		
	}

	
	height = feet*12 + inches;
	cout << "--------------------------------------------------------" << endl;

	// Resets function if total height is negative or zero
	if (height <= 0)
	{
		cout << "Total height is an invalid value, please re-enter." << endl;
		setHeight();
	}


}

void HealthProfile::setWeight()
{
	cout << "Enter weight in pounds: ";
	cin >> weight;
	while ((!weight) || (weight < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid value: ";
		cin >> weight;
		cin.ignore();
	}
	cout << "--------------------------------------------------------" << endl;
}

double HealthProfile::getBMI()
{
	BMI = 703 * weight / pow(height, 2);
	return BMI;
}
// Returns a string which is the BMI category determined by the BMI value
string HealthProfile::getCategory()
{
	if (BMI > 30)
	{
		BMIcategory = "Obese";
	}
	else if (BMI > 25)
	{
		BMIcategory = "Overweight";
	}
	else if (BMI > 18.5)
	{
		BMIcategory = "Normal";
	}
	else
	{
		BMIcategory = "Underweight";
	}
	return BMIcategory;
}

void HealthProfile::printProfile()
{
	
	cout << "Name: " << getName() << endl;
	cout << "Age: " << fixed << setprecision(1) << getAge() << endl;
	cout << "Height: " << fixed << setprecision(2) << getHeight() << " in." <<endl;
	cout << "Weight: " << fixed << setprecision(2) << getWeight() << " lbs." << endl;
	cout << "BMI: " << fixed << setprecision(2) << getBMI() << endl;
	cout << "BMI Category: " << getCategory() << endl;
	cout << "Max Heart Rate: " << fixed << setprecision(1) << getMaxHR() << endl;
	cout << "--------------------------------------------------------" << endl;
}

