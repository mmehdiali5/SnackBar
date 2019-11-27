#include<iostream>
using namespace std;
#include"MenuItem.h"

MenuItem::MenuItem():itemName("none")
{
	price = 0;
	quantity = 0;
}

MenuItem::MenuItem(CString name, double p, int q):itemName(name)
{
	price = p;
	quantity = q;
}

void MenuItem::setItemName(CString c)
{
	if (c.getLength() != 0)
	{
		itemName = c;
	}
}

void MenuItem::setItemPrice(double p)
{
	if (p > 0)
	{
		price = p;
	}
}

void MenuItem::setItemQuantity(int q)
{
	if (q > 0)
	{
		quantity = q;
	}
}

CString MenuItem::getItemName()const
{
	return itemName;
}

double MenuItem::getItemPrice()const
{
	return price;
}

int MenuItem::getItemQuantity()const
{
	return quantity;
}

void MenuItem::displayMenuItem()const
{
	cout << "Name: " << itemName << " Price: " << price << "\n";
}

void MenuItem::inputMenuItem()
{
	cout << "\nEnter Menu Item Name: ";
	itemName.input();
	cout << "\nEnter Price of Item: ";
	cin >> price;
	cout << "\nEnter Item Quantity: ";
	cin >> quantity;
}

ostream& operator<<(ostream & c, MenuItem & m)
{
	m.displayMenuItem();
	return c;
}

istream& operator>>(istream & c, MenuItem & m)
{
	m.inputMenuItem();
	return c;
}
