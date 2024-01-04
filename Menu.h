#pragma once
#include "ItemList.h"

class Menu : public ItemList
{
public:
	Menu(string F);
	~Menu();

	string toString();

	void load(string F); // sets filePath
};
