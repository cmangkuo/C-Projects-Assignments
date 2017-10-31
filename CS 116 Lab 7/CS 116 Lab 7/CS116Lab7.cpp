// CS116Lab7.cpp : Defines the entry point for the console application.
// Author: Chris Mangkuorahardjo

#include "stdafx.h"
#include "PieceWorker.h"
#include "SalesWorker.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Create class objects
	PieceWorker Worker;
	SalesWorker Salesrep;

	// Menu Loop
	while (1)
	{
		int choice;

		// Menu Options
		cout << "Main Menu" << endl;
		cout << "1 - PieceWorker" << endl;
		cout << "2 - Salesrep" << endl;
		cout << "3 - Exit" << endl;
		cout << "Enter option: ";
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
		cout << "============================================" << endl;

		// PieceWorker option
		if (choice == 1)
		{
			// Set Worker data
			Worker.setData();
			cout << endl;

			// Output payroll data
			cout << "Payroll for " << Worker.getName() << endl;
			cout << "Commission is $" << setfill('0') << setw(3) << Worker.commissionRate() << " per piece." << endl;
			cout << "Pieces sold: " << Worker.getUnits() << endl;
			cout << endl;
			cout << "Total Commissions: $" << fixed <<setprecision(2) << Worker.totalCommissions() << endl;
			cout << "Base Salary: $" << fixed << setprecision(2) << Worker.getBaseSalary() << endl;
			cout << "Total Pay: $" << fixed << setprecision(2) << Worker.totalPay() << endl;
			cout << "============================================" << endl;
		}

		// SalesWorker option
		else if (choice == 2)
		{
			// Set Worker data
			Salesrep.setData();
			cout << endl;

			// Output payroll data
			cout << "Payroll for " << Salesrep.getName() << endl;
			cout << "Commission is " << Salesrep.commissionRate() << "% of sales." << endl;
			cout << "Number of sales: " << Salesrep.getSales() << endl;
			cout << endl;
			cout << "Total Commissions: $" << fixed << setprecision(2) << Salesrep.totalCommissions() << endl;
			cout << "Base Salary: $" << fixed << setprecision(2) << Salesrep.getBaseSalary() << endl;
			cout << "Total Pay: $" << fixed << setprecision(2) << Salesrep.totalPay() << endl;
			cout << "============================================" << endl;
		}
		
		// Exit
		else
		{
			// Exit loop
			break;
		}

	}


	// Exit Program
	cout << "Press enter to exit." << endl;
	cin.ignore();
    return 0;
}

