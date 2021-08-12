#include <iostream>
#include "sleep.h"

int main() {

	std::cout << "Enter a delay <double>: ";
	double pause_double;
	std::cin >> pause_double;
	sleep(pause_double);
	std::cout << "Enter a delay <int>: ";
	int pause_int;
	std::cin >> pause_int;
	sleep(pause_int);
	std::cout << "Enter a delay <float>: ";
	float delay_float;
	std::cin >> delay_float;
	sleep(delay_float);

	std::cout << "DONE\n";
	return 0;
}
