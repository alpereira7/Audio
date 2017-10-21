#include "testFunctions.h"

float compareOutputs(float* out, float* outRef, unsigned int length)
{
	float sum = 0.;

	int i;
	for(i = 0; i < length; i++)
	{
		sum += fabs(out[i]-outRef[i]);
	}

	return sum;
}



