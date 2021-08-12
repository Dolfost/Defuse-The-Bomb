// clrscr -- <lib> clear screen function

#ifndef CLRSCR_H
#define CLRSCR_H

#include <iostream>

void clrscr(void) {
	std::cout << "\033[2J\033[1;1H";
}

#endif

// last edit: 18/07
// developed by Dolfost
