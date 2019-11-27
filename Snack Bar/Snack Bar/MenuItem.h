#ifndef MENU_ITEM_H
#define MENU_ITEM_H
#include"CString.h"

class MenuItem
{
	CString itemName;
	double price;
	int quantity;
public:
	MenuItem();
	MenuItem(CString name, double p, int q);
	void setItemName(CString);
	void setItemPrice(double);
	void setItemQuantity(int);
	CString getItemName()const;
	double getItemPrice()const;
	int getItemQuantity()const;
	void displayMenuItem()const;
	void inputMenuItem();
};

ostream& operator<<(ostream &, MenuItem &);
istream& operator>>(istream &, MenuItem &);

#endif
