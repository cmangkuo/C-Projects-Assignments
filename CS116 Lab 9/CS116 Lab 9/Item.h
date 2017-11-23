#pragma once
#include "SimpleVector.h"
#include <string>
using namespace std;


class Item
{
private: 
	int SKU, quantity;
	string description;
public:
	// Default Constructor
	Item();
	

	// Parameterized Constructors
	Item(int, string, int);
	Item(int);

	// Class functions
	void updateInventory(int);

	// Operator Overloads
	bool operator< (const Item& a) const;
	bool operator== (const Item& a) const;

	friend ostream& operator << (ostream & output, const Item &a)
	{
		output << "SKU: " << a.SKU << ", " << a.description << " [stock = " << a.quantity << "]" << endl;
		return output;

	}
};

