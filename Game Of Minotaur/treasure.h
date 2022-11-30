#pragma once

#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;


template <class T>
class Treasure
{
	T value;
	string name;
public:
	Treasure(string name, T value) 
		: name(name), value(value) {}

	string getName()
	{
		return name;
	}

	friend ostream& operator<<(ostream& out, const Treasure treasure)
	{
		cout << treasure.name << " of value " << treasure.value << " coins." << endl;
		return out;
	}
};