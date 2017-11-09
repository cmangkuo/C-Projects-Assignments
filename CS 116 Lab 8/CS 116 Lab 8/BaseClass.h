#pragma once
#include <string>
using namespace std;


class BaseClass
{
public:
	BaseClass();
	string getName() {return Name;}
	double getHealth() {return currentHealth;}
	virtual void print() = 0;
	virtual int getAttack() = 0;
	virtual void updateHP() = 0;
	virtual void updateXP() = 0;
	virtual void printInfo() = 0;

protected:
	string Name;
	double MaxHealth, currentHealth;
	int Experience;
};

