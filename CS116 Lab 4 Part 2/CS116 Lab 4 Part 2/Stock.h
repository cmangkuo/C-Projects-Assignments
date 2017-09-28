#pragma once
#include <string>
using namespace std;
class Stock
{
private:
	string CompanyName;
	int Shares;
	double PurchasePrice, CurrentPrice;

public:
	Stock();
	Stock(string, int, double, double);
	void setCompany();
	void setShare();
	void setPurchase();
	void setCurrent();
	void setData();

	string getCompany()
	{
		return CompanyName;
	}
	int getShares()
	{
		return Shares;
	}
	double getPurchase()
	{
		return PurchasePrice;
	}
	double getCurrent() 
	{
		return CurrentPrice;
	}
	double getValue() 
	{
		return CurrentPrice * Shares;
	}
	double getProfit()
	{
		return Shares*(CurrentPrice - PurchasePrice);
	}
};

