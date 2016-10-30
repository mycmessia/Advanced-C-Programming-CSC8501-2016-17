#pragma once
#ifndef _GENERATOR_
#define _GENERATOR_

#include <vector>

using namespace std;

class Generator {
public:
	Generator () : encoderCount (0) {};
	~Generator () {};
	void generateEncoder ();
	int getEncoderCount ();

private:
	int encoderCount;

	vector<int> gate1_chosen_vec;
	vector<int> gate2_chosen_vec;

	bool isObeyConstraints (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec);
	void doEncoding (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec);

	void popFromBack (vector<int> &v, int n);
};

#endif