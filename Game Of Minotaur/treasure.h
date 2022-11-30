#pragma once

#include <iostream>
#include <string.h>
#include <conio.h>
#include <cstdio>
using namespace std;


template <class T>
class treasure
{
	T value;
	char name[20];
public:
	treasure(const char* n, T v) : value(v) { strcpy_s(name, n); }

	friend ostream& operator<<(ostream& input, const treasure t)
	{
		cout << t.name << " of value " << t.value << " coins." << endl;
		return input;
	}
};