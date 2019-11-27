#include<iostream>
using namespace std;
#include"MenuItem.h"
#include"Menu.h"
#include"CString.h"

Menu::Menu(int cap)
{
	itemsList = new MenuItem*[cap];
	capacity = cap;
	noOfItems = 0;
}

Menu::~Menu()
{
	if (itemsList == nullptr)
	{
		capacity = 0;
		noOfItems = 0;
		return;
	}
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		(*itemsList[i]).~MenuItem();
	}
	delete[]itemsList;
	capacity = 0;
	noOfItems = 0;
}

Menu::Menu(const Menu & ref)
{
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	itemsList = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		itemsList[i]->setItemName(ref.itemsList[i]->getItemName());
		itemsList[i]->setItemPrice(ref.itemsList[i]->getItemPrice());
		itemsList[i]->setItemQuantity(ref.itemsList[i]->getItemQuantity());
	}
}

Menu & Menu::operator=(const Menu & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~Menu();
	if (!ref.itemsList)
	{
		return *this;
	}
	capacity = ref.capacity;
	noOfItems = ref.noOfItems;
	itemsList = new MenuItem*[capacity];
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		itemsList[i]->setItemName(ref.itemsList[i]->getItemName());
		itemsList[i]->setItemPrice(ref.itemsList[i]->getItemPrice());
		itemsList[i]->setItemQuantity(ref.itemsList[i]->getItemQuantity());
	}
	return *this;
}

void Menu::reSize(int newCap)
{
	if (newCap < capacity)
	{
		return;
	}
	MenuItem**mi = new MenuItem*[newCap];
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		mi[i] = itemsList[i];
	}
	delete[]itemsList;
	itemsList = mi;
	capacity = newCap;
}

bool Menu::isFull()const
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

bool Menu::isEmpty()const
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

int Menu::getPositionOfItem(const CString & c)const
{
	bool found = false;
	int i = 0;
	while (!found && i < noOfItems)
	{
		if(!((itemsList[i]->getItemName())==c))
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
		return i;
    }
	else
	{
		return -1;
	}
}

bool Menu::addItem(const MenuItem & m)
{
	if (noOfItems == capacity)
	{
		reSize(capacity * 2 + 1);
	}
	if (getPositionOfItem(m.getItemName()) == -1)
	{
		itemsList[noOfItems] = new MenuItem(m.getItemName(), m.getItemPrice(), m.getItemQuantity());
		noOfItems = noOfItems + 1;
		return true;
	}
	else
	{
		return false;
	}
}

bool Menu::removeItem(const CString & c)
{
	int i = getPositionOfItem(c);
	if (i != -1)
	{
		delete itemsList[i];
		itemsList[i] = itemsList[noOfItems-1];
		noOfItems = noOfItems - 1;
		return true;
	}
	else
	{
		return false;
	}
}

void Menu::displayMenu()const
{
	cout << "\n\n";
	for (int i = 0; i < noOfItems; i = i + 1)
	{
		cout << (*(itemsList[i])).getItemName()<<" Price: "<< (*(itemsList[i])).getItemPrice();
		cout << "\n";
	}
}

int Menu::getNumberOfItems()const
{
	return noOfItems;
}