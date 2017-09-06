// Chapter 3, Programming Challenge 14: Monthly Sales Tax
// Author: Chris Mangkuorahardjo
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Constants
	const double COUNTY = 0.02; // County sales tax
	const double STATE = 0.04; // State sales tax
	double Sales[12] = {0};
	string months[12] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
	double sales, countytax, statetax, totaltax, total;
	bool run = true;
	int month;
	int n = 0;
	string response, response1, response2;
	// TODO: Define the required variables



	while (run == true)
	{
		cout << "Enter Month (1-12)" << endl;
		cin >> month;
		response = "Y";
		n = 0;
		while (month < 1 || month>12)
		{
			cout << "Please enter a valid number" << endl;
			cin >> month;
		}
		if (Sales[month-1] != 0)
		{
			cout << "An entry already exists. Overwrite? (Y/N)" << endl;
			cin >> response;
		}

		while (response != "Y" && response != "y" && response != "N" && response != "n")
		{
			cout << "Please enter a valid response." << endl;
			cin >> response;
		}
		if (response == "Y" || response == "y")
		{
			cout << response << endl;
			cout << "Enter sales amount." << endl;
			cin >> sales;
		}

			

			// TODO: Calculate the county sales tax.
			countytax = sales*COUNTY;

			// TODO: Calculate the state sales tax.
			statetax = sales*STATE;

			// TODO: Calculate the total sales tax.
			totaltax = countytax + statetax;

			// TODO: Calculate the product sales.
			total = sales + totaltax;

			// TODO: Display results
			cout << "Sales: "<< setw(7) << "$" << sales << endl;
			cout << "County Tax: "<< setw(2) << "$" << fixed << setprecision(2) << countytax << endl;
			cout << "State Tax: " << setw(3) << "$"   << fixed << setprecision(2) << statetax << endl;
			cout << "Total Tax: " << setw(3) << "$"   << fixed << setprecision(2) << totaltax << endl;
			cout << "Total Sales: " << setw(0) << "$"   << fixed << setprecision(2) << total << endl;
			Sales[month - 1] = total;
			cout << "----------------------------------------------" << endl;

			cout << "Sales By Month" << endl;
			while (n < 12)
			{	
				cout << months[n] << ": $" << fixed << setprecision(2) << Sales[n] << endl;
				n++;
			}


			
			cout << "Add another entry?(Y/N)" << endl;
			cin >> response2;
			while (response2 != "Y" && response2 != "y" && response2 != "N" && response2 != "n")
			{
				cout << "Please enter a valid response." << endl;
				cin >> response2;
			}
			if (response2 == "N" || response2 == "n")
			{
				run = false;
			}
			
		}


		return 0;

	}
