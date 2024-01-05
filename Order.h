#pragma once
#include "ItemList.h"
class Order : public ItemList
{
private:
	double total;
	double savings;
public:
	Order();
	~Order();

	void calculateTotal();
	void printReceipt();
	string toString();

	void add(Item* Choice);
	void remove(int position);
};