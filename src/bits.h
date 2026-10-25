#pragma once

#include<iostream>
#include<string>
#include "LinkedList.h"

using namespace std;

class Bit {
public:
	LinkedList<char> completeNibble(string bitStr) {
		LinkedList<char> linkedlist;

		const char* chars = bitStr.c_str();

		for (int i = 0; i < bitStr.length(); ++i) {
			linkedlist.insertAtEnd(chars[i]);
		}

		switch (bitStr.length()) {
		case 4:
			return linkedlist;
		case 3:
			linkedlist.insertAtBegin('0');
			return linkedlist;
		case 2:
			linkedlist.insertAtBegin('0');
			linkedlist.insertAtBegin('0');
			return linkedlist;
		case 1:
			linkedlist.insertAtBegin('0');
			linkedlist.insertAtBegin('0');
			linkedlist.insertAtBegin('0');
			return linkedlist;
		}
	}
};