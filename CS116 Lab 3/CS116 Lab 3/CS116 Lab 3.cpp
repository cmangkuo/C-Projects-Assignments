// CS116 Lab 3.cpp : Defines the entry point for the console application.
//

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
	int age, height;
	double weight, BMI;
	

public:
	// Set values for class variables
	void setName();
	void setAge();
	void setWeight();
	void setHeight();
	
	// Returns corresponding class variables
	string getName() { return name; }
	int getAge() { return age; }
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
	HealthProfile test;
	test.setName();
	test.setAge();
	test.setHeight();
	test.setWeight();
	test.printProfile();
	cout << "Press enter to exit program." << endl;
	cin.ignore();
	cin.ignore();
    return 0;
}



// Class Functions
void HealthProfile::setName()
{
	cout << "Enter name: ";
	getline(cin, name);
	cout << endl;
}

void HealthProfile::setAge()
{
	cout << "Enter age: ";
	cin >> age;
	cout << endl;
	while ((!age) || (age < 0))
	{
		cout << "Please enter a valid number: ";
		cin >> age;
		cout << endl;
	}
}

void HealthProfile::setHeight()
{
	// Initialize local variables
	int feet, inches = 0;
	// Resets class variable each time the function is called
	height = 0;

	cout << "Enter height in feet: ";
	cin >> feet;
	while (1)
	{
		// Checks for bad input type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid value: ";
			cin >> feet;
		}
		// Checks for bad input value
		if (feet < 0)
		{
			cout << "Please enter a valid value: ";
			cin >> feet;
		}
		// Breaks out of loop if input is valid
		if (!cin.fail())
		{
			break;
		}

		
	}
	

	cout << "Enter height in inches: ";
	cin >> inches;
	while (1)
	{
		// Checks for bad input type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid value: ";
			cin >> inches;
		}
		// Checks for bad input value
		if (inches < 0)
		{
			cout << "Please enter a valid value: ";
			cin >> inches;
		}
		// Breaks out of loop if input is valid
		if (!cin.fail())
		{
			break;
		}


	}

	
	height = feet*12 + inches;

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
	while (1)
	{
		// Checks for bad input type
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid value: ";
			cin >> weight;
		}
		// Checks for bad input value
		if (weight <= 0)
		{
			cout << "Please enter a valid value: ";
			cin >> weight;
		}
		// Breaks out of loop if input is valid
		if (!cin.fail())
		{
			break;
		}


	}

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
	cout << "--------------------------------------------------------" << endl;
	cout << "Name: " << getName() << endl;
	cout << "Age: " << getAge() << endl;
	cout << "Height: " << getHeight() << " in." <<endl;
	cout << "Weight: " << getWeight() << " lbs." << endl;
	cout << "BMI: " << fixed << setprecision(2) << getBMI() << endl;
	cout << "BMI Category: " << getCategory() << endl;
	cout << "Max Heart Rate: " << getMaxHR() << endl;
	cout << "--------------------------------------------------------" << endl;
}

