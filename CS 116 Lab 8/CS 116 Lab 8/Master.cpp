#include "stdafx.h"
#include "Master.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor
Master::Master()
{
	// Set default values
	Name = "John Doe";
	MaxHealth = currentHealth = 100;
	Experience = 10;
	Weapon = "Sword";
	WeaponPower = 10;
	
}

// Parameterized Constructor
Master::Master(string name, string Equipment, int EquipmentPower)
{
	// Set parameterized values
	Name = name;
	MaxHealth = currentHealth = 100;
	Experience = 10;
	Weapon = Equipment;
	WeaponPower = EquipmentPower;
	
}

// Print
void Master::print()
{
	cout << Name << setw(25 - Name.length()) << "Master" << setw(19) << setprecision(0) << MaxHealth << setw(25 - to_string(MaxHealth).length()) << Experience << endl;
}

// Get attack
int Master::getAttack()
{
	int attack;
	// Random number from 0-20, then add  for 5-25, then add weapon stats
	attack = (rand() % 21) + 5 + WeaponPower;
	return attack;
}

// Update HP, only called if battle lost
void Master::updateHP()
{
	// Lose 20% of HP
	double HPLoss = MaxHealth * 0.2;
	currentHealth -= int(HPLoss);
	cout << "Lost " << int(HPLoss) << " HP!" << endl;
	if (currentHealth < 1)
	{
		cout << Name << " has fallen in battle!" << endl;
	}
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;

}

// Update XP, only called if battle won
void Master::updateXP()
{
	// Gain 5 XP
	Experience += 5;
	cout << "Gained 5 experience!" << endl;
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;
}

// Print character info
void Master::printInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Class: Master" << endl;
	cout << "Weapon: " << Weapon << endl;
	cout << "Weapon Power: " << WeaponPower << endl;
	cout << "HP: " << currentHealth << endl;
	cout << "XP: " << Experience << endl;
	
}