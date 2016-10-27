#include <iostream>
#include "Register.h"
#include "XORGate.h"
#include "Generator.h"
#include "ViterbiDecoder.h"

using namespace std;

int main ()
{
	Generator ge;
	ge.generateEncoder ();

	ViterbiDecoder vd;
	vd.decode ("output_gate1_01_gate2_23.txt");

	system ("pause");
	return 0;
}