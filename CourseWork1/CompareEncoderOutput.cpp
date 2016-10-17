#include "CompareEncoderOutput.h"
#include <fstream>

bool CompareEncoderOutput::compare (string file1, string file2) 
{
	char c1, c2;
	fstream fin1, fin2;

	fin1.open (file1, fstream::in);
	fin2.open (file2, fstream::in);

	while (EOF != (c1 = fin1.get ()) && EOF != (c2 = fin2.get ()))
	{
		if (c1 != c2)
			return false;
	}

	if (EOF != (c1 = fin1.get ()) && EOF == (c2 = fin2.get ()))
		return false;

	if (EOF == (c1 = fin1.get ()) && EOF != (c2 = fin2.get ()))
		return false;

	fin1.close ();
	fin2.close ();

	return true;
}