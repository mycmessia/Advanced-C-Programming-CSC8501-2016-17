#pragma once
#ifndef _REGISTER_
#define _REGISTER_

#include <iostream>

using namespace std;

const int REGISTER_COUNT = 3;

class Register {
public:
	Register () : value (0) {}
	Register (int v) : value (v) {}
	~Register () {}

	int get_value () { return value; }

	Register operator^ (const Register& r);
	friend ostream& operator<< (ostream& ostr, const Register& r);

private:
	int value;
};

#endif