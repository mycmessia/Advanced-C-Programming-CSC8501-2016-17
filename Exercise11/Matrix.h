#pragma once
#ifndef _MATRIX_
#define _MATRIX_

template <typename T>
class Matrix {
public:
	static const int default_x = 3;
	static const int default_y = 3;
	Matrix (int x = default_x, int y = default_y);
	~Matrix ();
	int get_x_size () const { return x_size; }
	int get_y_size () const { return y_size; }
	T get_element (int x, int y) const;
	void set_element (int x, int y, T elem);

protected:
	T** cells;
	int x_size;
	int y_size;
};

#endif