#pragma once
#ifndef _STATE_DIAGRAM_
#define _STATE_DIAGRAM_

#include "Register.h"

const int REGISTER_STATES_LENGTH = 16;

class StatesDiagram {
public:
	StatesDiagram ();
	~StatesDiagram ();

	int matrix[REGISTER_STATES_LENGTH][9];

	void print ();
};

_STATE_DIAGRAM_

#endif