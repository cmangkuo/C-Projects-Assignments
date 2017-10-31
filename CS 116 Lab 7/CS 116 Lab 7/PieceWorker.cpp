#include "stdafx.h"
#include "PieceWorker.h"
#include <iostream>
using namespace std;



// Parameterized Constructor
PieceWorker::PieceWorker(string workerName, double payRate, int units)
{
	name = workerName;

	// Set salary and units sold to 0 if input value is negative, otherwise set it to the input value
	if (baseSalary < 0)
	{
		baseSalary = 0;
	}
	else
	{
		baseSalary = payRate;
	}
	if (unitsSold < 0)
	{
		unitsSold = 0;
	}
	else
	{
		unitsSold = units;
	}
}


// Set Functions
void PieceWorker::setUnits()
{
	int units;
	cout << "Enter number of units sold: ";
	cin >> units;
	cin.ignore();
	// Input validation
	while ((!units) || (units < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid number of units: ";
		cin >> units;
		cin.ignore();
	}
	unitsSold = units;
}

void PieceWorker::setData()
{
	// Set all class member values
	setName();
	setBaseSalary();
	setUnits();

}


// Calculation Functions
double PieceWorker::commissionRate()
{
	double commissionRate;

	// Calculate commission rate
	int units = getUnits();
	if (units < 200)
	{
		commissionRate = 0.75;
	}
	else if (units< 1000)
	{
		commissionRate = 1.25;
	}
	else
	{
		commissionRate = 1.75;
	}

	// Return commission per piece
	return commissionRate;

}

double PieceWorker::totalCommissions()
{
	double totalCommissions;
	// Calculate total commissions
	totalCommissions = unitsSold * commissionRate();


	// Return total commissions
	return totalCommissions;
}

double PieceWorker::totalPay()
{
	double totalPay;

	// Calculate total pay
	totalPay = getBaseSalary() + totalCommissions();

	// Return total pay
	return totalPay;

}
