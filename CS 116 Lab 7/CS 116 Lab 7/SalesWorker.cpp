#include "stdafx.h"
#include "SalesWorker.h"
#include "Worker.h"
#include <string>
#include <iostream>
using namespace std;


// Default Constructor
SalesWorker::SalesWorker()
{
	name = "John Doe";
	baseSalary = 0;
	numSales = 0;
}

// Parameterized Constructor
SalesWorker::SalesWorker(string workerName, double salary, int monthlysales)
{
	name = workerName;
	// If salary or monthlysales are negative, set them to default values
	if (salary < 0)
	{
		baseSalary = 0;
	}
	else
	{
		baseSalary = salary;
	}
	if (monthlysales < 0)
	{
		numSales = 0;
	}
	else
	{
		numSales = monthlysales;
	}
	

}

// Set Functions
void SalesWorker::setSales()
{
	int sales;
	cout << "Enter number of monthly sales: ";
	cin >> sales;
	cin.ignore();
	
	// Input validation
	while ((!sales) || (sales < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid number of sales: ";
		cin >> sales;
		cin.ignore();
	}
	numSales = sales;
}

void SalesWorker::setData()
{
	// Set all class member values
	setName();
	setBaseSalary();
	setSales();
}

// Calculation Functions
double SalesWorker::commissionRate()
{
	double percentage;
	
	//Calculate commission percentage
	int sales = getSales();
	if (sales > 9999)
	{
		percentage = 20;
	}
	else if (sales > 4999)
	{
		percentage = 18;
	}
	else
	{
		percentage = 15;
	}

	// Return percentage
	return percentage;
}

double SalesWorker::totalCommissions()
{
	double totalCommissions;

	// Calculate total commissions
	totalCommissions = getSales() * commissionRate() / 100;

	// Return total commissions
	return totalCommissions;
}

double SalesWorker::totalPay()
{
	double total;

	// Calculate total pay
	total = getBaseSalary() + totalCommissions();

	// Return total pay
	return total;
}

