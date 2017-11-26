#ifndef TEST_GLOBALDEFS_H
#define TEST_GLOBALDEFS_H

#ifndef NULL
	#define NULL 		0
#endif

#define PI 					3.14159265358979323846


typedef enum{
	NO_ERROR = 0,
	FILE_ERROR,
	NULL_POINTER_ERROR,
	PARAM_CODE_ERROR,
}Errors;


#endif // TEST_GLOBALDEFS_H
