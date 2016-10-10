// Exercise6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace some_namespace {
	void some_function ()
	{
		cout << "some_function" << endl;
	}
}

namespace some_other_namespace {
	void some_other_function ()
	{
		cout << "some_other_function" << endl;
	}
}

int main ()
{
	some_namespace::some_function ();
	some_other_namespace::some_other_function ();

	system ("pause");
    return 0;
}

