// CS116Lab8.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include "BaseClass.h"
#include "Novice.h"
#include "Master.h"
#include "Wizard.h"
using namespace std;

int main()
{
	// Set random seed
	srand(time(NULL));

	// Storage variable for number of characters
	int CharacterCount = 0;
	int maxChars = 20;

	// Create array of pointers with 20 max characters
	BaseClass ** characterlist = new BaseClass*[maxChars];
	
	// Create menu loop
	while (1)
	{
		
		int choice;
		cout << "Menu" << endl;
		cout << "1 - Create Character" << endl;
		cout << "2 - Check Stats" << endl;
		cout << "3 - Fight" << endl;
		cout << "4 - Lookup a Character" << endl;
		cout << "5 - Quit" << endl;
		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		// Input validation
		while ((cin.fail()) || (choice < 1) || (choice > 5))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Please enter a valid option: ";
			cin >> choice;
			cin.ignore();

		}
		cout << "==================================================" << endl;


		// Create Character
		if (choice == 1)
		{
			// Check if character count has reached max
			if (CharacterCount == maxChars)
			{
				cout << "Maximum number of characters has been reached! Cannot create a new character." << endl;
			}
			else
			{
				int choice2;

				// Ask what type of character to create
				cout << "1 - Novice" << endl;
				cout << "2 - Master" << endl;
				cout << "3 - Wizard" << endl;
				cout << "Choose character type: ";
				cin >> choice2;
				cin.ignore();

				// Input validation
				while ((cin.fail()) || (choice2 < 1) || (choice2 > 3))
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits <streamsize>::max(), '\n');
					}
					cout << "Please enter a valid number: ";
					cin >> choice2;
					cin.ignore();
				}

				// Create Novice
				if (choice2 == 1)
				{
					string charname, mastername;
					// Get character name
					cout << "Enter character name: ";
					getline(cin, charname);

					// Get master name
					cout << "Enter master name: ";
					getline(cin, mastername);
					
					// Create new instance of novice
					characterlist[CharacterCount] = new Novice(charname, mastername);
					cout << charname << " successfully created!" << endl;

					// Add 1 to character count
					CharacterCount++;
				}

				// Create Master
				else if (choice2 == 2)
				{
					string charname, weapon;
					int weaponpower;

					// Get character name
					cout << "Enter character name: ";
					getline(cin, charname);

					// Get weapon type
					int choice3;
					cout << "1 - Sword" << endl; // Weapon Power = 10
					cout << "2 - Axe" << endl; // Weapon Power = 13
					cout << "3 - Spear" << endl; // Weapon Power = 12
					cout << "Choose your weapon: ";
					cin >> choice3;
					cin.ignore();

					// Input validation
					while ((cin.fail()) || (choice3 < 1) || (choice3 > 3))
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						cout << "Please enter a valid option: ";
						cin >> choice3;
						cin.ignore();

					}

					switch (choice3)
					{
						// Chose Sword
						case 1:
							weapon = "Sword";
							weaponpower = 10;
							break;

						// Chose Axe
						case 2:
							weapon = "Axe";
							weaponpower = 13;
							break;

						// Chose Spear
						case 3:
							weapon = "Spear";
							weaponpower = 12;
							break;
					}
				
					

					// Create new instance of master
					characterlist[CharacterCount] = new Master(charname, weapon, weaponpower);
					cout << charname << " successfully created!" << endl;

					// Add 1 to character count
					CharacterCount++;
				}

				// Create Wizard
				else if (choice2 == 3)
				{
					string charname, weapon, powertype;
					int weaponpower;

					// Get character name
					cout << "Enter character name: ";
					getline(cin, charname);

					// Get weapon type
					int choice4;
					cout << "1 - Staff" << endl; // Weapon Power = 10
					cout << "2 - Wand" << endl; // Weapon Power = 5
					cout << "3 - Book" << endl; // Weapon Power = 8
					cout << "Choose your weapon: ";
					cin >> choice4;
					cin.ignore();

					// Input validation
					while ((cin.fail()) || (choice4 < 1) || (choice4 > 3))
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						cout << "Please enter a valid option: ";
						cin >> choice4;
						cin.ignore();

					}
					switch (choice4)
					{
						// Chose Staff
						case 1:
							weapon = "Staff";
							weaponpower = 10;
							break;

						// Chose Wand
						case 2:
							weapon = "Wand";
							weaponpower = 5;
							break;

						// Chose Book
						case 3:
							weapon = "Book";
							weaponpower = 8;
							break;
					}
					// Get Power source
					int choice5;
					cout << "1- Arcane" << endl;
					cout << "2- Divine" << endl;
					cout << "Enter wizard's power source: ";
					cin >> choice5;
					cin.ignore();

					// Input validation
					while ((cin.fail()) || (choice5 < 1) || (choice5 > 2))
					{
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
						}
						cout << "Please enter a valid option: ";
						cin >> choice5;
						cin.ignore();
					}

					// Chose Arcane
					if (choice5 == 1)
					{
						powertype = "Arcane";
					}

					// Chose Divine
					else if (choice5 == 2)
					{
						powertype = "Divine";
					}

					// Create new instance of wizard
					characterlist[CharacterCount] = new Wizard(charname, weapon, weaponpower, powertype);
					cout << charname << " successfully created!" << endl;

					// Add 1 to character count
					CharacterCount++;
				}
			}
			cout << "==================================================" << endl;
		}
		// Print stats
		else if (choice == 2)
		{
			cout << "    " << "Name" << setw(20) << "Class" << setw(19) << "HP" << setw(16) << "XP" << endl;
			for (int i = 0; i < CharacterCount; i++)
			{
				cout << i + 1 << " - ";
				characterlist[i]->print();
			}
			cout << "==================================================" << endl;
		}
		// Initiate a Fight
		else if (choice == 3)
		{
			bool loop = true;
			bool characterAlive;
			// Loop until user stops battling
			while (loop)
			{
				// Ask which character will fight
				int choice6;
				for (int i = 0; i < CharacterCount; i++)
				{
					cout << i + 1 << " - " << characterlist[i]->getName() << endl;
				}

				cout << "Choose character: ";
				cin >> choice6;
				cin.ignore();

				// Input validation
				while ((cin.fail()) || (choice6 < 1) || (choice6 > CharacterCount))
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}

					cout << "Please enter a valid number: ";
					cin >> choice6;
					cin.ignore();
				}
				
				int index = choice6 - 1;
				bool victory;
				int attack;

				// Check if character has HP
				if (characterlist[index]->getHealth() < 1)
				{
					cout << "Character has no HP, cannot battle!" << endl;
					characterAlive = false;
				}
				else
				{
					characterAlive = true;
				}


				if (characterAlive)
				{
					
					// Roll a 3-sided die
					int diceroll;
					diceroll = rand() % 3 + 1;

					string enemyname;
					int enemyHP;

					// Generate enemy based on dice roll
					switch (diceroll)
					{
					case 1:
						enemyname = "Troglodyte";
						enemyHP = 12;
						break;
					case 2:
						enemyname = "Orc Warrior";
						enemyHP = 15;
						break;
					case 3:
						enemyname = "Black Dragon";
						enemyHP = 20;
						break;

					}
					// Get Attack
					attack = characterlist[index]->getAttack();
					cout << characterlist[index]->getName() << " encountered a " << enemyname << "!" << endl;
					cout << characterlist[index]->getName() << " attacks for " << attack << " points!" << endl;
					if (attack >= enemyHP)
					{
						victory = true;
					}
					else
					{
						victory = false;
					}

					// Update XP if battle won
					if (victory)
					{
						cout << characterlist[index]->getName() << " won the battle!" << endl;
						characterlist[index]->updateXP();
					}
					// Update HP if battle lost
					else
					{
						cout << characterlist[index]->getName() << " lost the battle!" << endl;
						characterlist[index]->updateHP();
					}
				}

				// Ask if user wants to battle again
				int choice7;
				cout << "1 - Yes" << endl;
				cout << "2 - No" << endl;
				cout << "Battle again? ";
				cin >> choice7;
				cin.ignore();

				// Input validation
				while ((cin.fail()) || (choice7 < 1) || (choice7 > 2))
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					cout << "Please enter a valid number: ";
					cin >> choice7;
					cin.ignore();
				}

				switch (choice7)
				{
				case 1:
					break;
				case 2:
					loop = false;
					break;
				}
			cout << "==================================================" << endl;
			}
		}
		// Character Lookup
		else if (choice == 4)
		{
			bool characterExists = false;
			string name;
			cout << "Enter character name: ";
			getline(cin, name);
			int index;
			for (int i = 0; i < CharacterCount; i++)
			{
				if (characterlist[i]->getName() == name)
				{
					index = i;
					characterExists = true;
				}
			}

			if (characterExists)
			{
				characterlist[index]->printInfo();
			}
			else
			{
				cout << "Character not found!" << endl;
			}
			cout << "==================================================" << endl;
		}
		// Quit
		else if (choice == 5)
		{
			// Delete array 
			delete[] characterlist;
			// Break out of loop
			break;
		}
	}
	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

