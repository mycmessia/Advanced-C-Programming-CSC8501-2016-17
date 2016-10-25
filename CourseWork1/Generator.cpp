#include <vector>
#include "Encoder.h"
#include "Generator.h"

using namespace std;

void Generator::popFromBack (vector<int> &v, int n)
{
	for (int i = 0; i < n; i++)
		v.pop_back ();
}

void Generator::doEncoding (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec)
{
	string inputFile = "input.txt";

	Encoder encoder (gate1_chosen_vec, gate2_chosen_vec);
	encoder.encode (inputFile);
}

void Generator::generateEncoder ()
{	
	// ----------------------------------------------------------------------
	// gate1 take the input
	// CAN NOT USE CLEAR WHEN WANT TO KEEP AT LEAST ONE
	// ----------------------------------------------------------------------
	gate1_chosen_vec.push_back (READ_FROM_INPUT);
	for (int i = 1; i < 4; i++)
	{
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

				// !!!!!!!!!!!!!!!!!!temp!!!!!!!!!!!!!!!!
				// delete this return when finished
				// !!!!!!!!!!!!!!!!!!temp!!!!!!!!!!!!!!!!
				return;

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

		// TODO
		// gate1 take another 2 from regs

		// gate1 take another 3 from regs
	}
}