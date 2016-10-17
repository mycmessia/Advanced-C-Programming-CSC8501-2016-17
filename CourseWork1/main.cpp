#include "Encoder.h"

int main ()
{
	int id = 0;
	char c = 'y';

	while (1)
	{
		cout << "Enter a number to choose a encoder permutaion: " << endl;
		cin >> id;

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