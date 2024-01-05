#pragma once
#include "Item.h"
#include <vector>
#include <memory>

using namespace std;

class ItemList // abstract
{
public:
	vector<unique_ptr<Item>> Items;
	virtual string toString() = 0;
};

