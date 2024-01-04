#pragma once
#include <vector>
#include "Item.h"

using namespace std;

class ItemList // abstract
{
public:
	vector<Item*> Items;
	virtual string toString() = 0;
};

