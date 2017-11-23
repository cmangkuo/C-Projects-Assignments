// CS116Lab9.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include "SimpleVector.h"
#include "Item.h"
#include <iostream>
#include <string>
using namespace std;


int main()
{
	
	SimpleVector<Item> Inventory(100);
	int choice;
	int numItems = 0;
	// Menu Loop
	while (1)
	{
		cout << "Enter ID to add item or view description" << endl;
		cout << "1 - Display Inventory" << endl;
		cout << "0 - Quit" << endl;

		cout << "Enter choice: ";
		cin >> choice;
		cin.ignore();
		// Input validation
		while (!choice)
		{
			if (choice == 0)
			{
				break;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if (choice < 0)
			{
				cout << "Choice must be positive." << endl;
			}
			cout << "Re-enter choice: ";
			cin >> choice;
			cin.ignore();
		}
		cout << "-------------------------------------------------------" << endl;
		// Chose 1
		if (choice == 1)
		{
			for (int i = 0; i < numItems; i++)
			{
				cout << Inventory.getItemAt(i);
			}
			cout << "-------------------------------------------------------" << endl;
		}

		// Chose 0
		else if (choice == 0)
		{
			cout << "Goodbye!" << endl;
			break;
		}
		
		// Chose a SKU
		else
		{
			// Add item if SKU doesn't already exist
			if (Inventory.search(choice) == -1)
			{
				string desc;
				int quant;
				cout << "Enter description: ";
				getline(cin, desc);
				cout << "Enter quantity: ";
				cin >> quant;
				cin.ignore();
				// Input validation
				while (!quant)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					if (quant < 1)
					{
						cout << "Quantity must be positive." << endl;
					}
					cout << "Re-enter quantity: ";
					cin >> quant;
					cin.ignore();
				}
				Inventory.insert(Item(choice, desc, quant));
				numItems++;
			}
			// Print item info if it does
			else
			{
				int index = Inventory.search(choice);
				cout << Inventory.getItemAt(index);

				// Ask if user wants to modify
				int modify;
				cout << "Update stock? (1- Yes/ 2- No): ";
				cin >> modify;
				cin.ignore();

				// Input validation
				while ((!modify) || (modify < 1) || (modify > 2))
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');

					}
					cout << "Please enter a valid option (1 - Yes/ 2 - No): ";
					cin >> modify;
					cin.ignore();
				}

				// Update stock if user wants to
				if (modify == 1)
				{
					int change;
					cout << "Enter amount to adjust: ";
					cin >> change;
					cin.ignore();
					
					// Input validation
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), 'n');
						cout << "Please enter a valid amount: ";
						cin >> change;
						cin.ignore();
					}
					Inventory.getItemAt(index).updateInventory(change);
				}
				
			}

			cout << "-------------------------------------------------------" << endl;
			

		}

		
	}
	cout << "-------------------------------------------------------" << endl;
	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

