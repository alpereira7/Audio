#include <stdio.h>
#include "testFunctions.h"
#include "testDefs.h"
#include "../volume/volume.h"

int main(void)
{
	const char* inFilNam 		= INPUT_FILE_NAME;

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
	float gain = -3.;
	float gain_ = -1000.;

	initVolume(&VolumeInstance, in, out, FRAME_SIZE);
	setVolume(&VolumeInstance, VOL_PARAM_GAIN, (unsigned int*)&gain);
	getVolume(&VolumeInstance, VOL_PARAM_GAIN, (unsigned int*)&gain_);
	printf("Gain is %f dB.\n", gain_);

	processVolume(&VolumeInstance);

	const char* outFilNam 		= OUTPUT_FILE_NAME;

	if(writeOutput(out, FRAME_SIZE, outFilNam))
	{
		printf("error 1\n");
		return 1;
	}

	const char* outRefFilNam 	= OUTPUT_REF_FILE_NAME;

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
