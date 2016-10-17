#include <iostream>

using namespace std;

class Base {
public:
	// This virutal can make sure we delete a Base pointer
	// the ~Derived and ~DerivedAgain will all be called.
	virtual ~Base () {
		cout << "~Base called" << endl;
	};

	void func ()
	{
		Base b;	
	}
};

class Derived : public Base {
public:
	~Derived () {
		cout << "~Derived called" << endl;
	};
};

class DerivedAgain : public Derived {
public:
	~DerivedAgain () {
		cout << "~DerivedAgain called" << endl;
	}
};

int main ()
{
	Base* p = new DerivedAgain;
	// ~DerivedAgain called
	// ~Derived called
	// ~Base called
	delete p;

	system ("pause");
	return 0;
}
