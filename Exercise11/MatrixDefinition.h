#include "stdafx.h"
#include "Matrix.h"

#ifndef _MATRIX_DEFINITION_
#define _MATRIX_DEFINITION_

using namespace std;

template <typename T>
Matrix<T>::Matrix (int x, int y) : x_size (x), y_size (y)
{
	cells = new T*[x_size];
	for (int i = 0; i < x_size; i++)
	{
		cells[i] = new T[y_size];
		memset (cells[i], 0, (y_size * sizeof (T)));
	}
}

// copy constructor
template <typename T>
Matrix<T>::Matrix (const Matrix<T>& src)
{
	x_size = src.get_x_size ();
	y_size = src.get_y_size ();

	cells = new T*[x_size];
	for (int i = 0; i < x_size; i++)
	{
		cells[i] = new T[y_size];
		memset (cells[i], 0, (y_size * sizeof (T)));
	}
}

template <typename T>
Matrix<T>::~Matrix ()
{
	for (int i = 0; i < x_size; i++)
	{
		delete[] cells[i];
	}

	delete[] cells;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
	if (this == &rhs) return (*this);

	for (int i = 0; i < x_size; i++)
	{
		delete[] cells[i];
	}

	delete cells;

	// We can read the x_size directly because we are in a method of Matrix
	// and the type of rhs is Matrix too even though the x_size is private.
	cells = new T*[rhs.x_size];
	for (int i = 0; i < rhs.x_size; i++)
	{
		cells[i] = new T[rhs.y_size];
		memset (cells[i], 0, (rhs.y_size * sizeof (T)));
	}

	for (int i = 0; i < rhs.x_size; i++)
	{
		for (int j = 0; j < rhs.y_size; j++)
		{
			cells[i][j] = rhs.cells[i][j];
		}
	}

	return *this;
}

template <typename E>
ostream& operator<< (ostream& ostr, const Matrix<E>& mtx) {
	
	for (int i = 0; i < mtx.x_size; i++)
	{
		for (int j = 0; j < mtx.y_size; j++)
		{
			ostr << mtx.cells[i][j] << ", ";
		}
		ostr << "\n";
	}
	ostr << "\n";
	return ostr;
}

template <typename E>
Matrix<E> operator* (const Matrix<E>& a, const Matrix<E>& b) {
	Matrix<E> result (a.x_size, b.y_size);

	for (int i = 0; i < a.x_size; i++)
	{
		for (int j = 0; j < a.x_size; j++)
		{
			for (int k = 0; k < a.x_size; k++)
			{
				result.cells[i][j] += (a.cells[k][j] * b.cells[i][k]);
			}
		}
	}

	return result;
}

template <typename T>
T Matrix<T>::get_element (int x, int y) const 
{
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::set_element (int x, int y, T elem)
{
	cells[x][y] = elem;
}

#endif