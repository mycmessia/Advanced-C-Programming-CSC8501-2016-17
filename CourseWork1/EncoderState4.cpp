#include "Encoder.h"
#include "EncoderState4.h"
#include <fstream>

void EncoderState4::encode (string inputFile, string outputFile)
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
		
		fout << Encoder::XORGate (registers[0], registers[2]);
		fout << Encoder::XORGate (n, registers[1]);

		Encoder::shiftRegisters (registers, n);
	}

	fin.close ();
	fout.close ();
}