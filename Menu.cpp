//#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

Menu::Menu(string F) { load(F); }
Menu::~Menu() {}

string Menu::toString() {
	int length = Items.size();
	string app = "\n[MENU]\n  | Appetisers |";
	string main = "\n  | Main Dishes |";
	string bev = "\n  | Beverages |";

	for (int i = 0; i < length; i++) {
		if (Items[i]->getType() == "a") { // if the item is an appetiser..
			app = app + "\n" + to_string(i+1) + "| " + Items[i]->toString();
		}
		else if (Items[i]->getType() == "m") { // if the item is an main course..
			main = main + "\n" + to_string(i+1) + "| " + Items[i]->toString();
		}
		else if (Items[i]->getType() == "b") { // if the item is an beverage..
			bev = bev + "\n" + to_string(i+1) + "| " + Items[i]->toString();
		} 
	}
	return (app + "\n" + main + "\n" + bev + "\n");
}

void Menu::load(string F) {
	ifstream File(F);
	if (!File.is_open()) { cout << "file not found"; };

	vector<string> obj;
	string line, values;

	for (int j = 0; j < 12; j++) {
		obj.clear();
		getline(File, line); // get current line from file

		stringstream s(line); // convert line to string stream
		while (getline(s, values, ',')) {
			if (values == "") { // if the token is empty, skip it
				obj.push_back("empty value");
				continue; }
			obj.push_back(values); // add each value to the vector
		}
		
		if (obj[0] == "a") { // appetiser
			Appetiser *A = new Appetiser(obj);
			Items.push_back(A);
		}
		else if (obj[0] == "m") { // main course
			MainCourse *M = new MainCourse(obj);
			Items.push_back(M);
		}
		else if (obj[0] == "b") { // beverage
			Beverage *B = new Beverage(obj);
			Items.push_back(B);
		}
	}
	cout << "Menu loaded successfully" << endl;
	File.close();
}