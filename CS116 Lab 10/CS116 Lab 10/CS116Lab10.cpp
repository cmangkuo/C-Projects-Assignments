// CS116Lab10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "LinkedList.h"
#include "InvoiceItem.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{	
	// Set up the shop
	LinkedList<InvoiceItem> Shop;
	
	Shop.appendNode(InvoiceItem("Iron Sword", 100, 1));
	Shop.appendNode(InvoiceItem("Steel Sword", 200, 1));
	Shop.appendNode(InvoiceItem("Iron Shield", 75, 1));
	Shop.appendNode(InvoiceItem("Steel Shield", 150, 1));
	Shop.appendNode(InvoiceItem("Iron Armor", 200, 1));
	Shop.appendNode(InvoiceItem("Steel Armor", 400, 1));
	Shop.appendNode(InvoiceItem("Potion", 20, 15));
	cout << "=================================================" << endl;
	
	// Initialize the Cart
	LinkedList<InvoiceItem> Cart;
	int cartSize = 0; // Determines number of item types in cart (NOT QUANTITY)
	int cartQuantity = 0; // Quantity of items in cart

	// Print out shop inventory
	cout << "Shop Inventory" << endl;
	Shop.displayList();
	
	// Main menu
	int choice = 100;
	while (choice != 0)
	{
		cout << "Enter item number to add to cart, or 0 to checkout: ";
		cin >> choice;
		cin.ignore();

		// Input validation
		while ((!choice) || (choice < 0) || (choice > 7))
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			cout << "Invalid number, please re-enter: ";
			cin >> choice;
			cin.ignore();

		}

		if (choice == 1)
		{
			// Check quantity of item, determine whether item is in stock, add to cart if it is
			int stock = Shop.getNodeAt(1).getQuantity();
			string itemname = Shop.getNodeAt(1).getName();
			int position;
			if (stock == 0)
			{
				cout << "Item out of stock" << endl;
			}
			else
			{
				// Reduce stock in shop
				Shop.getNodeAt(1).setQuantity(stock - 1);
				bool itemAlreadyInCart = 0;
				// Check if instance of item is already in cart
				for (int i = 0; i < cartSize; i++)
				{
					// If item in cart already, record position and set boolean to true
					if (Shop.getNodeAt(1).getName() == Cart.getNodeAt(i).getName())
					{
						position = i;
						itemAlreadyInCart = 1;
					}

				}

				// Add item to cart
				if (!itemAlreadyInCart) // Item not already in cart
				{
					Cart.appendNode(InvoiceItem(Shop.getNodeAt(1).getName(), Shop.getNodeAt(1).getPrice(), 1));
					cartQuantity++;
					cartSize++;
				}

				else // Item already exists in cart
				{
					Cart.getNodeAt(1).setQuantity(Cart.getNodeAt(1).getQuantity() + 1);
					cartQuantity++;
				}

			}
		}


	}
	

    return 0;
}

