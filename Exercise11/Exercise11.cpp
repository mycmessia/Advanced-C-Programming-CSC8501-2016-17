// Exercise11.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "MatrixDefinition.h"

using namespace std;

int main()
{
	Matrix<int> mtx1;
	mtx1.set_element (1, 1, 4);
	cout << mtx1;

	Matrix<int> mtx2;
	mtx2.set_element (2, 2, 2);
	cout << mtx2;

	Matrix<int> mtx3;
	mtx3 = mtx2;
	cout << mtx3;

	Matrix<int> product = (mtx1 * mtx2);
	cout << product;

	system ("pause");
    return 0;
}