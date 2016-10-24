#pragma once
#ifndef _GENERATOR_
#define _GENERATOR_

#include <vector>

using namespace std;

class Generator {
public:
	void generateEncoder ();

private:
	vector<int> gate1_chosen_vec;
	vector<int> gate2_chosen_vec;

	void doEncoding (vector<int>& gate1_chosen_vec, vector<int>& gate2_chosen_vec);

	void popFromBack (vector<int> &v, int n);
};

#endif