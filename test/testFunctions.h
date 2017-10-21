#ifndef TEST_TESTFUNCTIONS_H
#define TEST_TESTFUNCTIONS_H

#include <math.h>
#include "stdio.h"

int openOutputFiles(float* out, float* outRef, const char* outFileName, const char* outRefFileName);
float 	compareOutputs(float* out, float* outRef, unsigned int length);




#endif // TEST_TESTFUNCTIONS_H
