#pragma once
#include "Worker.h"
#include <string>
using namespace std;


class PieceWorker: public Worker
{
private:
	int unitsSold;

public:
	// Default Constructor
	PieceWorker()
	{
		name = "John Doe";
		baseSalary = 10;
		unitsSold = 0;
	}

	// Parameterized Constructor
	PieceWorker(string, double, int);
	
	// Set/Get Functions
	void setUnits();
	void setData();
	int getUnits()
	{
		return unitsSold;
	}

	// Calculation Functions
	double commissionRate();
	double totalCommissions();
	double totalPay();
};

