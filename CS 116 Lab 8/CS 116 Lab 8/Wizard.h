#pragma once
#include "BaseClass.h"
#include <string>
using namespace std;

class Wizard: public BaseClass
{
private:
	string Weapon;
	int WeaponPower;
	string PowerSource;

public:
	// Default Constructor
	Wizard();

	// Parameterized Constructor
	Wizard(string, int, int, string, int, string);
	~Wizard();
};

