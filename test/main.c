#include <stdio.h>
#include "testFunctions.h"
#include "testDefs.h"
#include "../volume/volume.h"

int main(void)
{
	const char* inFilNam 		= "input/in.txt";

	float in[FRAME_SIZE];

	// Generate sine
	if(genSine(440, 48000, FRAME_SIZE, inFilNam, in))
	{
		printf("error 0\n");
		return 1;
	}

	float out[FRAME_SIZE];
	float outRef[FRAME_SIZE];

	Volume VolumeInstance;
	float gain = 0.;
	float gain_ = -1000.;

	initVolume(&VolumeInstance, in, out, FRAME_SIZE);
	setVolume(&VolumeInstance, VOL_PARAM_GAIN, (unsigned int*)&gain);
	getVolume(&VolumeInstance, VOL_PARAM_GAIN, (unsigned int*)&gain_);
	printf("%f\n", gain_);

	processVolume(&VolumeInstance);

	const char* outFilNam 		= "output/out.txt";

	if(writeOutput(out, FRAME_SIZE, outFilNam))
	{
		printf("error 1\n");
		return 1;
	}

	const char* outRefFilNam 	= "output/outRef.txt";

	if(openOutFiles(out, outRef, outFilNam, outRefFilNam))
	{
		printf("error 1\n");
		return 1;
	}

	if(compareOutputs(out, outRef, FRAME_SIZE))
	{
		printf("test failed\n");
		return 1;
	}

	printf("OK\n");

	return 0;
}
