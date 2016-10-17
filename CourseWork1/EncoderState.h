#pragma once
#ifndef _ENCODER_STATE_
#define _ENCODER_STATE_

#include <iostream>
#include <string>

using namespace std;

class EncoderState {
public:
	// All virtual methods must have their definitions include this.
	virtual void encode (string inputFile, string outputFile) {};

protected:
	int registers[3];
};

#endif