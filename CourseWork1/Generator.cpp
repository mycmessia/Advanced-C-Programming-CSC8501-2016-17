#include <vector>
#include "Encoder.h"
#include "Generator.h"

using namespace std;

int Generator::getEncoderCount ()
{
	return encoderCount;
}

void Generator::popFromBack (vector<int> &v, int n)
{
	for (int i = 0; i < n; i++)
		v.pop_back ();
}

bool Generator::isObeyConstraints (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec)
{
	bool isReadInput = false;
	bool isReadReg1 = false;
	bool isReadReg2 = false;
	bool isReadReg3 = false;

	for (unsigned i = 0; i < gate1_chosen_vec.size (); i++)
	{
		if (gate1_chosen_vec[i] == READ_FROM_INPUT)
		{
			isReadInput = true;
		}
		else if (gate1_chosen_vec[i] == READ_FROM_REG1)
		{
			isReadReg1 = true;
		}
		else if (gate1_chosen_vec[i] == READ_FROM_REG2)
		{
			isReadReg2 = true;
		}
		else if (gate1_chosen_vec[i] == READ_FROM_REG3)
		{
			isReadReg3 = true;
		}
	}

	for (unsigned i = 0; i < gate2_chosen_vec.size (); i++)
	{
		if (gate2_chosen_vec[i] == READ_FROM_INPUT)
		{
			isReadInput = true;
		}
		else if (gate2_chosen_vec[i] == READ_FROM_REG1)
		{
			isReadReg1 = true;
		}
		else if (gate2_chosen_vec[i] == READ_FROM_REG2)
		{
			isReadReg2 = true;
		}
		else if (gate2_chosen_vec[i] == READ_FROM_REG3)
		{
			isReadReg3 = true;
		}
	}

	if (isReadInput && isReadReg1 && isReadReg2 && isReadReg3)
	{
		return true;
	}

	return false;
}

void Generator::doEncoding (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec)
{
	string inputFile = "input.txt";

	if (isObeyConstraints (gate1_chosen_vec, gate2_chosen_vec))
	{
		cout << "gate1_";
		for (unsigned i = 0; i < gate1_chosen_vec.size (); i++)
		{
			cout << gate1_chosen_vec[i];
		}
		
		cout << "_gate2_";
		for (unsigned i = 0; i < gate2_chosen_vec.size (); i++)
		{
			cout << gate2_chosen_vec[i];
		}
		cout << endl;

		encoderCount++;

		Encoder encoder (gate1_chosen_vec, gate2_chosen_vec);
		encoder.encode (inputFile);
	}
	else
	{
		//cout << "gate1_";
		//for (unsigned i = 0; i < gate1_chosen_vec.size (); i++)
		//{
		//	cout << gate1_chosen_vec[i];
		//}
		//
		//cout << "_gate2_";
		//for (unsigned i = 0; i < gate2_chosen_vec.size (); i++)
		//{
		//	cout << gate2_chosen_vec[i];
		//}
		//cout << endl;
	}
}

void Generator::generateEncoder ()
{	
	// ----------------------------------------------------------------------
	// gate1 take the input
	// ----------------------------------------------------------------------
	gate1_chosen_vec.push_back (READ_FROM_INPUT);

	// gate1 take another 1 from reg
	for (int j = 1; j < 4; j++)
	{
		gate1_chosen_vec.push_back (j);

		// gate2 take 2 from reg
		for (int k = 1; k < 4; k++)
		{
			for (int l = 1; l < 4; l++)
			{
				if (l != k)
				{
					gate2_chosen_vec.push_back (l);
				}
			}

			doEncoding (gate1_chosen_vec, gate2_chosen_vec);

			popFromBack (gate2_chosen_vec, 2);
		}

		// gate2 take 3 from reg
		for (int k = 1; k < 4; k++)
		{
			gate2_chosen_vec.push_back (k);
		}

		doEncoding (gate1_chosen_vec, gate2_chosen_vec);

		popFromBack (gate2_chosen_vec, 3);

		gate1_chosen_vec.pop_back ();
	}
}