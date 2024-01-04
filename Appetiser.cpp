#include "Appetiser.h"
#include <iostream>
#include <vector>


Appetiser::Appetiser( vector<string> obj) {
	setType(obj[0]);
	setName(obj[1]);
	setPrice(stod(obj[2]));
	setCalories(stoi(obj[3]));
	if (obj[4] == "y") { setShareable(true); }
	else { setShareable(false); }
	if (obj[5] == "y") { settwoForOne(true); }
	else { settwoForOne(false); }
}
Appetiser::~Appetiser() {}

string Appetiser::toString() { 
	if (this->getShareable()) { return((this->getName()+ ": $" + to_string(this->getPrice()) + ", " + to_string(this->getCalories()) + " cal (shareable)")); }
	else if (this->gettwoForOne()) { return((this->getName() + ": $" + to_string(this->getPrice()) + ", " + to_string(this->getCalories()) + " cal (2-4-1)")); }
	else { return((this->getName() + ": $" + to_string(this->getPrice()) + ", " + to_string(this->getCalories()) + " cal")); }
}

bool Appetiser::getShareable() { return shareable; }
bool Appetiser::gettwoForOne() { return twoForOne; }
void Appetiser::setShareable(bool S) { shareable = S; }
void Appetiser::settwoForOne(bool T) { twoForOne = T; }