// Exercise7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Swap.h"

using namespace std;

int nums[10] = {7, 3, 5, 2, 1, 4, 6, 9, 10, 8};

void sort_ascending ()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 10; j++)
		{
			if (nums[j] < nums[i])
				swap_ref (nums[i], nums[j]);
		}
	}
}

int main ()
{
	sort_ascending ();

	for (int i = 0; i < 10; i++)
	{
		cout << nums[i] << endl;
	}

	system ("pause");

    return 0;
}