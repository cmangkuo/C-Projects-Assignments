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
void DisplayPortfolio(struct StockInfo a[]);
void DisplayProfits(struct StockInfo a[]);
int Exit();



int main()
{
	StockInfo Portfolio[maxsize];
	Menu(Portfolio);
	
	
    
}


// Function which will be the user interface
void Menu(struct StockInfo a[])
{
	
	
	cout << "Welcome to your stock portfolio. What would you like to do?" << endl;
		
	
	
	cout << "1: Add stocks.	2: Display Current stocks.	3: Display Profits/Losses	4: Exit." << endl;
	cin >> choice;
	cin.ignore();
	cout << "-----------------------------------------------------------------" << endl;
	while ((choice < 1) || (choice > 4))
	{
		cout << "Please enter a valid option." << endl;
		cin >> choice;
	}
	
	if (choice == 1)
	{
		AddStock(a);
	}

	if (choice == 2)
	{
		DisplayPortfolio(a);
	}

	if (choice == 3)
	{
		DisplayProfits(a);
	}

	if (choice == 4)
	{
		Exit();	
	}
	
		



}







void AddStock(struct StockInfo a[])
{
	if (index >= 10)
	{
		cout << "Maximum size reached, unable to add another stock." << endl;
	}
	
	else if (index < 10)
	{
		cout << "Enter company name: ";
		
		getline(cin, a[index].CompanyName);
		cout << endl;
		cout << "Enter number of shares: ";
		cin >> a[index].Shares;
		cout << endl;
		cout << "Enter purchase price: ";
		cin >> a[index].PurchasePrice;
		cout << endl;
		cout << "Enter current market price: ";
		cin >> a[index].CurrentPrice;
		cout << endl;
		cout << "Stock successfully added!" << endl;
		index++;
		cout << "Index: " << index << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	Menu(a);
	
	
}


void DisplayPortfolio(struct StockInfo a[])
{
	
	cout << "   Company" << setw(18) << "Shares" << setw(19) << "Purchase" << setw(17) << "Market" << endl;


	for (int i = 0; i < index; i++)
	{
		cout << i + 1 << ": " << a[i].CompanyName << fixed << setw(25 - a[i].CompanyName.length()) << a[i].Shares << setw(22 - to_string(a[i].Shares).length()) 
			<< setprecision(2) << a[i].PurchasePrice << setw(17) << setprecision(2) << a[i].CurrentPrice << endl;


	}
	cout << "-----------------------------------------------------------------" << endl;
	Menu(a);
	
}

void DisplayProfits(struct StockInfo a[])
{
	int NetProfit = 0;

	cout << fixed << setw(3) << "   Company" << setw(18) << "Profits" << endl;

	for (int i = 0; i < index; i++)
	{
		a[i].Profit = a[i].Shares * (a[i].CurrentPrice - a[i].PurchasePrice);
		cout << i << ": " << a[i].CompanyName << fixed << setw(25 - a[i].CompanyName.length()) << a[i].Profit << endl;
		NetProfit += a[i].Profit;

	}

	cout << endl;
	if (NetProfit >= 0)
	{
		cout << "Net:  $" << fixed << setprecision(2) << NetProfit << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	
	else
	{
		NetProfit = abs(NetProfit);
		cout << "Net: -$" << fixed << setprecision(2) << NetProfit << endl;
		cout << "-----------------------------------------------------------------" << endl;
	}
	Menu(a);
}



int Exit()
{
	return 0;
}
