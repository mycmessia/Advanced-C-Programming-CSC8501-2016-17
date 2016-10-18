#include "Encoder.h"
#include "CompareEncoderOutput.h"

int main ()
{
	//CompareEncoderOutput ceo;
	//bool res = ceo.compare ("output0.txt", "output1.txt");
	//cout << res << endl;

	int id = 0;
	char c = 'y';
	string inputFile;

	while (1)
	{
		cout << "Please Enter the input file name:" << endl;
		cin >> inputFile;
		cin.clear ();
		cin.ignore (1000, '\n');

		try 
		{
			ifstream fin;
			fin.open (inputFile);
			fin.close ();

			if (fin.fail ())
			{
				throw invalid_argument ("No input file exists " + inputFile + ".");
			}
			else
			{
				cout << "Please Enter a number to choose a encoder permutaion (0-5):" << endl;
				cin >> id;
				cin.clear ();
				cin.ignore (1000, '\n');	// discard 1000 characters until next line

				if (id < 0 || id > 5) id = 0;

				Encoder encoder (id);
				string outputFile = "output" + to_string(id) + ".txt";

				encoder.encode ("input.txt", outputFile);

				cout << "Encoding with encoder " << id << " has finished." << endl;
				cout << "Check the output in file " << outputFile << "." << endl;

				cout << "Do you need another encoding (y/n)?" << endl;
				cin >> c;

				if (c != 'y') break;
			}
		}
		catch (invalid_argument s)
		{
			cout << s.what () << endl;
		}
	}

	system ("pause");
	return 0;
}