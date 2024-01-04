#include "Item.h"
#include <iostream>
#include <vector>

Item::Item() {}
Item::~Item() {}
string Item::toString() { 
	return((getName() + ": $"+ to_string(getPrice()) + ", " + to_string(getCalories()) + " cal")); 
}

string Item::getType() { return type; }
string Item::getName() { return name; }
double Item::getPrice() { return price; }
int Item::getCalories() { return calories; }

void Item::setType(string Ty) { type = Ty;}
void Item::setName(string N) { name = N; }
void Item::setPrice(double P) { price = P; }
void Item::setCalories(int C) { calories = C; }