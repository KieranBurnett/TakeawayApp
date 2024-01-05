/* ------------------------------------------------------
CMP2811 Applied Programming Paradigms
Driver program for "Takeaway" assignment
Autumn 2023

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure you follow that guideline.
Also make sure that you don't modify the code provided here,
but instead add what you need to complete the tasks.

Good luck!
------------------------------------------------------ */
#define _CRT_SECURE_NO_WARNINGS

#include "Menu.h"
#include "Order.h"
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main()
{
	string userCommand;
	vector <string> parameters;

	// Create a menu object from a CSV file
	Menu menu = Menu("menu.csv");

	// Create an order object
	Order order = Order();
	while (userCommand != "exit")
	{
		cout << "\nWaiting on command.. " << endl;
		getline(cin, userCommand);
		if (userCommand == "") { continue; }
		char* cstr = new char[userCommand.length() + 1];
		strcpy(cstr, userCommand.c_str());

		char* token;
		token = strtok(cstr, " "); // takes first word of input

		while (token != NULL)
		{
			parameters.push_back(token);
			token = strtok(NULL, " "); // splits input by " ", stores each one as a token, added to parameters
		}

		string command = parameters[0]; // first word of user input

		if (command.compare("menu") == 0) {
			cout << menu.toString(); // output menu
		}
		else if (command.compare("add") == 0) {
			int digit = stoi(parameters[1]); // string Name, double Price, int Calories, string Shareable, string Tfo, string Type 
			Item* choice = menu.Items[digit-1];
			order.add(choice);

			// You may also wish to implement the ability to add multiple items at once!
			// e.g. add 1 5 9 
		}
		else if (command.compare("remove") == 0)
		{
			order.remove(stoi(parameters[1])-1);
		}
		else if (command.compare("checkout") == 0)
		{
			cout << order.toString() << endl; // display the items in order, total price and savings made
			cout << "Type 'yes' to confirm your order.. " << endl;
			string inp;
			cin >> inp;
			if (inp == "yes") { 
			order.printReceipt(); 
			exit(1);
			}
		}
		else if (command.compare("help") == 0)
		{
			cout << "\n  [HELP]" << endl;
			cout << "menu - display the menu to the user" << endl;
			cout << "add [INDEX] - add an item to the order by numeric index in the menu(starting at 1)" << endl;
			cout << "remove[INDEX] - remove item from order by numeric index in the order(starting at 1)" << endl;
			cout << "checkout - display the items in the user’s order, the price, and discount savings" << endl;
			cout << "help - display a help menu for the user with the available options" << endl;
			cout << "exit - terminate the program gracefully" << endl;
		}

		parameters.clear();

	}

	cout << "Press any key to quit...";
	std::getchar();

}