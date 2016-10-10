#include "stdafx.h"
#include <iostream>

using namespace std;

void swap (int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap2 (int* x, int* y)
{
	int* temp = x;
	x = y;
	y = temp;

	//cout << "x " << x << " y " << y << endl;
}

void swap3 (int** x, int** y)
{
	int *xx = *x;
	int *yy = *y;

	int* temp = xx;
	xx = yy;
	yy = temp;
}

void swap4 (int x, int y)
{
	int temp = x;
	x = y;
	y = temp;
	
	//cout << "x: " << x << " y: " << y << endl;
}

void swap_ref (int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void swap_test ()
{
	//int a = 1; int b = 2;
	//int* p1 = &a; int* p2 = &b;

	//cout << "a: " << a << " b: " << b << endl;
	//swap(&a, &b);
	//cout << "a: " << a << " b: " << b << endl;

	//cout << "p1: " << p1 << " p2 " << p2 << endl;
	//swap3 (&p1, &p2);
	//cout << "p1: " << p1 << " p2 " << p2 << endl;
}