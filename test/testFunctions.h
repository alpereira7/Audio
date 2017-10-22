#ifndef TEST_TESTFUNCTIONS_H
#define TEST_TESTFUNCTIONS_H

#include <math.h>
#include "stdio.h"
#include "globalDefs.h"

int genSine(float f, float fs, int length, const char* inFilNam);

int openOutFiles(	float* out1,
					float* out2,
					const char* outFilNam1,
					const char* outFilNam2);

float compareOutputs(	float* out,
						float* outRef,
						const unsigned int length);

#endif // TEST_TESTFUNCTIONS_H
