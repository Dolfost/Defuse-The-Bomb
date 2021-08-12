#include <iostream>
#include "fcheck.h"

int main() {
	std::ifstream inFile;
	char name[30];

	std::cout << "Enter a filename <char>: ";
	std::cin.get(name, 30).get();

	inFile.open(name);

	is_open(inFile, name, true);
	ifstrm_status(inFile, name, true, true, false);
	inFile.close();

	char *name1 = new char[30];
	std::cout << "Enter a filename <char*>: ";
	std::cin.get(name1, 30).get();

	inFile.open(name1);

	is_open(inFile, name1, true);
	inFile.close();

	eof_msg(inFile, name, true);

	return 0;
}
