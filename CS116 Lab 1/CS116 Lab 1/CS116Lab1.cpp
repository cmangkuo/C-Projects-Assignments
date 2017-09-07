// CS116Lab1.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// global variables
bool run = true;
int choice, index = 0;
const int maxsize = 10;



struct StockInfo
{
	string CompanyName;
	int Shares;
	double PurchasePrice, CurrentPrice, Profit;
};

// Function Prototypes
void Menu(struct StockInfo a[]);
void AddStock(struct StockInfo a[]);
void RemoveStock(struct StockInfo a[]);
void DisplayPortfolio(struct StockInfo a[]);
void DisplayProfits(struct StockInfo a[]);
int Exit();



int main()
{
	// Initializes our array of structures with a number of elements equal to maxsize
	StockInfo Portfolio[maxsize];
	// Starts the Menu command
	Menu(Portfolio);
	// Exits the program
	Exit();
}


// Function which will be the main user interface
void Menu(struct StockInfo a[])
{
	
	
	cout << "Welcome to your stock portfolio. What would you like to do?" << endl;
		
	// Runs this loop until the user selects to exit (currently option 5)
	while (true)
	{
		cout << "1: Add stocks.	2: Remove Stocks	3: Display Current stocks.	4: Display Profits/Losses	5: Exit." << endl;
		cin >> choice;
		cin.ignore();
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
		// Input validation for data type
		while (1)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Error, please enter a valid number. "<< endl;
				cin >> choice;
				cin.ignore();
			}
			if (!cin.fail())
			{
				break;
			}
			
		}

		// Input validation for data value
		while ((choice < 1) || (choice > 5))
		{
			cout << "Please enter a valid option." << endl;
			cin >> choice;
		}
		
		// Actions corresponding to user's choice
		if (choice == 1)
		{
			AddStock(a);
		}
	
		if (choice == 2)
		{
			RemoveStock(a);
		}

		if (choice == 3)
		{
			DisplayPortfolio(a);
		}

		if (choice == 4)
		{
			DisplayProfits(a);
		}

		// Will break out of the loop so the program can exit
		if (choice == 5)
		{
			break;
		}
	
		
	}

}






// Function to add a stock
// Asks for company name, number of shares, purchase price, and current market price
// Saves this input in an array
void AddStock(struct StockInfo a[])
{
	// Checks if we are at maximum capacity for our array of structs
	if (index >= 10)
	{
		cout << "Maximum size reached, unable to add another stock." << endl;
	}
	
	// Asks for user input if we are not at maximum capacity
	else if (index < 10)
	{
		cout << "Enter company name: ";
		getline(cin, a[index].CompanyName);
		cout << endl;
		cout << "Enter number of shares: ";
		cin >> a[index].Shares
			;
		cout << endl;
		cout << "Enter purchase price: ";
		cin >> a[index].PurchasePrice;
		cout << endl;
		cout << "Enter current market price: ";
		cin >> a[index].CurrentPrice;
		cout << endl;
		cout << "Stock successfully added!" << endl;
		index++;
		cout << "Number of Company Stocks: " << index << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
	
	
}

// Removes a stock of the user's choice
void RemoveStock(struct StockInfo a[])
{
	int n = 0;
	string tempName;
	DisplayPortfolio(a);
	cout << "Enter number of stock you wish to remove: ";
	cin >> n;

	// Input validation which ensures that the user inputs the number (which will be used to determine the index) of the stock instead of the name
	while (1)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error, please enter a valid number. " << endl;
			cin >> n;
			cin.ignore();
		}
		if (!cin.fail())
		{
			break;
		}

	}
	while ((n < 1) || (n > index))
	{
		cout << "Please enter a valid number." << endl;
		cin >> n;
	}
	tempName = a[n - 1].CompanyName;
	for (int i = n - 1; i < index; i++)
	{
		a[i].CompanyName = a[i + 1].CompanyName;
		a[i].Shares = a[i + 1].Shares;
		a[i].PurchasePrice = a[i + 1].PurchasePrice;
		a[i].CurrentPrice = a[i + 1].CurrentPrice;
	}
	index--;
	cout << "Successfully removed " << tempName << endl;
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	DisplayPortfolio(a);
}

// Displays all current invested stocks
void DisplayPortfolio(struct StockInfo a[])
{
	
	cout << "   Company" << setw(18) << "Shares" << setw(19) << "Purchase" << setw(17) << "Market" << endl;


	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << ": " << a[i].CompanyName << fixed << setw(25 - a[i].CompanyName.length()) << a[i].Shares << setw(22 - to_string(a[i].Shares).length()) 
			<< setprecision(2) << a[i].PurchasePrice << setw(17) << setprecision(2) << a[i].CurrentPrice << endl;


	}
	cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	
	
}

// Displays the profits/losses from each stock and the net profit/loss
void DisplayProfits(struct StockInfo a[])
{
	int NetProfit = 0;

	cout << fixed << setw(3) << "   Company" << setw(18) << "Profits" << endl;

	// This might look like a lot, but it is mostly just formatting.
	// Prints out company name, number of shares, purchase price and market price
	for (int i = 0; i < index; i++)
	{
		a[i].Profit = a[i].Shares * (a[i].CurrentPrice - a[i].PurchasePrice);
		cout << i << ": " << a[i].CompanyName << fixed << setw(25 - a[i].CompanyName.length()) << a[i].Profit << endl;
		NetProfit += a[i].Profit;

	}

	cout << endl;

	// Checks if profit is positive or negative. Mostly for formatting reasons, prints out a message depending on if there is a profit or a loss
	if (NetProfit >= 0)
	{
		cout << "Net Profit: $" << fixed << setprecision(2) << NetProfit << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
	else
	{
		NetProfit = abs(NetProfit);
		cout << "Net Loss: $" << fixed << setprecision(2) << NetProfit << endl;
		cout << "------------------------------------------------------------------------------------------------------------------------" << endl;
	}
	
}


// Exits the program
int Exit()
{
	cout << "Closing portfolio." << endl;
	cout << "Press enter to close window." << endl;
	cin.ignore();
	return 0;
}
