#pragma once
#include "BaseClass.h"
#include <string>
using namespace std;

class Novice: public BaseClass
{
private:
	string MasterName;
public:
	// Default Constructor
	Novice()
	{
		Name = "John Doe";
		Health = 100;
		Experience = 10;
		MasterName = "None";
	}
	// Parameterized Constructor
	Novice(string, int, int, string);
	
};

