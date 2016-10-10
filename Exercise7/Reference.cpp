#include "stdafx.h"
#include <iostream>

using namespace std;

void reference ()
{
	int a = 1;
	int& r = a;

	cout << r + 2 << endl;
}