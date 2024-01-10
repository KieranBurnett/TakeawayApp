#include "Order.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 
#include <cstdlib>

Order::Order() { total = 0.00; savings = 0.00; }
Order::~Order() {}

void Order::calculateTotal() { 
	double new_total = 0.00;
	double new_savings = 0.00;
	vector<double> tfo_prices;
	for (Item* obj : Items) {
		new_total = new_total + obj->getPrice();
		if (obj->getType() == "a") {
			Appetiser* object = dynamic_cast<Appetiser*>(obj);
			if (object->gettwoForOne()) {
				tfo_prices.push_back(object->getPrice());
			}
		}
	}

	int length = tfo_prices.size();
	if (length > 1) {
		sort(tfo_prices.begin(), tfo_prices.end());
		if (length % 2 != 0) { tfo_prices.pop_back(); length = length - 1; } // makes it and even amount, most expensive is unnecessary, doesnt change anything
		for (int i = 0; i < length / 2; i++) { tfo_prices.pop_back(); }
		for (double price : tfo_prices) {
			new_savings += price;
		}
		new_total-=new_savings;
	}
	else { new_savings = 0; }
	total = new_total;
	savings = new_savings;
}

void Order::printReceipt() { // writes toString() to a file, receipt.txt
	ofstream File("receipt.txt");
	File << toString();
	File.close();
} 
string Order::toString() {
	calculateTotal();
	string str = "\n\t|Checkout|";
	for (int i = 0; i < Items.size(); i++) {
		if (Items[i]->getType() == "a") {
			Appetiser* object = dynamic_cast<Appetiser*>(Items[i]);
			str = str + "\n" + to_string(i+1) + "|" + object->toString();
		}
		if (Items[i]->getType() == "m") {
			MainCourse* object = dynamic_cast<MainCourse*>(Items[i]);
			str = str + "\n" + to_string(i+1) + "|" + object->toString();
		}
		if (Items[i]->getType() == "b") {
			Beverage* object = dynamic_cast<Beverage*>(Items[i]);
			str = str + "\n" + to_string(i+1) + "|" + object->toString();
		}
	}
	str = str + "\n";
	if (savings > 0.00) { str = str + "\n\t2-4-1 Discount(s) applied!"; }
	str = str + "\nSavings: £" + to_string(savings) + "\nTotal: £" + to_string(total);
	return(str);
}

void Order::add(Item* choice) { 
	cout << "Added: " << choice->getName() <<  " for £" << choice->getPrice() << " to your order.. " << endl;
	Items.push_back(choice);
}

void Order::remove(int position) { 
	cout << "Removed: " << Items[position]->getName() << " from your order.. " << endl; 
	Items.erase(Items.begin()+(position));
}