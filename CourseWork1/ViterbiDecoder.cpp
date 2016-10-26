#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "ViterbiDecoder.h"

using namespace std;

DecodeStep::DecodeStep () : hd (0)
{

}

DecodeStep::~DecodeStep ()
{

}

ViterbiDecoder::ViterbiDecoder ()
{
	statesDiagram = new StatesDiagram;

	statesDiagram->initFromFile ("diagram_output_gate1_01_gate2_23.txt");
}

ViterbiDecoder::~ViterbiDecoder ()
{
	delete statesDiagram;
}

void ViterbiDecoder::decode (string receivedFile)
{
	// !!!!!need to delete everything in vec manually
	vector< vector <DecodeStep*> > vec;

	fstream fin;
	fin.open (receivedFile, fstream::in);

	char c1, c2;
	int n1, n2;

	int stepCounter = 0;
	while (EOF != (c1 = fin.get ()) && EOF != (c2 = fin.get ()))
	{
		n1 = c1 - '0';
		n2 = c2 - '0';

		vec.push_back (vector <DecodeStep*> ());

		if (stepCounter == 0)
		{
			DecodeStep* ds0 = new DecodeStep;
			ds0->initState[0] = 0;
			ds0->initState[1] = 0;
			ds0->initState[2] = 0;
			ds0->input = 0;
			checkDiagramSet (ds0);
			calcHD (ds0, n1, n2);
			vec[stepCounter].push_back (ds0);

			DecodeStep* ds1 = new DecodeStep;
			ds1->initState[0] = 0;
			ds1->initState[1] = 0;
			ds1->initState[2] = 0;
			ds1->input = 1;
			checkDiagramSet (ds1);
			calcHD (ds1, n1, n2);
			vec[stepCounter].push_back (ds1);
		}
		else
		{
			// iterate last columon each one input 0 and 1
			for (unsigned int i = 0; i < vec[stepCounter - 1].size (); i++)
			{
				DecodeStep* ds0 = new DecodeStep;
				ds0->initState[0] = vec[stepCounter - 1][i]->finalState[0];
				ds0->initState[1] = vec[stepCounter - 1][i]->finalState[1];
				ds0->initState[2] = vec[stepCounter - 1][i]->finalState[2];
				ds0->input = 0;
				checkDiagramSet (ds0);
				calcHD (ds0, n1, n2);
				vec[stepCounter].push_back (ds0);

				DecodeStep* ds1 = new DecodeStep;
				ds1->initState[0] = vec[stepCounter - 1][i]->finalState[0];
				ds1->initState[1] = vec[stepCounter - 1][i]->finalState[1];
				ds1->initState[2] = vec[stepCounter - 1][i]->finalState[2];
				ds1->input = 1;
				checkDiagramSet (ds1);
				calcHD (ds1, n1, n2);
				vec[stepCounter].push_back (ds1);
			}
		}

		stepCounter++;
	}

	fin.close ();

	deque<int> path;

	int lastFinalStates[REGISTER_COUNT] = {0, 0, 0};

	bool isFirst = true;

	while (stepCounter > 0)
	{
		if (isFirst)
		{
			int smallestHD = vec[stepCounter - 1][0]->hd;
			int smallestIndex = 0;
			for (unsigned i = 0; i < vec[stepCounter - 1].size (); i++)
			{
				if (vec[stepCounter - 1][i]->hd < smallestHD)
				{
					smallestHD = vec[stepCounter - 1][i]->hd;
					smallestIndex = i;
				}
			}

			lastFinalStates[0] = vec[stepCounter - 1][smallestIndex]->initState[0];
			lastFinalStates[1] = vec[stepCounter - 1][smallestIndex]->initState[1];
			lastFinalStates[2] = vec[stepCounter - 1][smallestIndex]->initState[2];

			path.push_front (smallestIndex);

			isFirst = false;
		}
		else
		{
			// find the first valid
			int smallestHD = 0;
			int smallestIndex = 0;
			for (unsigned i = 0; i < vec[stepCounter - 1].size (); i++)
			{
				if (vec[stepCounter - 1][i]->finalState[0] == lastFinalStates[0] &&
					vec[stepCounter - 1][i]->finalState[1] == lastFinalStates[1] &&
					vec[stepCounter - 1][i]->finalState[2] == lastFinalStates[2])
				{
					smallestIndex = i;
					smallestHD = vec[stepCounter - 1][i]->hd;
				}
			}

			// find the smallest valid
			for (unsigned i = 0; i < vec[stepCounter - 1].size (); i++)
			{
				if (vec[stepCounter - 1][i]->finalState[0] == lastFinalStates[0] &&
					vec[stepCounter - 1][i]->finalState[1] == lastFinalStates[1] &&
					vec[stepCounter - 1][i]->finalState[2] == lastFinalStates[2])
				{
					if (vec[stepCounter - 1][i]->hd < smallestHD)
					{
						smallestIndex = i;
						smallestHD = vec[stepCounter - 1][i]->hd;
					}
				}
			}
			
			lastFinalStates[0] = vec[stepCounter - 1][smallestIndex]->initState[0];
			lastFinalStates[1] = vec[stepCounter - 1][smallestIndex]->initState[1];
			lastFinalStates[2] = vec[stepCounter - 1][smallestIndex]->initState[2];

			path.push_front (smallestIndex);
		}

		stepCounter--;
	}

	//for (unsigned i = 0; i < path.size (); i++)
	//{
	//	cout << path[i];
	//}
	//cout << endl;

	for (unsigned i = 0; i < vec.size (); i++)
	{
		cout << vec[i][path[i]]->input;
	}
	cout << endl;

	for (unsigned i = 0; i < vec.size (); i++)
	{
		for (unsigned j = 0; j < vec[i].size (); j++)
		{
			delete vec[i][j];
			vec[i][j] = nullptr;
		}
	}
}

void ViterbiDecoder::calcHD (DecodeStep* ds, int receviedN1, int receivedN2)
{
	if (ds->output[0] != receviedN1)
	{
		ds->hd += 1;
	}

	if (ds->output[1] != receivedN2)
	{
		ds->hd += 1;
	}
}

void ViterbiDecoder::checkDiagramSet (DecodeStep* ds)
{
	for (int i = 0; i < REGISTER_STATES_LENGTH; i++)
	{
		if (statesDiagram->matrix[i][0] == ds->input &&
			statesDiagram->matrix[i][1] == ds->initState[0] &&
			statesDiagram->matrix[i][2] == ds->initState[1] &&
			statesDiagram->matrix[i][3] == ds->initState[2])
		{
			ds->output[0] = statesDiagram->matrix[i][7];
			ds->output[1] = statesDiagram->matrix[i][8];

			ds->finalState[0] = statesDiagram->matrix[i][4];
			ds->finalState[1] = statesDiagram->matrix[i][5];
			ds->finalState[2] = statesDiagram->matrix[i][6];
		}
	}
}