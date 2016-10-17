#pragma once
#ifndef _ENCODER_
#define _ENCODER_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class EncoderState;

class Encoder {
public:
	Encoder (int t);
	~Encoder ();

	static const int REGISTERS_COUNT = 3;
	static void initRegisters (int arr[]);
	static void shiftRegisters (int arr[], int input);
	static void printRegisters (int arr[]);

	static int XORGate (int n1, int n2);

	// read input from a file and output to another file
	void encode (string inputFile, string outputFile);

private:
	EncoderState* state;

	int type;
};

#endif