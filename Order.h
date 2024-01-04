#pragma once
#include "ItemList.h"
class Order : public ItemList
{
private:
	int total;
public:
	Order();
	~Order();

	int calculateTotal();
	string printReceipt();
	string toString();

	void add(Item* Choice);
	void remove(int position);
	
	int getTotal();
	void setTotal();
};

