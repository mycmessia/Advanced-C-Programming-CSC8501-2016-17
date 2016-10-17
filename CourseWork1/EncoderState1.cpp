#include "Encoder.h"
#include "EncoderState1.h"
#include <fstream>

void EncoderState1::encode (string inputFile, string outputFile)
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

		fout << Encoder::XORGate (n, registers[1]);
		fout << Encoder::XORGate (registers[0], registers[2]);

		Encoder::shiftRegisters (registers, n);
	}

	fin.close ();
	fout.close ();
}