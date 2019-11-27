#include<iostream>
using namespace std;
#include "Order.h"
#include"MenuItem.h"

Order::Order(int oid, int size):orderId(oid)
{
	capacity = size;
	noOfItems = 0;
	items = new MenuItem*[capacity];
}

Order::Order(const Order & ref):orderId(ref.orderId)
{
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	items = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		items[i] = ref.items[i];
	}
}

Order& Order::operator=(const Order & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~Order();
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	items = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		items[i] = new MenuItem(*(ref.items[i]));
	}
	return *this;
}

bool Order::isFull()const
{
	if (noOfItems == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Order::isEmpty()const
{
	if (noOfItems == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Order::getOrderId()const
{
	return orderId;
}

bool Order::isMenuItemExist(const CString & c)const
{
	int i = 0;
	bool found = false;
	while (!found && i < noOfItems)
	{
		if (!(items[i]->getItemName() == c))
		{
			found = true;
		}
		else
		{
			i = i + 1;
		}
	}
	if (found)
	{
		return true;
    }
	else
	{
		return false;
	}
}

bool Order::addMenuItem(const MenuItem & m)
{
	if (!isMenuItemExist(m.getItemName()))
	{
		items[noOfItems] = new MenuItem(m);
		noOfItems = noOfItems + 1;
		for (int i = 0; i < noOfItems; i = i + 1)
		{
			if ((*(items[i])).getItemName() == m.getItemName())
			{
				int q = (*(items[i])).getItemQuantity();
				(*(items[i])).setItemQuantity(q - 1);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool Order::removeMenuItem(const CString & m)
{
	int i = 0;
	bool found = false;
	while (!found && i < noOfItems)
	{
		if (!(items[i]->getItemName() == m))
		{
			found = true;
		}
		else
		{
			i = i + 1;
		}
	}
	if (found)
	{
		delete items[i];
		items[i] = items[noOfItems - 1];
		noOfItems = noOfItems - 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool Order::updateMenuItemQuantity(const CString & c, int q)
{
	if(q>=0)
	{ 
		int i = 0;
		bool found = false;
		while (!found && i < noOfItems)
		{
			if (!(items[i]->getItemName() == c))
			{
				found = true;
			}
			else
			{
				i = i + 1;
			}
		}
		if (found)
		{
			items[i]->setItemQuantity(q);
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

double Order::getTotalBill()const
{
	double bill = 0;
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		bill = bill + items[i]->getItemPrice();
	}
	return bill;
}

int Order::getNoOfItems()const
{
	return noOfItems;
}

void Order::displayOrder()const
{
	cout << "ID: " << orderId<<"\n";
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		cout << *(items[i]) << "  " << (*(items[i])).getItemPrice()<<"\n";
	}
	cout << "\n";
}

Order::~Order()
{
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		delete items[i];
	}
	delete[]items;
	capacity = 0;
	noOfItems = 0;
}
