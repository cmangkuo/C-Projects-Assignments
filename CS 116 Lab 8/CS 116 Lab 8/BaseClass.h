#pragma once
#include <string>
using namespace std;


class BaseClass
{
public:
	BaseClass();
	virtual void print() = 0;
	virtual int getAttack() = 0;
	virtual void updateHP() = 0;
	virtual void updateXP() = 0;
protected:
	string Name;
	int Health;
	int Experience;
};

