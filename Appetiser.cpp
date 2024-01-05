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
	string app = (this->getName() + ": $" + to_string(this->getPrice()) + ", " + to_string(this->getCalories()) + " cal");
	if (this->getShareable()) { app = app + " (Shareable)"; }
	if (this->gettwoForOne()) { app = app + " (2-4-1)"; }
	return(app);
}

bool Appetiser::getShareable() { return shareable; }
bool Appetiser::gettwoForOne() { return twoForOne; }
void Appetiser::setShareable(bool S) { shareable = S; }
void Appetiser::settwoForOne(bool T) { twoForOne = T; }