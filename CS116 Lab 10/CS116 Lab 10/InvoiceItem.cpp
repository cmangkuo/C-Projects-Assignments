#include "stdafx.h"
#include "InvoiceItem.h"


InvoiceItem::InvoiceItem()
{
	name = "Empty";
	price = 0;
	quantity = 0;
}

InvoiceItem::InvoiceItem(string item, int cost, int num)
{
	name = item;
	price = cost;
	quantity = num;
}

void InvoiceItem::setName(string item)
{
	name = item;
}

void InvoiceItem::setPrice(int cost)
{
	price = cost;
}

void InvoiceItem::setQuantity(int num)
{
	quantity = num;
}





