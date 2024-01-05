#include "Order.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "beverage.h"
#include "ItemList.h"
#include "Item.h"
#include <iostream>
#include <vector>

Order::Order() {}
Order::~Order() {}

void Order::calculateTotal() { 
	for (auto obj : Items) {
		total += obj->getPrice();
		if (obj->getType() == "a") {
			obj->toString();
			// 2-4-1
		}
	}

	vector<Item*> tfo_items;
	savings = 0;
}
string Order::printReceipt() { return ""; }
string Order::toString() { calculateTotal(); return to_string(total); }

void Order::add(Appetiser* choice) { 
	cout << "Added: " << choice->getName() <<  " for $" << choice->getPrice() << " to your order.. " << endl;
	Items.push_back(choice);
}

void Order::remove(int position) { 
	cout << "Removed: " << Items[position]->getName() << " from your order.. " << endl; 
	Items.erase(Items.begin()+(position));
}

int Order::getTotal() { return total; }