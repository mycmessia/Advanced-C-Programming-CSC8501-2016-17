#include <iostream>
#include "Register.h"
#include "XORGate.h"
#include "Generator.h"
#include "ViterbiDecoder.h"
#include "ErrorInject.h"
#include "CompareFile.h"

using namespace std;

int main ()
{
	cout << "Generate encoders will start" << endl;
	system ("pause");

	Generator ge;
	ge.generateEncoder ();
	cout << "The number of encoders is: " << ge.getEncoderCount () << endl;

	cout << "Enter the decoder you want to choose (like gate1_xx_gate2_xx):" << endl;
	string typeStr;
	cin >> typeStr;

	string diagram ("diagram_" + typeStr + ".txt");
	string encoder_output ("encoder_output_" + typeStr + ".txt");

	ViterbiDecoder vd (diagram);
	vd.decode (encoder_output);

	CompareFile cf;
	bool res = cf.compare ("input.txt", vd.outputFileName);
	if (res)
	{
		cout << "Decode successfully!" << endl;
	}
	else
	{
		cout << "Decoding failure." << endl;
	}
	
	cout << "Now inject errors into the encoder outputfile." << endl;

	ErrorInject ei;
	ei.inject ("encoder_output_" + typeStr + ".txt");

	cout << "Injected errors, try to decode again." << endl;
		
	string encoder_output_with_errors ("error_encoder_output_" + typeStr + ".txt");

	ViterbiDecoder vderror (diagram);
	vderror.decode (encoder_output_with_errors);

	res = cf.compare ("input.txt", vderror.outputFileName);
	if (res)
	{
		cout << "Decode successfully!" << endl;
	}
	else
	{
		cout << "Decoding failure." << endl;
	}

	system ("pause");
	return 0;
}