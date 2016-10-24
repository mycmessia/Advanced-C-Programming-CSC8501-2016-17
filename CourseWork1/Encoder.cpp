#include <fstream>
#include <string>
#include "Encoder.h"

/***
 * gate1_vec 0 1 2 3
 * gate2_vec 0 1 2 3
 * 0 means read from input file, 1 means read from register1,
 * 2 means read from register2 and 3 means read from register3
 */
Encoder::Encoder (vector<int>& v1, vector<int>& v2)
{
	for (unsigned i = 0; i < 3; i++)
		registers[i] = 0;

	for (unsigned i = 0; i < v1.size (); i++)
		gate1_vec.push_back (v1[i]);

	for (unsigned i = 0; i < v2.size (); i++)
		gate2_vec.push_back (v2[i]);

	gate1 = new XORGate;
	gate2 = new XORGate;
}

Encoder::~Encoder ()
{
	delete gate1;
	delete gate2;
}

void Encoder::encode (string inputFile)
{
	string outputFile = "output_";

	outputFile += "gate1_";
	bool isGate1ReadFromInput = false;
	for (unsigned i = 0; i < gate1_vec.size (); i++)
	{
		if (gate1_vec[i] == READ_FROM_INPUT)
		{
			isGate1ReadFromInput = true;
		}
		else if (gate1_vec[i] == READ_FROM_REG1)
		{
			reg_vec1.push_back (&registers[0]);
		}
		else if (gate1_vec[i] == READ_FROM_REG2)
		{
			reg_vec1.push_back (&registers[1]);
		}
		else if (gate1_vec[i] == READ_FROM_REG3)
		{
			reg_vec1.push_back (&registers[2]);
		}

		outputFile += to_string (gate1_vec[i]);
	}

	outputFile += "_gate2_";
	bool isGate2ReadFromInput = false;
	for (unsigned i = 0; i < gate2_vec.size (); i++)
	{
		if (gate2_vec[i] == READ_FROM_INPUT)
		{
			isGate1ReadFromInput = true;
		}
		else if (gate2_vec[i] == READ_FROM_REG1)
		{
			reg_vec2.push_back (&registers[0]);
		}
		else if (gate2_vec[i] == READ_FROM_REG2)
		{
			reg_vec2.push_back (&registers[1]);
		}
		else if (gate2_vec[i] == READ_FROM_REG3)
		{
			reg_vec2.push_back (&registers[2]);
		}
		outputFile += to_string (gate2_vec[i]);
	}
	outputFile += ".txt";

	char c;
	int n;

	fstream fin, fout;

	// Make sure the inputFile is exist
	fin.open (inputFile, fstream::in);
	fout.open (outputFile, fstream::out);

	while (EOF != (c = fin.get ()))
	{
		n = c - '0';

		// either gate1 or gate2 must read from the input file
		if (isGate2ReadFromInput)
			fout <<	gate2->calculate (reg_vec2, n);
		else
			fout <<	gate2->calculate (reg_vec2);

		if (isGate1ReadFromInput)
			fout <<	gate1->calculate (reg_vec1, n);
		else
			fout <<	gate1->calculate (reg_vec1);

		shiftRegisters (n);
	}

	fout.close ();
	fin.close ();
}

void Encoder::shiftRegisters (int input)
{
	for (int i = 2; i > 0; i--)
		registers[i] = registers [i - 1];

	registers[0] = input;
}