#ifndef VOLUME_H
#define VOLUME_H

typedef struct VolumeParam_{
	float 		vol_dB;
} VolumeParam;

typedef struct VolumeState_{
	float 		vol_lin;
} VolumeState;

typedef struct Volume_{
	float* 			pIn;
	float* 			pOut;
	unsigned int 	nbSamples;

	VolumeParam		param;
	VolumeState 	state;

} Volume;

#endif // VOLUME_H


