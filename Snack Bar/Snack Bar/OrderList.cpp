#include<iostream>
using namespace std;
#include"OrderList.h"
#include"Order.h"

int OrderList::orderIDGen = 0;

OrderList::OrderList(int size)
{
	noOfOrders = 0;
	capacity = size;
	orders = new Order*[capacity];
}

OrderList::OrderList(const OrderList & ref)
{
	noOfOrders = ref.noOfOrders;
	capacity = ref.capacity;
	orders = new Order*[capacity];
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		orders[i] = new Order(*(ref.orders[i]));
	}
}

OrderList::~OrderList()
{
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		delete orders[i];
	}
	delete[]orders;
	capacity = 0;
	noOfOrders = 0;
}

OrderList& OrderList::operator=(const OrderList & ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~OrderList();
	if (ref.orders == nullptr)
	{
		return *this;
	}
	noOfOrders = ref.noOfOrders;
	capacity = ref.capacity;
	orders = new Order*[capacity];
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		orders[i] = new Order(*(ref.orders[i]));
	}
	return *this;
}

void OrderList::reSize(int newSize)
{
	if ((newSize <= capacity) || (newSize < 0))
	{
		return;
	}
	capacity = newSize;
	Order**orders2= new Order*[capacity];
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		orders2[i] = orders[i];
	}
	delete[]orders;
	orders = orders2;
}

bool OrderList::isFull()const
{
	if (noOfOrders == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool OrderList::isEmpty()const
{
	if (noOfOrders == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool OrderList::addOrder(const Order & o)
{
	if (isFull())
	{
		return false;
	}
	else
	{
		if (noOfOrders == capacity)
		{
			reSize(capacity * 2 + 1);
		}
		orders[noOfOrders] = new Order(orderIDGen, o.getNoOfItems());
		*(orders[noOfOrders]) = o;
		noOfOrders = noOfOrders + 1;
		orderIDGen = orderIDGen + 1;
		return true;
	}
}

bool OrderList::removeOrder(int id)
{
	bool found = false;
	int i = 0;
	while (!found && i<noOfOrders)
	{
		if ((orders[i]->getOrderId()) == id)
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
		orders[i] = orders[noOfOrders - 1];
		noOfOrders = noOfOrders - 1;
		return true;
    }
	else
	{
		return false;
	}
}

double OrderList::getTotalEarning()const
{
	double earning = 0;
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		earning = earning + (orders[i]->getTotalBill());
	}
	return earning;
}

int OrderList::getNumberOfOrders()const
{
	return noOfOrders;
}

void OrderList::displayOrder(int id)
{
	bool found = false;
	int i = 0;
	while (!found && i < noOfOrders)
	{
		if ((orders[i]->getOrderId()) == id)
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
		cout << "ID: " << id<<"\n";
		orders[i]->displayOrder();
		cout << "\n\n";
	}
}

void OrderList::getTotalBillOfOrder(int id)
{
	bool found = false;
	int i = 0;
	while (!found && i < noOfOrders)
	{
		if ((orders[i]->getOrderId()) == id)
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
		cout << "\nTotalBill: " << orders[i]->getTotalBill() << "\n";
	}
}

void OrderList::displayAllOrders()const
{
	for (int i = 0; i < noOfOrders; i = i + 1)
	{
		orders[i]->displayOrder();
	}
}