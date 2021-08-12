// fcheck.h -- <lib> checking fstream objects for errors

#ifndef FCHECK_H
#define FCHECK_H

#include <fstream>
#include <iostream>

#include "messages/current.h"

			//...:::is_open start:::...//
bool is_open(std::ifstream & inFile, const char filename[], bool exit_if_closed) {		// is_open ifstream char[]
	if (inFile.is_open())
		return true;
	else {
		std::cout << FC_PREFIX << FC_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}
bool is_open(std::ifstream & inFile, const char *filename[], bool exit_if_closed) {		// is_open ifstream char*[]
	if (inFile.is_open())
		return true;
	else {
		std::cout << FC_PREFIX << FC_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}

bool is_open(std::ofstream & outFile, const char filename[], bool exit_if_closed) {		// is_open ofstream char[]
	if (outFile.is_open())
		return true;
	else {
		std::cout << FC_PREFIX << FC_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}
bool is_open(std::ofstream & outFile, const char *filename[], bool exit_if_closed) {		// is_open ofstream char*[]
	if (outFile.is_open())
		return true;
	else {
		std::cout << FC_PREFIX << FC_FAILED_TO_OPEN;
		if (exit_if_closed) exit(EXIT_FAILURE);
		return false;
	}
}
			//...:::is_open end:::...//

			//...:::ifstrm_status start:::...//
bool ifstrm_status(std::ifstream & inFile, const char filename[], bool exit_if_fail, bool eof_react, bool slient) {	// ifstream status char[]
	if (inFile.good())
	       return true;
	if (inFile.eof()) {
		if (!eof_react)
			return true;
		if (!slient)
			std::cout << FC_PREFIX << FC_EOF; 
	} else
	if (inFile.fail()) {
		if (!slient)
			std::cout << FC_PREFIX << FC_FAIL;
		if (exit_if_fail) exit(EXIT_FAILURE);
	} else {
		if (!slient)
			std::cout << FC_PREFIX << FC_BAD;
		if (exit_if_fail) exit(EXIT_FAILURE);
	}
	return false;
}
bool ifstrm_status(std::ifstream & inFile, const char *filename[], bool exit_if_fail, bool eof_react, bool slient) {	// ifstream status char*[]
	if (inFile.good())
	       return true;
	if (inFile.eof()) {
		if (!eof_react)
			return true;
		if (!slient)
			std::cout << FC_PREFIX << FC_EOF;
	} else
	if (inFile.fail()) {
		if (!slient)
			std::cout << FC_PREFIX << FC_FAIL;
		if (exit_if_fail) exit(EXIT_FAILURE);
	} else {
		if (!slient)
			std::cout << FC_PREFIX << FC_BAD;
		if (exit_if_fail) exit(EXIT_FAILURE);
	}
	return false;
}
			//...:::ifstrm_status end:::...//
			
			//...:::messages start:::...//
bool eof_msg(std::ifstream & inFile, const char filename[], bool exit_if_eof) {	// ifstream eof message char[]
	if (inFile.eof()) {
		std::cout << FC_EOF_MSG;
		if (exit_if_eof) exit(EXIT_FAILURE);
		return true;
	}
	return false;
}
bool eof_msg(std::ifstream & inFile, const char *filename[], bool exit_if_eof) {	// ifstream eof message char*[]
	if (inFile.eof()) {
		std::cout << FC_EOF_MSG;
		if (exit_if_eof) exit(EXIT_FAILURE);
		return true;
	}
	return false;
}
#endif

// last edit: 24/07/2021
// developed by Dolfost
