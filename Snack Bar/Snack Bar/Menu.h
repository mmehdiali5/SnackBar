#ifndef MENU_H
#define MENU_H

class MenuItem;
class CString;

class Menu
{
	MenuItem** itemsList;
	int capacity;
	int noOfItems;
public:
	Menu(int capacity=5);
	Menu(const Menu & ref);
	Menu& operator=(const Menu & ref);
	void reSize(int newSize);
	bool isFull()const;
	bool isEmpty()const;
	int getPositionOfItem(const CString &)const;
	bool addItem(const MenuItem&);
	bool removeItem(const CString &);
	void displayMenu()const;
	int getNumberOfItems()const;
	~Menu();
};

#endif
