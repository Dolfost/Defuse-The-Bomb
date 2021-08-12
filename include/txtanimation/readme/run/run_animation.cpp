// run_animation.cpp -- script for viewing your txtanimations

#include <iostream>
#include "../../txtanimation.h"

int main(void) {
	char *name = new char[4096];
	char *choise = new char;

	std::cout << "Animation filename: ";
	std::cin.get(name, 4096).get();

	do {
		run_animation(name);

		std::cout << "\nRun animation \"" << name << "\" again? <y/n> ";
		std::cin.get(*choise).get();

		while (*choise != 'y' && *choise != 'n') {
			std::cout << "Please, enter a valid ansver: <y/n> ";
			std::cin.get(*choise).get();
		}

	} while (*choise == 'y');

	delete [] name;
	delete choise;

	return 0;
}
