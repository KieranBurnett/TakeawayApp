#include "Order.h"
#include <iostream>

Order::Order() {}
Order::~Order() {}

int Order::calculateTotal() { return 0; }
string Order::printReceipt() { return ""; }
string Order::toString() { return ""; }

void Order::add(Item* Choice) { 
	cout << "Added: " << " to your order.. " << endl; 
}
void Order::remove(int position) { 
	cout << "Removed: " << " from your order.. " << endl; 
}

int Order::getTotal() { return total; }
void Order::setTotal() {}