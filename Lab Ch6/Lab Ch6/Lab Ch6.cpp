// Lab Ch6.cpp : Defines the entry point for the console application.

/**
* Chapter 6, Programming Challenge 14: Order Status,
* Gaddis' text: pages 370-371
*/

// Author: Chris Mangkuorahardjo

#include <iostream>
#include <iomanip>
using namespace std;

// Function prototypes
void getStockInfo(int &, int &, double &);
void displayStatus(int, int, double = 10.00);

int main()
{
	int ordered; // To hold the spools ordered
	int inStock; // To hold the spools in stock
	double specialShipping; // To hold any special shipping charges

							// TODO: Call function getStockInfo - Get the order and stock information.
	getStockInfo(ordered, inStock, specialShipping);
	// TODO: Call function displayStatus
	displayStatus(ordered, inStock, specialShipping);
	// Determine whether there are special charges and display the order status.
	system("pause");
	return 0;

}

//*********************************************************
// The getStockInfo function asks the user for the number *
// of spools ordered, the number of spools in stock, and *
// any special shipping charges. The values are validated *
// and stored in reference parameters. *
//*********************************************************

void getStockInfo(int &ordered, int &inStock, double &specialShipping)
{
	char choice; // To hold 'y' or 'n'

				 // TODO: Get the number of spools ordered.
	cout << "Input number of spools ordered." << endl;
	cin >> ordered;
	// TODO: Validate the number of spools ordered.
	while (ordered < 1)
	{
		cout << "Please enter a valid amount." << endl;
		cin >> ordered;
	}

	// TODO: Get the number of spools in stock.
	cout << "Input number of spools in stock." << endl;
	cin >> inStock;

	// TODO: Validate the number of spools in stock.
	while (inStock < 0)
	{
		cout << "Please enter a valid amount." << endl;
		cin >> inStock;
	}

	// Get the special shipping charges, if any.
	cout << "Are special shipping charges required? (y or n): ";
	cin >> choice;

	if (choice == 'Y' || choice == 'y')
	{
		cout << "Enter the amount of any special shipping charges per spool: " << endl;
		cin >> specialShipping;

		// Validate the special shipping charges.
		while (specialShipping < 0)
		{
			cout << "Special shipping charges "
				<< "must be zero or more. "
				<< "Enter the amount of any special "
				<< "shipping charges per spool: " << endl;
			cin >> specialShipping;
		}
	}
	else
		specialShipping = 0;
}

//*********************************************************
// The displayStatus function accepts as arguments the *
// number of spools ordered, the number in stock, and the *
// shipping charges per spool. *
//*********************************************************

void displayStatus(int ordered, int inStock, double specialShipping)
{
	const double UNIT_SPOOL_COST = 100.00;

	int available = ordered; // Number of spools available to ship
	int backOrder = 0; // Number of spools back ordered

	double spoolCost; // Charges for spools shipping now
	double shipCharges; // Shipping charges for this shipment
	double totalCharges; // Cost of shipped spools + shipping chgs

						 // Determine whether any spools are back ordered.
	if (ordered > inStock)
	{
		available = inStock;
		backOrder = ordered - inStock;
	}

	// TODO: Calculate the charges.
	spoolCost = 100 * available;
	shipCharges = (10 + specialShipping) * available;
	totalCharges = spoolCost + shipCharges;
	// Display the order summary.
	cout << "\nOrder Summary\n"
		<< "==================\n"
		<< "\nItems ordered: " << ordered
		<< "\nReady to ship: " << available;

	if (available < ordered)
	{
		cout << "\nOn backorder: " << backOrder;
	}

	cout << fixed << showpoint << setprecision(2)
		<< endl
		<< "\nSubtotal: " << setw(8) << "$" << spoolCost
		<< "\nShipping: " << setw(8) << "$" << shipCharges
		<< "\nTotal Due: " << setw(7) << "$" << totalCharges
		<< endl;
}