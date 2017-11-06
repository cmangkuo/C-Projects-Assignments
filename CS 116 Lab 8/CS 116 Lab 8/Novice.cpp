#include "stdafx.h"
#include "Novice.h"


Novice::Novice(string name, int HP, int XP, string Master)
{
	Name = name;
	Health = HP;
	Experience = XP;
	MasterName = Master;
}


Novice::~Novice()
{
}
