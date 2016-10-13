// Exercise12.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class B {
public:
	B (int n) : n (n) {};
	~B () {};

	int get_b () {return n;}

private:
	int n;
};

class A {
public:
	A (int n) : n (n) {};
	~A () {};

	void printInt (A* b) {
		std::cout << b->n<< std::endl;
	};

private:
	int n;
};



int main()
{
	A x (1), y (2);

	x.printInt (&y);

	system ("pause");
    return 0;
}

