// Lab Ch5.cpp : Defines the entry point for the console application.

// Chapter 5, Programming Challenge 16: Savings Account Balance; Tony Gaddis, page 296

// Author: Chris Mangkuorahardjo

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	double yrInterestRate; // Annual interest rate
	double moInterestRate; // Monthly interest rate
	double balance; // Account balance
	double deposited; // Amount deposited in a single month
	double withDrawn; // Amount withdrawn in a single month
	double moIntPaid; // Interest paid in a single month
	double totalDeposits = 0; // Total of all deposits
	double totalWithdrawals = 0; // Total of all withdrawals
	double totalInterest = 0; // Total interest earned
	int months; // Number of months passed

				// TODO: Set up the output formatting.

				// TODO: Get the annual interest rate.
	cout << "Enter the annual interest percentage on the account (e.g. 4%): " << endl;
	cin >> yrInterestRate;


	// TODO: Validate the interest rate - Interest rate must be non-negative

	while (yrInterestRate < 0)
	{
		cout << "Please enter a valid interest rate." << endl;
		cin >> yrInterestRate;
	}
	yrInterestRate /= 100;


	// TODO: Get the starting balance.
	cout << "Enter the starting balance: " << endl;
	cin >> balance;

	// TODO: Validate the starting balance - The balance must be greater than 0
	while (balance < 0)
	{
		cout << "Please enter a valid balance." << endl;
		cin >> balance;
	}

	// TODO: Get the number of months that the account has been open.
	cout << "Enter the number of months account has been open." << endl;
	cin >> months;

	// TODO: Validate the number of months - Number of months must be non-negative
	while (months <= 0)
	{
		cout << "Please enter a valid number." << endl;
		cin >> months;
	}


	// TODO: Calculate the monthly interest rate.
	moInterestRate = yrInterestRate / 12;

	// TODO: Process the transactions.
	for (int count = 1; count <= months; count++) {
		// TODO: Display the month number.
		cout << "Month: " << count << endl;
		// TODO: Input the amount deposited this month.
		cout << "Enter amount deposited this month." << endl;
		cin >> deposited;
		// TODO: Validate the amount deposited this month - Deposits must be zero or greater.
		while (deposited < 0)
		{
			cout << "Please enter a valid amount." << endl;
			cin >> deposited;
		}

		// TODO: Input the amount withdrawn this month- Total withdrawals for this month
		cout << "Enter amount withdrawn this month." << endl;
		cin >> withDrawn;

		// TODO: Validate the amount withdrawn this month.
		while (withDrawn < 0)
		{
			cout << "Please enter a valid amount." << endl;
			cin >> withDrawn;
		}


		// Calculate the totals. 
		// TODO: Add deposits to balance
		balance += deposited;
		// TODO: Total of deposits
		if (deposited > 0)
		{
			totalDeposits++;
		}

		// TODO: Subtract withdrawals from balance
		balance -= withDrawn;
		// TODO: Total of withdrawals
		if (withDrawn > 0)
		{
			totalWithdrawals++;
		}

		// Determine if we have a negative balance.
		if (balance < 0) {
			cout << "The account has a balance of $" << balance << endl;
			cout << "Because the balance is negative, the account has been closed." << endl;
			system("pause");
			break;
		}
		if (count<months)
		{
			cout << "Total deposits: " << fixed << setprecision(0) << totalDeposits << endl;
			cout << "Total withdrawals: " << fixed << setprecision(0) << totalWithdrawals << endl;
			// TODO: Calculate the monthly interest paid.
			moIntPaid = balance * moInterestRate;
			cout << "Interest paid this month: " << fixed << setprecision(2) << moIntPaid << endl;
			// TODO: Accumulate the total interest.
			totalInterest += moIntPaid;
			cout << "Total interest paid: " << fixed << setprecision(2) << totalInterest << endl;
			// TODO: Add the interest to the balance.
			balance += moIntPaid;
			cout << "Total balance this month: " << fixed << setprecision(2) << balance << endl;
		}

	}
	// Display results
	cout << "-----------------------------------------------------------" << endl;
	cout << "Amount of deposits:  " << setw(7) << fixed << setprecision(0) << totalDeposits << endl;
	cout << "Amount of withdrawals:  " << setw(4) << fixed << setprecision(0) << totalWithdrawals << endl;
	cout << "Final balance:  " << setw(12) << "$" << balance << fixed << setprecision(2) << endl;
	cout << "Amount of interest earned: " << setw(0) << "$" << totalInterest << endl << fixed << setprecision(2) << endl;
	system("pause");

	return 0;
}
