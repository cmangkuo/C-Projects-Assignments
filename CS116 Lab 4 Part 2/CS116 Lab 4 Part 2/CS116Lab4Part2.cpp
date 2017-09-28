// CS116Lab4Part2.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include "Stock.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void menu(vector<Stock> a);

int main()
{
	vector<Stock> StockPortfolio;
	menu(StockPortfolio);
	return 0;
}



void menu(vector<Stock> a)
{
	unsigned int choice;
	unsigned int count = 0;
	a.resize(10); // Default size of vector
	bool run = true;
	while (run)
	{
		// Display options
		cout << "Stock Portfolio" << endl;
		cout << "1 - Add Stock" << endl;
		cout << "2 - Show portfolio" << endl;
		cout << "3 - Exit" << endl;
		cout << "Please select an option: ";
		cin >> choice;
		cin.ignore();
		// Input validation
		while ((!choice) || (choice < 1) || (choice > 3))
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
		cout << "------------------------------------------------------------------------------" << endl;
		// Execute functions based on choice
		// Add Stock
		if (choice == 1)
		{
			a.resize(count + 1);
			a[count].setData();
			count++;
			cout << "------------------------------------------------------------------------------" << endl;
		}
		
		// Print Stock Portfolio
		if (choice == 2)
		{
			double totalValue = 0;
			double totalProfits = 0;
			cout << "Company"  << setw(23) << "Value" << setw(30) << "Net Profits/Losses" << endl;
			for (unsigned int i = 0; i < count; i++)
			{
				cout << a[i].getCompany() << fixed << setw(30 - a[i].getCompany().length())  << setprecision(2) << a[i].getValue()
					<< /*setw(30 - to_string(a[i].getValue()).length())*/ setw(25) << setprecision(2) << a[i].getProfit() << endl;
				totalValue += a[i].getValue();
				totalProfits += a[i].getProfit();
			}
			cout << endl << "Total" << setw(17) << "$" << totalValue << setw(37 - to_string(totalValue).length()) << totalProfits << endl;
			cout << "------------------------------------------------------------------------------" << endl;
		}

		// Exit
		if (choice == 3)
		{
			run = false;
		}
	}
	cout << "Press enter to exit." << endl;
	cin.ignore();
}

