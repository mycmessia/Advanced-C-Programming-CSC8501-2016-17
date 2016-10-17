#include "Encoder.h"
#include "CompareEncoderOutput.h"

int main ()
{
	//CompareEncoderOutput ceo;
	//bool res = ceo.compare ("output0.txt", "output1.txt");
	//cout << res << endl;

	int id = 0;
	char c = 'y';

	while (1)
	{
		cout << "Enter a number to choose a encoder permutaion (0-5):" << endl;
		cin >> id;
		cin.clear ();
		cin.ignore (1000, '\n');	// discard 1000 characters until next line

		if (id < 0 || id > 5) id = 0;

		Encoder encoder (id);
		string outputFile = "output" + to_string(id) + ".txt";

		ofstream outfile (outputFile);
		outfile.close();

		encoder.encode ("input.txt", outputFile);

		cout << "Encoding with encoder " << id << " has finished." << endl;
		cout << "Check the output in file " << outputFile << endl;

		cout << "Do you need another encoding (y/n)" << endl;
		cin >> c;

		if (c != 'y') break;
	}

	system ("pause");
	return 0;
}