#pragma once
#include <string>
#include "BaseClass.h"
using namespace std;

class Master: public BaseClass
{
private: 
	string Weapon;
	int WeaponPower;
public:
	// Default Constructor
	Master();
	// Parameterized Constructor
	Master(string, int, int, string, int);
	~Master();
};

