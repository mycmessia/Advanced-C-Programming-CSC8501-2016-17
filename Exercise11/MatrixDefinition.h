#include "stdafx.h"
#include "Matrix.h"
#include <iostream>

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
T Matrix<T>::get_element (int x, int y) const 
{
	return (cells[x][y]);
}

template <typename T>
void Matrix<T>::set_element (int x, int y, T elem)
{
	cells[x][y] = elem;
}