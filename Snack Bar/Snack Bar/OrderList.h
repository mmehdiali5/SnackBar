#ifndef ORDER_LIST_H
#define ORDER_LIST_H
class Order;

class OrderList
{
	static int orderIDGen;
	Order**orders;
	int noOfOrders;
	int capacity;
public:
	OrderList(int size = 5);
	OrderList(const OrderList & ref);
	OrderList&operator=(const OrderList&ref);
	void reSize(int newSize);
	bool isFull()const;
	bool isEmpty()const;
	bool addOrder(const Order &);
	bool removeOrder(int);
	double getTotalEarning()const;
	int getNumberOfOrders()const;
	void displayOrder(int orderId);
	void getTotalBillOfOrder(int orderId);
	void displayAllOrders()const;
	~OrderList();
};

#endif
