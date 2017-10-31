#pragma once
#include "Worker.h"
#include <string>
using namespace std;

class SalesWorker: public Worker
{
public:
	int numSales;
	// Default Constructor
	SalesWorker();

	// Parameterized Constructor
	SalesWorker(string, double, int);

	// Set/Get Functions
	void setSales();
	void setData();
	int getSales()
	{
		return numSales;
	}

	// Calculation Functions
	double commissionRate();
	double totalCommissions();
	double totalPay();
};

