#include "Encoder.h"
#include "EncoderState5.h"
#include <fstream>

void EncoderState5::encode (string inputFile, string outputFile)
{
	Encoder::initRegisters (registers);
	
	char c;
	int n;

	fstream fin, fout;
	fin.open (inputFile, fstream::in);
	fout.open (outputFile, fstream::out);

	while (EOF != (c = fin.get ()))
	{
		n = c - '0';
		
		fout << Encoder::XORGate (registers[0], registers[1]);
		fout << Encoder::XORGate (n, registers[2]);

		Encoder::shiftRegisters (registers, n);
	}

	fin.close ();
	fout.close ();
}