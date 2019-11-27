#ifndef ORDER_H
#define ORDER_H

class MenuItem;
class CString;

class Order
{
	const int orderId;
	MenuItem**items;
	int capacity;
	int noOfItems;
public:
	Order(int oid, int size = 10);
	Order(const Order&ref);
	Order&operator=(const Order & ref);
	bool isFull()const;
	bool isEmpty()const;
	int getOrderId()const;
	bool isMenuItemExist(const CString &)const;
	bool addMenuItem(const MenuItem &);
	bool removeMenuItem(const CString &);
	bool updateMenuItemQuantity(const CString &,int);
	double getTotalBill()const;
	int getNoOfItems()const;
	void displayOrder()const;
	~Order();
};


#endif
