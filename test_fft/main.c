#include <stdio.h>
#include <filter.h>
#include "../global/testFunctions.h"
#include "testDefs.h"

complex_float pm twiddle_table[FRAME_SIZE];

int main(void)
{
    int i;
	const char* inFilNam 		= INPUT_FILE_NAME;
	float in[FRAME_SIZE];
	float out[FRAME_SIZE];

	float inZP[2*FRAME_SIZE] = {0};
	complex_float inFFT[2*FRAME_SIZE];
	complex_float outFFT[2*FRAME_SIZE];
	
	twidfft (twiddle_table,2*FRAME_SIZE);

	// Generate sine
	if(genSine(440, 48000, FRAME_SIZE, inFilNam, in))
	{
		printf("error 0\n");
		return 1;
	}
	
	// Zero-Pad
	for(i = 0; i < FRAME_SIZE; i++)
	{
	    inZP[i] = in[i];
	}
	
	// Real FFT
	rfft(inZP, inZP, inFFT, twiddle_table, 1, 2*FRAME_SIZE) ;

    // 2nd half of the spectrum
    for (i = 1; i < (FRAME_SIZE); i++)
    {
        inFFT[2*FRAME_SIZE - i] = conjf (inFFT[i]);
    }
    
    // Inverse FFT
    ifft(inFFT, inFFT, outFFT, twiddle_table, 1, 2*FRAME_SIZE);
 
    // Write output
    for (i = 0; i < FRAME_SIZE; i++)
    {
        out[i] = outFFT[i].re;
    }
    
	const char* outFilNam 		= OUTPUT_FILE_NAME;
	if(writeOutput(out, FRAME_SIZE, outFilNam))
	{
		printf("error 1\n");
		return 1;
	}

	float outRef[FRAME_SIZE];
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
