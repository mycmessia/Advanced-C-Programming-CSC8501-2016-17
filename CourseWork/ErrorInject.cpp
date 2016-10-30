#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <fstream>
#include "ErrorInject.h"

using namespace std;

void ErrorInject::inject (string fileName) 
{
	fstream fin, fout;

	fin.open (fileName, iostream::in);
	fout.open ("error_" + fileName, iostream::out);

	char c;
	int n;

	bool bMode = false;
	int bmCounter = 0;
	
	srand ((unsigned) time(NULL));

	while (EOF != (c = fin.get ()))
	{
		n = c - '0';

		if (bMode)
		{
			int ran = rand () % 2;
			if (ran == 0)
			{
				n = 0;
			}
			else
			{
				n = 1;
			}

			bmCounter++;

			if (bmCounter > 4)
			{
				bMode = false;
				bmCounter = 0;
			}
		}
		else
		{
			int ran = rand () % 21;
			if (ran > 18)
			{
				bMode = true;
			}
		}

		fout << n;
	}

	fin.close ();
	fout.close ();
}