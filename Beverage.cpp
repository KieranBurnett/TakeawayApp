#include "Beverage.h"
#include <iostream>
#include <vector>

Beverage::Beverage( vector<string> obj ) {
	setType(obj[0]);
	setName(obj[1]);
	setPrice(stod(obj[2]));
	setCalories(stoi(obj[3]));
	setVolume(stoi(obj[6]));
	setAbv(stod(obj[7]));
}
Beverage::~Beverage() {}

bool Beverage::isAlcoholic() { 
	if (getAbv() != 0) { return true; }
	else { return false; }
}
string Beverage::toString() { 
	return(getName()+ ": $"+ to_string(getPrice())+ ", " + to_string(getCalories()) + " cal (" + to_string(getVolume()) + ", " + to_string(getAbv()) + "% abv)");
}

int Beverage::getVolume() { return volume; }
double Beverage::getAbv() { return abv; }
void Beverage::setVolume(int V) { volume = V; }
void Beverage::setAbv(double A) { abv = A; }