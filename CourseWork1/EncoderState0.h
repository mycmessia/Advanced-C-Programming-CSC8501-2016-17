#pragma once
#ifndef _ENCODER_STATE_0_
#define _ENCODER_STATE_0_

#include "EncoderState.h"

using namespace std;

class EncoderState0 : public EncoderState {
	virtual void encode (string inputFile, string outputFile);
};

#endif