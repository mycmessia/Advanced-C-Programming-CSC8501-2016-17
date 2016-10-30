#pragma once
#ifndef __VITERBI_DECODER__
#define __VITERBI_DECODER__

#include <string>
#include "StatesDiagram.h"

class DecodeStep {
public:
	DecodeStep ();
	~DecodeStep ();

	int initState[REGISTER_COUNT];
	int input;
	int output[2];
	int finalState[REGISTER_COUNT];
	int hd;
};

class ViterbiDecoder {
public:
	ViterbiDecoder (string& diagram);
	~ViterbiDecoder ();

	StatesDiagram* statesDiagram;

	void calcHD (DecodeStep* ds, int receviedN1, int receivedN2);
	void checkDiagramSet (DecodeStep* ds);
	void decode (string& receivedFile);

	string outputFileName;

private:
	DecodeStep* input0tree;
	DecodeStep* input1tree;
};

#endif