#pragma once
#include <string>
#include <vector>

using namespace std;

class Item
{
private:
	string type;
	string name;
	double price;
	int calories;
public:
	Item();
	~Item();

	virtual string toString();

	string getType();
	string getName();
	double getPrice();
	int getCalories();

	void setType(string Ty);
	void setName(string N);
	void setPrice(double P);
	void setCalories(int C);
};

