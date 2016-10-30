#include "StatesDiagram.h"

#include <iostream>
#include <fstream>

using namespace std;

StatesDiagram::StatesDiagram () : matrix {
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{1, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 1, 0, 0, 0},
		{1, 1, 0, 0, 1, 1, 0, 0, 0},

		{0, 0, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 0, 1, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0},
		{1, 0, 0, 1, 1, 0, 0, 0, 0},

		{0, 0, 1, 1, 0, 0, 1, 0, 0},
		{1, 0, 1, 1, 1, 0, 1, 0, 0},
		{0, 1, 0, 1, 0, 1, 0, 0, 0},
		{1, 1, 0, 1, 1, 1, 0, 0, 0},

		{0, 1, 1, 0, 0, 1, 1, 0, 0},
		{1, 1, 1, 0, 1, 1, 1, 0, 0},
		{0, 1, 1, 1, 0, 1, 1, 0, 0},
		{1, 1, 1, 1, 1, 1, 1, 0, 0}
	} 
{}

StatesDiagram::~StatesDiagram ()
{
	
}

void StatesDiagram::initFromFile (string fileName)
{
	fstream fin;
	fin.open (fileName, fstream::in);

	string str;
	char c;
	int n;
	int i = 0;

	while (getline (fin, str))
	{
		c = str.at (7);
		n = c - '0';
		matrix[i][7] = n;

		c = str.at (8);
		n = c - '0';
		matrix[i][8] = n;

		i++;
	}
}

void StatesDiagram::printToFile (string fileName)
{
	fstream fout;
	
	fout.open (fileName, fstream::out);

	for (int i = 0; i < REGISTER_STATES_LENGTH; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			fout << matrix[i][j];
		}
		fout << endl;
	}

	fout.close ();
}