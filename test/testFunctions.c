#include "testFunctions.h"

int openOutputFiles(float* out, float* outRef, const char* outFileName, const char* outRefFileName)
{
	FILE* outRefFile 	= fopen(outRefFileName, "r");

	if (outRefFile == NULL)
		return 1;

	FILE* outFile 		= fopen(outFileName, "r");

	if (outFile == NULL)
		return 1;

	int i;
	float value;

	i = 0;
	while(fscanf(outRefFile, "%f,", &value) > 0)
	{
		outRef[i] = value;
		i++;
	}

	i = 0;
	while(fscanf(outFile, "%f,", &value) > 0)
	{
		out[i] = value;
		i++;
	}

	return 0;
}

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


