#include <iostream>
#include <iomanip>
using namespace std;

// Author: Chris Mangkuorahardjo
// Price of item 1 = $15.95 
// Price of item 2 = $24.95
// Price of item 3 = $6.95
// Price of item 4 = $12.95
// Price of item 5 = $3.95

int main()
{

	// Constants
	double subtotal = 0;
	double taxrate = 0.0925;
	double tax;
	double total;
	int count = 0;
	int n = 5;
	int y = 5;
	double item1, item2, item3, item4, item5;


	// TODO - Store the prices of the five items in five variables.

	item1 = 15.95;
	item2 = 24.95;
	item3 = 6.95;
	item4 = 12.95;
	item5 = 3.95;

	double prices[5] = { 0 };
	prices[0] = item1;
	prices[1] = item2;
	prices[2] = item3;
	prices[3] = item4;
	prices[4] = item5;

	// TODO - Calculate the subtotal.

	while (n>0)
	{
		subtotal = subtotal + prices[y - n];
		n--;
	}

	// TODO - Calculate the total.
	tax = subtotal*taxrate;
	total = subtotal + tax;



	// TODO - Display each item’s price, the subtotal of the sale, 
	// the amount of sales tax, and the total.
	cout << "Total Items: " << y << endl;
	while (count != y)
	{
		cout << "Item " << count + 1 << ":" << setw(10) << " $" << prices[count] << endl;
		count++;
	}
	cout << "-----------------------------" << endl;
	cout << "Subtotal: " << setw(7) << "$" << fixed << setprecision(2) << subtotal << endl;
	cout << "Tax (9.25%): " << setw(4) << "$" << fixed << setprecision(2) << setw(2) << tax << endl;
	cout << "Total Price: " << setw(4) << "$" << fixed << setprecision(2) << setw(2) << total << endl;

	return 0;

}