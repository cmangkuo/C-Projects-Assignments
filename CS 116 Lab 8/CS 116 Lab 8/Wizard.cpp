#include "stdafx.h"
#include "Wizard.h"

// Default Constructor
Wizard::Wizard()
{
	Name = "John Doe";
	Health = 100;
	Experience = 10;
	Weapon = "Wand";
	WeaponPower = 5;
	PowerSource = "Arcane";
}

// Parameterized Constructor
Wizard::Wizard(string name, int HP, int XP, string Equipment, int EquipmentPower, string PowerType)
{
	Name = name;
	Health = HP;
	Experience = XP;
	Weapon = Equipment;
	WeaponPower = EquipmentPower;
	PowerSource = PowerType;
}

Wizard::~Wizard()
{
}
