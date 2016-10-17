#include "Encoder.h"
#include "EncoderState.h"
#include "EncoderState0.h"
#include "EncoderState1.h"
#include "EncoderState2.h"
#include "EncoderState3.h"
#include "EncoderState4.h"
#include "EncoderState5.h"

Encoder::Encoder (int t) : type (t) {
	switch (type)
	{
	case 0:
		state = new EncoderState0;
		break;
	case 1:
		state = new EncoderState1;
		break;
	case 2:
		state = new EncoderState2;
		break;
	case 3:
		state = new EncoderState3;
		break;
	case 4:
		state = new EncoderState4;
		break;
	case 5:
		state = new EncoderState5;
		break;
	default:
		state = new EncoderState0;
		break;
	}
}

Encoder::~Encoder () {
	delete state;
};

int Encoder::XORGate (int n1, int n2)
{
	if (n1 == n2)
		return 0;

	return 1;
}

void Encoder::initRegisters (int arr[]) {
	for (int i = 0; i < REGISTERS_COUNT; i++)
	{
		arr[i] = 0;
	}
}

void Encoder::shiftRegisters (int arr[], int input) {
	for (int i = Encoder::REGISTERS_COUNT - 1; i > 0; i--)
	{
		arr[i] = arr[i - 1];
	}

	arr[0] = input;
}

void Encoder::printRegisters (int arr[]) {
	for (int i = 0; i < Encoder::REGISTERS_COUNT; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}

void Encoder::encode (string inputFile, string outputFile) {
	state->encode (inputFile, outputFile);
}