#pragma once
#include <string>
using namespace std;
class Worker
{

public:
	// Default Constructor
	Worker()
	{
		name = "John Doe";
		baseSalary = 0;
	}

	// Parameterized Constructor
	Worker(string, double);

	// Set/Get Functions
	void setName();
	void setBaseSalary();

	string getName()
	{
		return name;
	}
	double getBaseSalary()
	{
		return baseSalary;
	}
protected:
	string name;
	double baseSalary;
};

