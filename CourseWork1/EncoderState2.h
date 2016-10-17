#pragma once
#ifndef _ENCODER_STATE_2_
#define _ENCODER_STATE_2_

#include "EncoderState.h"

using namespace std;

class EncoderState2 : public EncoderState {
	virtual void encode (string inputFile, string outputFile);
};

#endif