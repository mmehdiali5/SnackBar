#ifndef SNACK_BAR_H
#define SNACK_BAR_H
#include"Menu.h"
#include"OrderList.h"

class SnackBar
{
	Menu restaurantMenu;
	OrderList list;
public:
	void startApp();
};

#endif

