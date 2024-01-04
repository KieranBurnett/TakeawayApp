#pragma once
#include "Item.h"
#include <vector>

using namespace std;

class MainCourse : public Item
{
public:
	MainCourse(vector<string>obj);
	~MainCourse();
};

