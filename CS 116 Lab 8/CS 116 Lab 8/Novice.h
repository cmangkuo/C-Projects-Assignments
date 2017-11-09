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
	Novice();

	// Parameterized Constructor
	Novice(string, string);
	
	// Class Behaviors
	void print();
	int getAttack();
	void updateHP();
	void updateXP();
	void printInfo();
};

