#pragma once
#include "ItemList.h"
class Order : public ItemList
{
private:
	double total = 0.00;
	double savings = 0.00;
public:
	Order();
	~Order();

	void calculateTotal();
	string printReceipt();
	string toString();

	void add(Appetiser* choice);


	void add(Item* Choice);
	void remove(int position);
	
	int getTotal();
};