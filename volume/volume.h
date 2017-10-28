/*
 * volume.h
 *
 *      Author: Alberto Pereira
 */

#ifndef VOLUME_H
#define VOLUME_H

#define VOL_INIT_GAIN_DB 		0.
#define VOL_INIT_GAIN_LIN 		1.

typedef enum {
	VOL_PARAM_GAIN 		= 0,
	VOL_PARAM_N
} VolParamCode;

typedef struct VolumeParam_{
	float 			gain_dB;
} VolumeParam;

typedef struct VolumeState_{
	float 			gain_lin;
} VolumeState;

typedef struct Volume_{
	float 			*pIn;
	float			*pOut;
	unsigned int 	nbSamples;

	VolumeParam		param;
	VolumeState 	state;
} Volume;

int initVolume(	Volume *pVolumeInstance,
				float *pIn,
				float *pOut,
				const unsigned int nbSamples);

int processVolume(Volume* pVolumeInstance);

int getVolume(	Volume* pVolume,
				unsigned int paramCode,
				unsigned int *paramValue);

int setVolume(	Volume* pVolume,
				unsigned int paramCode,
				unsigned int *paramValue);

#endif // VOLUME_H
