#pragma once
#ifndef _ENCODER_STATE_1_
#define _ENCODER_STATE_1_

#include "EncoderState.h"

using namespace std;

class EncoderState1 : public EncoderState {
	virtual void encode (string inputFile, string outputFile);
};

#endif
