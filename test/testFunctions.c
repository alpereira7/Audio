#include "testFunctions.h"

int genSine(float f, float fs, int length, const char* inFilNam)
{
	FILE* inFile = fopen(inFilNam, "w");
	if (inFile == NULL) 						return FILE_ERROR;

	float in[length];
	int i;
	for(i = 0; i < length; i++)
	{
		in[i] = sin(2.*PI*f*(float)i/fs);
		fprintf(inFile, "%f,\n", in[i]);
	}

	return NO_ERROR;
}

int openOutFiles(	float* out1,
					float* out2,
					const char* outFilNam1,
					const char* outFilNam2)
{
	FILE* outFile1 	= fopen(outFilNam1, "r");
	if (outFile1 == NULL) 						return FILE_ERROR;

	FILE* outFile2 	= fopen(outFilNam2, "r");
	if (outFile2 == NULL) 						return FILE_ERROR;

	int i;
	float value;
	i = 0;
	while(fscanf(outFile1, "%f,", &value) > 0)
	{
		out1[i++] = value;
	}

	i = 0;
	while(fscanf(outFile2, "%f,", &value) > 0)
	{
		out2[i++] = value;
	}

	return NO_ERROR;
}

float compareOutputs(float* out, float* outRef, const unsigned int length)
{
	float sum = 0.;

	int i;
	for(i = 0; i < length; i++)
	{
		sum += fabs(out[i]-outRef[i]);
	}

	return sum;
}


