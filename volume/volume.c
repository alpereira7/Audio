/*
 * volume.c
 *
 *      Author: Alberto Pereira
 */

#include <math.h>
#include <stdio.h>
#include "volume.h"
#include "../global/globalDefs.h"

int initVolume(	Volume *pVolume,
				float *pIn,
				float *pOut,
				const unsigned int nbSamples)
{
	if(pVolume == NULL) 		return NULL_POINTER_ERROR;
	if(pIn == NULL) 			return NULL_POINTER_ERROR;
	if(pOut == NULL) 			return NULL_POINTER_ERROR;

	pVolume->pIn 				= pIn;
	pVolume->pOut 				= pOut;
	pVolume->nbSamples 			= nbSamples;

	pVolume->param.gain_dB 		= VOL_INIT_GAIN_DB;

	pVolume->state.gain_lin 	= VOL_INIT_GAIN_LIN;

	return NO_ERROR;
}

int setVolume(Volume* pVolume, unsigned int paramCode, unsigned int* paramValue)
{
	switch(paramCode)
	{
		case(VOL_PARAM_GAIN):
			pVolume->param.gain_dB = *(float*)paramValue;
			pVolume->state.gain_lin = pow(10.,pVolume->param.gain_dB/20.);
			break;

		default:
			return PARAM_CODE_ERROR;
	}

	return NO_ERROR;
}

int getVolume(Volume* pVolume, unsigned int paramCode, unsigned int* paramValue)
{
	switch(paramCode)
	{
		case(VOL_PARAM_GAIN):
			*(float*)paramValue = 20*log10(pVolume->state.gain_lin);
			break;

		default:
			return PARAM_CODE_ERROR;
	}

	return NO_ERROR;
}
int processVolume(Volume* pVolume)
{
	float *pIn 		= pVolume->pIn;
	float *pOut 	= pVolume->pOut;
	float nbSamples = pVolume->nbSamples;

	float gain_lin 	= pVolume->state.gain_lin;

	int i;
	for(i = 0; i < nbSamples; i++)
	{
		*pOut++ = gain_lin * (*pIn++);
	}

	return NO_ERROR;
}
