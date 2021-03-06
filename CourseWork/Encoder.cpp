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
	zeroRegisters ();

	for (unsigned i = 0; i < v1.size (); i++)
		gate1_vec.push_back (v1[i]);

	for (unsigned i = 0; i < v2.size (); i++)
		gate2_vec.push_back (v2[i]);

	gate1 = new XORGate;
	gate2 = new XORGate;

	stateDiagram = new StatesDiagram;

	fillStateDiagram ();
	
	zeroRegisters ();
}

Encoder::~Encoder ()
{
	delete gate1;
	delete gate2;

	delete stateDiagram;
}

void Encoder::encode (string inputFile)
{
	vector<Register*> reg_temp1;
	vector<Register*> reg_temp2;

	string outputFile = "encoder_output_";

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
			reg_temp1.push_back (&registers[0]);
		}
		else if (gate1_vec[i] == READ_FROM_REG2)
		{
			reg_temp1.push_back (&registers[1]);
		}
		else if (gate1_vec[i] == READ_FROM_REG3)
		{
			reg_temp1.push_back (&registers[2]);
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
			reg_temp2.push_back (&registers[0]);
		}
		else if (gate2_vec[i] == READ_FROM_REG2)
		{
			reg_temp2.push_back (&registers[1]);
		}
		else if (gate2_vec[i] == READ_FROM_REG3)
		{
			reg_temp2.push_back (&registers[2]);
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

	int gate2output, gate1output;

	while (EOF != (c = fin.get ()))
	{
		n = c - '0';

		// either gate1 or gate2 must read from the input file
		if (isGate2ReadFromInput)
		{
			gate2output = gate2->calculate (reg_temp2, n);
			fout <<	gate2output;
		}
		else
		{
			gate2output = gate2->calculate (reg_temp2);
			fout << gate2output;
		}

		if (isGate1ReadFromInput)
		{
			gate1output = gate1->calculate (reg_temp1, n);
			fout <<	gate1output;
		}
		else
		{
			gate1output = gate1->calculate (reg_temp1);
			fout <<	gate1output;
		}

		shiftRegisters (n);
	}

	fout.close ();
	fin.close ();
}

void Encoder::fillStateDiagram ()
{	
	string outputFile = "gate1_";
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

	fstream fin;

	fin.open ("generate_all_the_diagram_input.txt", fstream::in);

	int gate2output, gate1output;

	while (EOF != (c = fin.get ()))
	{
		n = c - '0';

		// either gate1 or gate2 must read from the input file
		if (isGate2ReadFromInput)
		{
			gate2output = gate2->calculate (reg_vec2, n);
		}
		else
		{
			gate2output = gate2->calculate (reg_vec2);
		}

		if (isGate1ReadFromInput)
		{
			gate1output = gate1->calculate (reg_vec1, n);
		}
		else
		{
			gate1output = gate1->calculate (reg_vec1);
		}

		for (int i = 0; i < REGISTER_STATES_LENGTH; i++)
		{
			if (n == stateDiagram->matrix[i][0] &&
				registers[0].get_value () == stateDiagram->matrix[i][1] &&
				registers[1].get_value () == stateDiagram->matrix[i][2] &&
				registers[2].get_value () == stateDiagram->matrix[i][3])
			{
				stateDiagram->matrix[i][7] = gate2output;
				stateDiagram->matrix[i][8] = gate1output;
			}
		}

		shiftRegisters (n);
	}

	fin.close ();

	stateDiagram->printToFile ("diagram_" + outputFile);
}

void Encoder::shiftRegisters (int input)
{
	for (int i = 2; i > 0; i--)
		registers[i] = registers [i - 1];

	registers[0] = input;
}

void Encoder::zeroRegisters ()
{
	for (int i = 0; i < REGISTER_COUNT; i++)
	{
		registers[i] = 0;
	}
}