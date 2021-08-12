#ifndef TXTANIAMTION_PARSER_H
#define TXTANIAMTION_PARSER_H

#include <iostream>
#include <fstream>
#include <cstring>

#include "common/common.h"
#include "txtanimation.h"

#include "include/fcheck/fcheck.h"
#include "include/clrscr/clrscr.h"

struct txt__anim__parser__data {
	char version[11] = "1.0-stable";

	unsigned long lines = 0;
	unsigned int blocks = 0;
	unsigned int expected_blocks = 0;
	unsigned long current_line = 0;
};

// lines counting
unsigned long ta_count_lines(char filename[]) {
	std::ifstream inFile;
	inFile.open(filename);
	is_open(inFile, filename, true);

	char *rubbish = new char[ta_temp_size];
	unsigned long count = 0;

	while (!inFile.eof()) {
		inFile.getline(rubbish, ta_temp_size);
		ifstrm_status(inFile, filename, true, false, false);
		++count;
	}

	--count;

	inFile.close();
	delete [] rubbish;

	return count;
}

void ta_parser_fatal_error_msg(void) {
	std::cout << "last error status:\tfatal\nAbort.\n";
	exit(EXIT_FAILURE);
}
// <debug> printing debug info
void ta_parser_info(txt__anim__common__data *common_data, txt__anim__main__data *main_data,
		    txt__anim__parser__data *parser_data, char temp[][ta_temp_size]) {
	std::cout << "\nInfo:"
		     "\nFilename:\t\t" << main_data->filename
		  << "\nDelay:\t\t\t" << main_data->delay
		  << "\nBlock size:\t\t" << main_data->block_size
		  << "\nBlocks expected:\t" << parser_data->expected_blocks
		  << "\nBlocks read:\t\t" << parser_data->blocks
		  << "\nLines read:\t\t" << parser_data->lines
		  << "\n\nLast memory cells content:\n";

	unsigned short *count = new unsigned short;
	for (*count = 0; *count < main_data->block_size; ++*count)	// <debug> printing all temp array
		std::cout << "temp[" << *count << "]:\t " << temp[*count] << "\n";
	delete count;
}

void run_animation_parser(char filename[]) {
	// allocating memory for parser data
	txt__anim__parser__data *parser_data = new txt__anim__parser__data; 
	
	// hello message
	std::cout << "TXT-animation Parser\nversion: " << parser_data->version
		  << "\n\nStarting...\n";

	// allocating memory for main data
	txt__anim__main__data *main_data = new txt__anim__main__data;
	
	// opeing parser ifstream
	std::ifstream inFile;
	inFile.open(filename);
	if (!is_open(inFile, filename, false))	// if could not open a file
		ta_parser_fatal_error_msg();    // prinf fatal error and exit
	
	// allocating memory for common data
	txt__anim__common__data *common_data = new txt__anim__common__data;
	
	// saving filename in main_data
	strncpy(main_data->filename, filename, ta_temp_size);

	// counting file lines
	parser_data->lines = ta_count_lines(main_data->filename); 

	// error check no header
	if (parser_data->lines == 0) {
		std::cout << "\nerror: file \"" << main_data->filename << "\" is empty.\n";
		ta_parser_fatal_error_msg(); }

	// getting data from header
	if (!ta_read_header(inFile, main_data)) {
		std::cout << "\nERROR: could not read header in file \"" << main_data->filename << "\".\n";
		ta_parser_fatal_error_msg(); } 
	
	// error check too small file
	if (parser_data->lines < (main_data->block_size + common_data->header_size + 1)) {
		std::cout << "\nERROR: the number of lines in file \"" << main_data->filename
			  << "\"\ncannot contain even one block of the size specified in the header.\n"
			     "\nInfo:\n"
			     "Lines:\t\t\t" << parser_data->lines
			  << "\nBlock size:\t\t" << main_data->block_size
			  << "\nHeader size <const>:\t" << common_data->header_size
			  << "\n";
		ta_parser_fatal_error_msg(); }
	
	std::cout << "Assuming the possible number of blocks...\n";
	parser_data->expected_blocks = // make expectations
	((parser_data->lines - common_data->header_size) / (main_data->block_size + 1));

	std::cout << "Running file \"" << main_data->filename << "\"... <"
		  << main_data->delay << "/" << main_data->block_size << ">\n";

	char temp[main_data->block_size][ta_temp_size];	// temps
	char *rubbish = new char[ta_temp_size];
	unsigned short *count = new unsigned short;

	// skipping the header in current_line
	parser_data->current_line += common_data->header_size + 1;
	while (!inFile.eof()) {	// <core>
		for (*count = 0; *count < main_data->block_size; ++*count) {
			++parser_data->current_line;	// counting current line

			if (parser_data->current_line > parser_data->lines)
				--parser_data->current_line;

			std::cout << "reading the line: " << parser_data->current_line << "/"
				  << parser_data->lines << "\r";

			inFile.getline(temp[*count], ta_temp_size);
			if (!ifstrm_status(inFile, main_data->filename, false, false, false))
				ta_parser_fatal_error_msg();
		}
		// counting readed blocks and line that will be eaten by inFile.get()
		++parser_data->blocks;
		++parser_data->current_line;

		inFile.getline(rubbish, ta_temp_size);
		if (!ifstrm_status(inFile, main_data->filename, false, false, false))
			ta_parser_fatal_error_msg();
	} std::cout << "\n"; // new line after current_line and \r

	delete count;	// freeing memory
	delete [] rubbish;
	
	// error checking the wrong number of blocks
	std::cout << "Equalization of the expected and explicit number of blocks...\n";
	if (parser_data->expected_blocks != parser_data->blocks) {
		std::cout << "\nERROR: number of blocks in file \"" << main_data->filename << "\" is less than\n"
			     "expected number blocks.\n" 
			     "\nInfo:\n"
			     "Lines:\t\t\t" << parser_data->lines
			  << "\nBlock size:\t\t" << main_data->block_size
			  << "\nHeader size <const>:\t" << common_data->header_size
			  << "\nBlocks expected:\t" << parser_data->expected_blocks
			  << "\nBlocks readed:\t\t" << parser_data->blocks << "\n";
		ta_parser_fatal_error_msg();
	}

	std::cout << "\nAll looks fine.\n";
	ta_parser_info(common_data, main_data, parser_data, temp);

	char *choise = new char;

	// run animation loop
	std::cout << "\nRun animation \"" << main_data->filename << "\"? <y/n> ";
	while (*choise != 'n') {
		std::cin.get(*choise).get();
		while (*choise != 'y' && *choise != 'n') {

			std::cout << "Please, enter a valid ansver: <y/n> ";
			std::cin.get(*choise).get();
		}
		if (*choise == 'n')
			break;

		run_animation(main_data->filename);
		ta_parser_info(common_data, main_data, parser_data, temp);

		std::cout << "\nRun animation \"" << main_data->filename << "\" again? <y/n> ";
	}

	// freeing memory
	delete main_data;
	delete common_data;
	delete parser_data;
	delete choise;	
}

#endif

// last edit: 28/07/21
// developed by Dolfost
