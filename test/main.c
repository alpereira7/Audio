//#include <stdlib.h>
#include <stdio.h>
#include "testFunctions.h"

int main(void)
{
	FILE* outRefFile 	= fopen("output/outRef.txt", "r");

	if (outRefFile == NULL)
		printf("Error ! ");

	FILE* outFile 		= fopen("output/out.txt", "r");

	if (outFile == NULL)
		printf("Error ! ");

	float outRef[128] = {0.};
	float out[128] = {0.};
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

	if(compareOutputs(out, outRef, 128))
	{
		printf("test failed\n");
	}
	else
	{
		printf("OK\n");
	}

	return 0;
}
