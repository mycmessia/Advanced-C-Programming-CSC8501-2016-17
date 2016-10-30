#include "XORGate.h"

int XORGate::calculate (vector<Register*>& v)
{
	Register temp;

	for (unsigned i = 0; i < v.size (); i++)
	{
		temp = temp ^ *v[i];
	}

	return temp.get_value ();
}

int XORGate::calculate (vector<Register*>& v, int input)
{
	Register temp;

	for (unsigned i = 0; i < v.size (); i++)
	{
		temp = temp ^ *v[i];
	}

	if (input == temp.get_value ())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}