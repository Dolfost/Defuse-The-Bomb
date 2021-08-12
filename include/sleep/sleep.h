// sleep.h -- <lib> sleep function

#ifndef SLEEP_H
#define SLEEP_H

#include <ctime>

void sleep(double secs) {
	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay);
}
void sleep(int secs) {
	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay);
}
void sleep(float secs) {
	clock_t delay = secs * CLOCKS_PER_SEC;
	clock_t start = clock();
	while (clock() - start < delay);
}

#endif

// last edit: 18/07/21
// developed by Dolfost
