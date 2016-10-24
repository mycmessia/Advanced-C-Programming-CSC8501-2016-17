#include "Register.h"

using namespace std;

Register Register::operator+ (const Register& r)
{
	Register newR;

	if (value == r.value)
		newR.value = 0;
	else
		newR.value = 1;

	return newR;
}

ostream& operator<< (ostream& ostr, const Register& r)
{
	ostr << r.value;

	return ostr;
}