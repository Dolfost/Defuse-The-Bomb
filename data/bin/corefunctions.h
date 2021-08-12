// corefunctions.h -- core functions for game Defuse Tbe Bomb

#ifndef DTB_COREFUNCTIONS_H
#define DTB_COREFUNCTIONS_H

#include <limits>

short urandom(short min, short max) { // range : [min, max] 
   static bool first = true;
   if (first) {  
      srand( time(NULL) ); 	// seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

void cin_ignore(void) {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void cin_clear(void) {
	char temp = 'x';
	do {
		std::cin.get(temp);
	} while (temp != '\n');
}

void cin_empty(char text[], unsigned short limit) {
	while (strlen(text) == 0) {
		clrscr();
		std::cout << "Please enter something: ";
		std::cin.getline(text, limit);
	}
}

void check_ansver(char answr) {
	while (answr != 'y' && answr != 'n') {
		std::cout << "Enter a correct answer: ";
		std::cin.get(answr);
		cin_ignore();
	}
	cin_clear();
}

#endif

// last edit 28/07/2021
// developed by Dolfost
