#pragma once
#include <iostream>
#include <time.h>
#include <fstream>

using std::cout;
using std::ifstream;
using std::ofstream;

void AssignIP() {
	const string USER_DATA2 = "data/";

	srand(time(0));
	ofstream ip(USER_DATA2 + "ip.txt");
	ip << rand() % 196 << "." << rand() % 195 << "." << rand() % 98 << "." << rand() % 56;
	ip.close();
}