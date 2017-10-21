#include <stdio.h>
#include "testFunctions.h"

int main(void)
{
	float out[128] 				= {0.};
	float outRef[128] 			= {0.};

	const char* outFileName 	= "output/out.txt";
	const char* outRefFileName 	= "output/outRef.txt";

	if(openOutputFiles(out, outRef, outFileName, outRefFileName))
	{
		printf("error 1\n");
		return 1;
	}

	if(compareOutputs(out, outRef, 128))
	{
		printf("test failed\n");
		return 1;
	}

	printf("OK\n");

	return 0;
}
