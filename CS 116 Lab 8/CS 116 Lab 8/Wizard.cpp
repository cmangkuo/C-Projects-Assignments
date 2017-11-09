#include "stdafx.h"
#include "Wizard.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor
Wizard::Wizard()
{
	// Set default values
	Name = "John Doe";
	MaxHealth = currentHealth = 100;
	Experience = 10;
	Weapon = "Wand";
	WeaponPower = 5;
	PowerSource = "Arcane";

}

// Parameterized Constructor
Wizard::Wizard(string name, string Equipment, int EquipmentPower, string PowerType)
{
	// Set parameterized values
	Name = name;
	MaxHealth = currentHealth = 100;
	Experience = 10;
	Weapon = Equipment;
	WeaponPower = EquipmentPower;
	PowerSource = PowerType;
	
}

// Class Behaviours

// Print
void Wizard::print()
{
	cout << Name << setw(25 - Name.length()) << "Wizard" << setw(19) << setprecision(0) << MaxHealth << setw(25 - to_string(MaxHealth).length()) << Experience << endl;
}

// Get attack
int Wizard::getAttack()
{
	int attack;

	// Randomly generate number from 0-15, then add 10 for 10-25, then add weapon stats
	attack = (rand() % 16) + 10 + WeaponPower;
	// Add attack based on power source
	if (PowerSource == "Arcane")
	{
		// Add 2 if arcane
		attack += 2;
	}
	else if (PowerSource == "Divine")
	{
		// Add 5 if divine
		attack += 5;
	}
	return attack;
}

// Update HP, only called when battle lost
void Wizard::updateHP()
{
	// Lose 10% HP
	double HPLoss = MaxHealth * 0.1;
	currentHealth -= int(HPLoss);
	cout << "Lost " << int(HPLoss) << " HP!" << endl;
	if (currentHealth < 1)
	{
		cout << Name << " has fallen in battle!" << endl;
	}
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;
}

// Update XP, only called when battle won
void Wizard::updateXP()
{
	// Add 8 XP
	Experience += 8;
	cout << "Gained 8 experience!" << endl;
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;
}

// Print Character info
void Wizard::printInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Class: Wizard" << endl;
	cout << "Weapon: " << Weapon << endl;
	cout << "Weapon Power: " << WeaponPower << endl;
	cout << "Power Source: " << PowerSource << endl;
	cout << "HP: " << currentHealth << endl;
	cout << "XP: " << Experience << endl;
}