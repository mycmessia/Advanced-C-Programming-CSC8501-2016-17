#pragma once
#ifndef _XORGATE_
#define _XORGATE_

#include <vector>
#include "Register.h"

class XORGate {
public:
	int calculate (vector<Register*>& v);
	int calculate (vector<Register*>& v, int input);
};

#endif