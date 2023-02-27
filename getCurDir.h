#pragma once

#include <stdio.h>  /* defines FILENAME_MAX */
#include <string>


#ifdef WIN32
	#include <direct.h>
	#define GetCurrentDir _getcwd
#else
	#include <unistd.h>
	#define GetCurrentDir getcwd
#endif


inline std::string getCurrentDir()
{
	char cCurrentPath[FILENAME_MAX];

	if (!GetCurrentDir(cCurrentPath, sizeof(cCurrentPath))) throw "can't getCurrentDir";

	return cCurrentPath;

}

