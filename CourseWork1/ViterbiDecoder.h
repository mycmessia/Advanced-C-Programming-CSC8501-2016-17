#pragma once
#ifndef __VITERBI_DECODER__
#define __VITERBI_DECODER__

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
	ViterbiDecoder ();
	~ViterbiDecoder ();

	StatesDiagram* statesDiagram;

	void calcHD (DecodeStep* ds, int receviedN1, int receivedN2);
	void setOutputFinalStateByDiagram (DecodeStep* ds);
	void decode (string receivedFile);

private:
	DecodeStep* input0tree;
	DecodeStep* input1tree;
};

#endif