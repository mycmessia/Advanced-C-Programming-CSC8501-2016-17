#pragma once
#ifndef _ENC0DER_
#define _ENCODER_

#include <vector>
#include "Register.h"
#include "XORGate.h"
#include "StatesDiagram.h"

enum {
	READ_FROM_INPUT,
	READ_FROM_REG1,
	READ_FROM_REG2,
	READ_FROM_REG3
};

class Encoder {
public:
	Encoder () {}
	Encoder (vector<int>& v1, vector<int>& v2);
	~Encoder ();

	void encode (string inputFile);

private:
	Register registers[3];

	StatesDiagram* stateDiagram;

	XORGate* gate1;
	XORGate* gate2;

	vector<int> gate1_vec;
	vector<int> gate2_vec;

	vector<Register*> reg_vec1;
	vector<Register*> reg_vec2;

	void shiftRegisters (int input);
};

#endif _ENCODER_