#include "stdafx.h"
#include "Master.h"

// Default Constructor
Master::Master()
{
	Name = "John Doe";
	Health = 100;
	Experience = 10;
	Weapon = "Sword";
	WeaponPower = 10;
}

// Parameterized Constructor
Master::Master(string name, int HP, int XP, string Equipment, int EquipmentPower)
{
	Name = name;
	Health = HP;
	Experience = XP;
	Weapon = Equipment;
	WeaponPower = EquipmentPower;
}
Master::~Master()
{
}
