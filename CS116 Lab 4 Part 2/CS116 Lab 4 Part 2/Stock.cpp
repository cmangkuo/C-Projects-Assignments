#include "stdafx.h"
#include "Stock.h"
#include <string>
#include <iostream>
using namespace std;

Stock::Stock()
{
	CompanyName = " ";
	Shares = 0;
	PurchasePrice = 0;
	CurrentPrice = 0;
}


Stock::Stock(string name, int share, double purchase, double current)
{
	while (share < 0)
	{
		cout << "Please enter a valid number of shares: ";
		cin >> share;
		cin.ignore();
	}
	while (purchase < 0)
	{
		cout << "Please enter a valid value for purchase price: $";
		cin >> purchase;
		cin.ignore();
	}
	while (current < 0)
	{
		cout << "Please enter a valid value for current price: $";
		cin >> current;
		cin.ignore();
	}
	CompanyName = name;
	Shares = share;
	PurchasePrice = purchase;
	CurrentPrice = current;
}

void Stock::setCompany()
{
	cout << "Enter company name: ";
	getline(cin, CompanyName);
	
	while (CompanyName.empty())
	{
		cout << "Company name cannot be blank, please re-enter: ";
		getline(cin, CompanyName);
	}
}
void Stock::setShare()
{
	cout << "Enter number of shares: ";
	cin >> Shares;
	while ((!Shares) || (Shares < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid number of shares: ";
		cin >> Shares;
		cin.ignore();

	}
}
void Stock::setPurchase()
{
	cout << "Enter purchase price of shares: ";
	cin >> PurchasePrice;
	while ((!PurchasePrice) || (PurchasePrice < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid purchase price: $";
		cin >> PurchasePrice;
		cin.ignore();

	}
}
void Stock::setCurrent()
{
	cout << "Enter current price of shares: ";
	cin >> CurrentPrice;
	while ((!CurrentPrice) || (CurrentPrice < 0))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		cout << "Please enter a valid purchase price: $";
		cin >> CurrentPrice;
		cin.ignore();

	}
}

void Stock::setData()
{
	setCompany();
	setShare();
	setPurchase();
	setCurrent();
}