#include <iostream>
#include "Register.h"
#include "XORGate.h"
#include "Generator.h"

using namespace std;

int main ()
{
	Generator ge;
	ge.generateEncoder ();

	system ("pause");
	return 0;
}