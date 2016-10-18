#include <iostream>

using namespace std;

class A {
public:
	A () : a1 (0), a2 (0) {
		cout << "default ctor" << endl;
	}
	A (A &a) {
		cout << "copy ctor" << endl;
		a1 = a.a1;
		a2 = a.a2;
	}
	int a1, a2;
};


int main ()
{
	A myA;
	myA.a1 = 10;
	myA.a2 = 20;

	A anotherA = myA;

	cout << anotherA.a1 << anotherA.a2 << endl;

	system ("pause");
	return 0;
}