#include <stdio.h>
#include "testFunctions.h"

int main(void)
{
	const char* inFilNam 		= "input/in.txt";

	if(genSine(440, 48000, 128, inFilNam))
	{
		printf("error 0\n");
		return 1;
	}

	float out[128] 				= {0.};
	float outRef[128] 			= {0.};

	const char* outFilNam 		= "output/out.txt";
	const char* outRefFilNam 	= "output/outRef.txt";

	if(openOutFiles(out, outRef, outFilNam, outRefFilNam))
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
