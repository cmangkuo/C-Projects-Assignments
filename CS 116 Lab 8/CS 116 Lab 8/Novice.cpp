#include "stdafx.h"
#include "Novice.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Default Constructor
Novice::Novice()
{
	// Set default values
	Name = "John Doe";
	MaxHealth = currentHealth = 100;
	Experience = 10;
	MasterName = "None";
	
}

// Parameterized Constructor
Novice::Novice(string name, string Master)
{
	// Set parameterized values
	Name = name;
	MaxHealth = currentHealth = 100;
	Experience = 10;
	MasterName = Master;

}

// Print
void Novice::print()
{
	cout << Name << setw(25-Name.length()) << "Novice" << setw(19) << setprecision(0) << MaxHealth << setw(25-to_string(MaxHealth).length()) << Experience << endl;
}

// Get attack
int Novice::getAttack()
{
	int attack;

	// Generate random number from 0-19, add 1 to finalize to 1-20
	attack = rand() % 20 + 1;
	return attack;
}

// Update HP, will only be called if battle is lost
void Novice::updateHP()
{
	// Lose 30% HP
	double HPLoss = MaxHealth * 0.3;
	currentHealth -= int(HPLoss);
	cout << "Lost " << int(HPLoss) << " HP!" << endl;
	if (currentHealth < 1)
	{
		cout << Name << " has fallen in battle!" << endl;
	}
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;
}

// Update XP, will only be called if battle is won
void Novice::updateXP()
{
	// Gain 2 XP
	Experience += 2;
	cout << "Gained 2 experience!" << endl;
	cout << "HP: " << currentHealth << setw(10) << "XP: " << Experience << endl;
}

// Print character info
void Novice::printInfo()
{
	cout << "Name: " << Name << endl;
	cout << "Class: Novice" << endl;
	cout << "Master: " << MasterName << endl;
	cout << "HP: " << currentHealth << endl;
	cout << "XP: " << Experience << endl;
}

