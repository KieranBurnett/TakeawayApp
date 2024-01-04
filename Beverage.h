#pragma once
#include "Item.h"
#include <vector>

using namespace std;

class Beverage : public Item
{
private:
	int volume;
	double abv;
public:
	Beverage( vector<string> obj );
	~Beverage();

	bool isAlcoholic();
	string toString();

	int getVolume();
	double getAbv();
	void setVolume(int V);
	void setAbv(double A);
};

