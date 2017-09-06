// CS116InClass2.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Global Variables
const int number = 3;

// Function Prototypes
void StockItems(struct Item array[]);
void showItems(struct Item array[]);
void reportSales(struct Item array[]);
void reportReorders(struct Item array[]);

// Struct for item properties
struct Item
{
	string Description;
	double Price;
	int Stock, Sold;
};

int main()
{
	Item Vending[number];
	StockItems(Vending);
	showItems(Vending);
	reportSales(Vending);
	reportReorders(Vending);
	cout << "Press enter to exit program.";
	cin.ignore();
	cin.ignore();

    return 0;
}

// Admin function which will let allow the user to change item names, prices, and stock. Resets the Sold variable on each item.
void StockItems(struct Item array[])
{
	for (int i = 0; i < number; i++)
	{
		cout << "Enter description for item " << i + 1 << ": ";
		getline(cin, array[i].Description);
		cout << "Enter price for item " << i + 1 << ": ";
		cin >> array[i].Price;
		cout << "Enter stock for item " << i + 1 << ": ";
		cin >> array[i].Stock;
		while (array[i].Stock % 1 != 0)
		{
			cout << "Please enter a valid number: ";
			cin >> array[i].Stock;
		}
		cout << "-----------------------------------------------------" << endl;
		array[i].Sold = 0;
		cin.ignore();
	}
}

void showItems(struct Item array[])
{
	// int which will store the customer's item choice.
	int choice = number + 1;
	// Variables which will store, respectively: item price, remaining balance, any change amount, money put in, and total amount paid.
	double price, balance, change, money, paid;
	// Boolean for whether the item is fully paid
	bool fullyPaid;
	bool run = true;
	
	while (run)
	{
		cout << "Items" << fixed << setw(21) << "Price" << setw(20) << "Stock" << endl;
		// Displays items, prices, and current stock
		for (int i = 0; i < number; i++)
		{
			cout << i + 1 << ": " << array[i].Description << fixed << setw(22 - array[i].Description.length()) << setprecision(2)
				<< array[i].Price << setw(25 - (to_string(array[i].Price).length())) << array[i].Stock << endl;
		}
		cout << "-----------------------------------------------------" << endl;
		cout << "Enter item number or enter 0 to quit: ";
		cin >> choice;
		// Input Validation
		while ((choice < 0) || (choice > number))
		{
			cout << "Please enter a valid number: ";
			cin >> choice;
		}
		// Exits out of the loop if customer is done
		if (choice == 0)
		{
			run = false;
		}
		// Checks whether the selected item is in stock
		while (array[choice - 1].Stock == 0)
		{
			cout << "Item out of stock." << endl;
			cout << "-----------------------------------------------------" << endl;
			cout << "Enter item number or enter 0 to quit: ";
			cin >> choice;
			while ((choice < 0) || (choice > number))
			{
				cout << "Please enter a valid number: ";
				cin >> choice;
			}
			if (choice == 0)
			{
				run = false;
				
			}
		}
		// Displays the price of the selected item and resets the variables used to determine whether the item is paid for
		if (run == true)
		{
			cout << "Price: $" << array[choice - 1].Price << endl;
			price = array[choice - 1].Price;
			change = paid = balance = 0;
			fullyPaid = false;	
		}

		// Asks the user to input money until the item is fully paid for
		while (fullyPaid == false)
		{
			if (paid == 0)
			{
				cout << "Enter money: ";
				cin >> money;
				paid += money;
				balance = price - money;
			}
			else
			{
				cout << "Insufficient funds. Remaining balance: $" << balance << endl;
				cout << "Enter money: ";
				cin >> money;
				balance -= money;
				paid += money;
			}
			if (paid >= price)
			{
				fullyPaid = true;
			}
		}
		// Dispenses items and change (if any) after the item has been fully paid for
		if (fullyPaid == true)
		{
			if (run == true)
			{
				change -= balance;
				cout << "Enjoy!" << endl;
				if (change > 0)
				{
					cout << "Dispensing change: $" << change << endl;
				}
				cout << "-----------------------------------------------------" << endl;
				array[choice - 1].Sold++;
				array[choice - 1].Stock--;
			}
		}
	}
	cout << "-----------------------------------------------------" << endl;

}

// Will print out items, number sold, and remaining stock
void reportSales(struct Item array[])
{
	cout << "Sales Report" << endl;
	cout << "Item" << fixed << setw(21) << "Sold" << setw(21) << "Stock" << endl;
	double sales = 0;
	for (int i = 0; i < number; i++)
	{
		cout << array[i].Description << fixed << setw(25 - array[i].Description.length())
			<< array[i].Sold << setw(25 - (to_string(array[i].Price).length())) << array[i].Stock << endl;
		sales += (array[i].Sold * array[i].Price);
	}
	cout << "Total Sales: $" << sales << endl;
	cout << "-----------------------------------------------------" << endl;
}

// Will print out the number of items needed to restock the machine to capacity
void reportReorders(struct Item array[])
{
	int itemSold;
	cout << "Reorder Report" << endl;
	cout << "The following items need restocking." << endl;
	for (int i = 0; i < number; i++)
	{
		if (array[i].Sold != 0)
		{
			itemSold = array[i].Sold;
			cout << array[i].Description << fixed << setw(25 - array[i].Description.length()) << itemSold << endl;
		}
		
	}
	cout << "-----------------------------------------------------" << endl;

}