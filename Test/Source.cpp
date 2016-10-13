#include <ostream>
using namespace std;

template <typename T>
class Matrix {
public:
	static const int default_x = 3;
	static const int default_y = 3;

	Matrix (int x = default_x, int y = default_y);
	Matrix (const Matrix<T>& src);
	~Matrix ();

	Matrix<T>& operator=(const Matrix<T>& rhs);

	// These two functions below are not methods of class Matrix
	// so we change the typename to E and the reason why we put them
	// here is because they need to be friend with class Matrix so
	// these two functions can get access to the protected and private
	// members of Matrix.

	template <typename E> 
	friend ostream& operator<<(ostream& ostr, const Matrix<E>& mtx);
	
	//template <typename T>
	//Matrix<T> operator* (const Matrix<T>& a, const Matrix<T>& b);

	int get_x_size() const { return x_size; }
	int get_y_size() const { return y_size; }
	
	T get_element(int x, int y) const;
	void set_element(int x, int y, T elem);

private:
	T** cells;
	int x_size;
	int y_size;
};

//template <typename T>
//class foo {
//public:
//	template <typename E>
//	friend ostream& 
//
//};


auto main()->int {

	return 0;
}
