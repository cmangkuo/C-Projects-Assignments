#pragma once
#include <iostream>
#include <string>
using namespace std;

class InvoiceItem
{
private:
	string name;
	int price, quantity;
	
public:
	
	InvoiceItem();
	InvoiceItem(string, int, int);
	void setName(string);
	void setPrice(int);
	void setQuantity(int);
	
	string getName() {
		return name;
	}
	int getPrice() {
		return price;
	}
	int getQuantity() {
		return quantity;
	}
	int getTotal() {
		return price*quantity;
	}

	friend ostream& operator<< (ostream& output, const InvoiceItem& a)
	{
		output << a.quantity << " " << a.name << "(s) at " << a.price << " gold each." << endl;
		return output;

	}
	
};

