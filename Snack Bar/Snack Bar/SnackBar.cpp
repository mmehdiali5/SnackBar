#include<iostream>
using namespace std;
#include"SnackBar.h"
#include"CString.h"
#include"MenuItem.h"
#include"Order.h"

void SnackBar::startApp()
{
	bool stop = false;
	int input;
	do
	{
		cout << "\nEnter 1 to add item to Menu ";
		cout << "\nEnter 2 to remove item from the Menu ";
		cout << "\nEnter 3 to get Number Of Items in The Menu ";
		cout << "\nEnter 4 to display Menu ";
		cout << "\nEnter 5 to Enter Order ";
		cout << "\nEnter 0 to close application ";
		cin >> input;
		cin.ignore();
		if (input == 0)
		{
			stop = true;
		}
		else if (input == 1)
		{
			MenuItem mi;
			mi.inputMenuItem();
			int i=restaurantMenu.addItem(mi);
			if (i)
			{
				cout << "Item added Successfully\n";
			}
			else
			{
				cout << "Item Already Exist\n";
			}
		}
		else if (input == 2)
		{
			cout << "\nEnter item name to remove it: ";
			CString c;
			c.input();
			int i = restaurantMenu.removeItem(c);
			if (i)
			{
				cout << "Item removed Successfully\n";
			}
			else
			{
				cout << "Item not Exist in Menu\n";
			}
		}
		else if (input == 3)
		{
			cout << "Number Of Items are: " << restaurantMenu.getNumberOfItems()<<"\n";
		}
		else if (input == 4)
		{
			restaurantMenu.displayMenu();
		}
		else if (input == 5)
		{
			CString name;
			cout << "\nEnter name of item to add in order ";
			name.input();
			int i = restaurantMenu.getPositionOfItem(name);
			if ( i!= -1)
			{
				Order o(-1);
				MenuItem m(name, 0, 0);
				o.addMenuItem(m);
				list.addOrder(o);
			}
			else
			{
				cout << "Item not available";
			}
		}
	} while (!stop);
	cout << "Application Terminated Successfully";
}