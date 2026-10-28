#pragma once

#include<iostream>
using namespace std;

class General {
public:

	void printStar(int times) {
		for (int i = 0; i < times; ++i) {
			cout << "*";
		}
	}

	void printNewLine(int times) {
		for (int i = 0; i < times; ++i) {
			cout << "\n";
		}
	}
};