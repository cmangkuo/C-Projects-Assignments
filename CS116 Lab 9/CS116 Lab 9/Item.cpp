#include "stdafx.h"
#include "Item.h"
#include <iostream>
using namespace std;
// Default
Item::Item()
{
	quantity = 0;
	description = "Placeholder";
	SKU = 0;
}


// Parameter
Item::Item(int num, string desc, int quant)
{
	SKU = num;
	description = desc;
	quantity = quant;
}

Item::Item(int num)
{
	SKU = num;
}

void Item::updateInventory(int quant)
{
	// Check if quantity is large enough to be subtracted from if quant is negative
	while (((quantity < abs(quant)) && (quant < 0)) || (!quant))
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Please enter a valid quantity: ";
		}
		if (quantity < abs(quant))
		{
			cout << "Not enough stock, please re-enter: ";
		}
		cin >> quant;
		cin.ignore();
		
	}

	// Adjust quantity
	quantity += quant;
	
}

bool Item::operator<(const Item & a) const
{
	return (SKU < a.SKU);
}

bool Item::operator==(const Item & a) const
{
	return (SKU == a.SKU);
}
