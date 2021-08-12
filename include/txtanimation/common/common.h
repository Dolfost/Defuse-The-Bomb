#ifndef TXTANIMATION_COMMON_H
#define TXTANIMATION_COMMON_H

#include <iostream>
#include <fstream>

#include "../include/fcheck/fcheck.h"

#define ta_temp_size 4096 // maximum template size;

struct txt__anim__common__data {
	const unsigned short header_size = 1;
};

struct txt__anim__main__data {
	char filename[ta_temp_size];
	float delay = 0;
	unsigned short block_size = 0;
};

// <core> header reading
bool ta_read_header(std::ifstream& inFile, txt__anim__main__data *main_data) { 
	bool badflag = false;
	char *rubbish = new char[ta_temp_size];

	inFile >> main_data->delay;

	if (!ifstrm_status(inFile, main_data->filename, false, true, true))
		badflag = true;

	inFile >> main_data->block_size;
	if (!ifstrm_status(inFile, main_data->filename, false, true, true))
		badflag = true;

	inFile.getline(rubbish, ta_temp_size);
	inFile.getline(rubbish, ta_temp_size);

	delete [] rubbish;

	if (!ifstrm_status(inFile, main_data->filename, false, true, true))
		badflag = true;
	
	if (badflag)
		return false;
	return true;
}

#endif

// last edit: 22/07/21
// developed by Dolfost
