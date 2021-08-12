#ifndef TXTANIAMTION_H
#define TXTANIAMTION_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "common/common.h"

#include "include/fcheck/fcheck.h"
#include "include/clrscr/clrscr.h"
#include "include/sleep/sleep.h"

void run_animation(const char filename[]) {	// char[]
	txt__anim__main__data *main_data = new txt__anim__main__data;	// filename getting
	std::ifstream inFile;			// opening ifstream
	inFile.open(filename);
	is_open(inFile, filename, true);

	txt__anim__common__data *common_data = new txt__anim__common__data;

	strncpy(main_data->filename, filename, ta_temp_size);

	ta_read_header(inFile, main_data);	// getting data from header 

	char temp[main_data->block_size][ta_temp_size];	// temps
	char *rubbish = new char[ta_temp_size];
	unsigned short *count = new unsigned short;

	while (!inFile.eof()) {	// <core>
		for (*count = 0; *count < main_data->block_size; ++*count) {		// <core> getting data
			inFile.getline(temp[*count], ta_temp_size);
			ifstrm_status(inFile, main_data->filename, true, false, false);
		}
		clrscr();
		inFile.getline(rubbish, ta_temp_size);
		ifstrm_status(inFile, main_data->filename, true, false, false);
		for (*count = 0; *count < main_data->block_size; ++*count) {		// <core> printing data
			std::cout << temp[*count] << "\n";
		}
		sleep(main_data->delay);
	}


	delete main_data; 	// freeing memory
	delete common_data;
	delete [] rubbish;
	delete count;
//	delete [] temp;		// I will return to this asshole
}


#endif

// last edit: 28/07/021
// developed by Dolfost
