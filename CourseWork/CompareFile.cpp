#include <iostream>
#include <fstream>
#include "CompareFile.h"

using namespace std;

bool CompareFile:: fexists (const string& filename)
{
	ifstream ifile (filename.c_str ());
	return (bool) ifile;
}

bool CompareFile::compare (const string& file1, const string& file2)
{
	char c1, c2;
	fstream fin1, fin2;

	if (fexists (file1) && fexists (file2))
	{
		fin1.open (file1, fstream::in);
		fin2.open (file2, fstream::in);

		while (fin1.good () && fin2.good ())
		{
			c1 = fin1.get ();
			c2 = fin2.get ();

			if (c1 != c2)
			{
				fin1.close ();
				fin2.close ();
				return false;
			}
		}

		if (fin1.good () == fin2.good ())
		{				
			fin1.close ();
			fin2.close ();
			return true;
		}

		fin1.close ();
		fin2.close ();
		return false;
	}
	else
	{
		cout << "Can not compare " << file1 + " with " << file2 << " cause they may not all exist." << endl;
		return false;
	}
}