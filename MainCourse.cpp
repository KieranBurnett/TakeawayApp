#include "MainCourse.h"
#include <iostream>
#include <vector>

using namespace std;

MainCourse::MainCourse(vector<string> obj) {
	setType(obj[0]);
	setName(obj[1]);
	setPrice(stod(obj[2]));
	setCalories(stoi(obj[3]));
}
MainCourse::~MainCourse() {}