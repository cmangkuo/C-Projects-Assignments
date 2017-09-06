#include <iostream>
#include <iomanip>
//Author: Chris Mangkuorahardjo
using namespace std;
int main()
{
	int numchecks;
	double balance, checkcharge, checktotal, totalcharges = 0, total;
	bool under_400 = false;

	//  Uses user input to find initial balance
	cout << "Please enter initial balance." << endl;
	cin >> balance;

	// Checks if the initial balance is positive or negative. Displays a warning if negative

	if (balance<0)
	{
		cout << "Warning! Account is overdrawn." << endl;
	}

	//  Checks if balance is under 400, which will set a boolean true if that is the case
	if (balance<400)
	{
		under_400 = true;
	}


	//  Takes user input for the number of checks written.
	cout << "Please enter number of checks written" << endl;
	cin >> numchecks;

	//  Checks if user input an appropriate number. Will loop until a positive number is returned
	while (numchecks<0)
	{
		cout << "Please enter a valid number." << endl;
		cin >> numchecks;
	}


	// Checks the number of checks written and sets the checkcharge value accordingly.
	if (numchecks<20)
	{
		checkcharge = 0.1;
	}
	else if (numchecks<40)
	{
		checkcharge = 0.08;
	}
	else if (numchecks<60)
	{
		checkcharge = 0.06;
	}
	else
	{
		checkcharge = 0.04;
	}

	//  If initial balance < $400, add a $15 fee.
	if (under_400)
	{
		totalcharges += 15;
	}

	//  Calculates total charges then final balance.
	checktotal = numchecks*checkcharge;
	totalcharges += 10 + checktotal;
	total = balance - totalcharges;

	cout << "Charges" << endl;
	cout << "----------------------------------------------" << endl;
	cout << "Number of checks: " << setw(11) << numchecks << endl;
	cout << "Charge per check: " << setw(9) << "$" << fixed << setprecision(2) << checkcharge << endl;
	cout << "Total charge for checks: " << setw(2) << "-$" << fixed << setprecision(2) << checktotal << endl;
	if (under_400)
	{
		cout << "Minimum balance fee: " << setw(8) << "-$15" << endl;
	}
	cout << "Monthly fee: " << setw(16) << "-$10" << endl;
	cout << "-----------------------------------------------" << endl;
	cout << "Initial balance: " << setw(10) << "$" << balance << endl;
	cout << "Total charges: " << setw(12) << "-$" << fixed << setprecision(2) << totalcharges << endl;
	cout << "Final balance: " << setw(12) << "$" << fixed << setprecision(2) << total << endl;

	return 0;

}