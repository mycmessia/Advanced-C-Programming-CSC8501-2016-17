#pragma once
#ifndef _COMPARE_ENCODER_OUTPUT_
#define _COMPARE_ENCODER_OUTPUT_

#include <string>

using namespace std;

class CompareEncoderOutput {
public:
	CompareEncoderOutput () {};
	~CompareEncoderOutput () {};
	bool compare (string file1, string file2);
};

#endif