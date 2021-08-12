// scores.h -- scores data structure

#include <iostream>
#include <cstring>

#include "constants.h"

struct dtb_scores {
	char player_name[SCORES_NAMELENGHT];
	int combo[SCORES_COMBO];
	unsigned long wins_fails[2];
};

struct dtb_player_name_data {
	unsigned short stts = 2;
} player_name_data;

unsigned long scores_lines;

// count lines
unsigned long count_lines(const char filename[]) {
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

dtb_scores* copy_scores(void) {
	dtb_scores *scores = new dtb_scores[scores_lines / 2];

	std::ifstream inFile;
	inFile.open(SCORES_FILE);
	is_open(inFile, SCORES_FILE, true);
	
	unsigned long count;
	unsigned long count2;
	for (count = 0; count < scores_lines / 2; ++count) {
		inFile.getline((scores + count)->player_name, SCORES_NAMELENGHT);
		ifstrm_status(inFile, SCORES_FILE, true, false, false);
		
		count2 = 0;
		while (count2 < SCORES_COMBO) {
			inFile >> (scores + count)->combo[count2];
			inFile.get();
			ifstrm_status(inFile, SCORES_FILE, true, false, false);
			++count2;
		} 

		count2 = 0;
		while (count2 < 2) {
			inFile >> (scores + count)->wins_fails[count2];
			inFile.get();
			ifstrm_status(inFile, SCORES_FILE, true, false, false);
			++count2;
		}
	}
	inFile.close();
	return scores;
}

void check_player_name(dtb_scores *current) {
	char name[scores_lines / 2][SCORES_NAMELENGHT];
	char debris[PROGRAM_DEBRIS_SIZE];

	std::ifstream inFile;
	inFile.open(SCORES_FILE);
	is_open(inFile, SCORES_FILE, true);
	
	unsigned long count;

	for (count = 0; count < scores_lines / 2; ++count) {
		inFile.getline(name[count], SCORES_NAMELENGHT);
		ifstrm_status(inFile, SCORES_FILE, true, false, false);
		inFile.getline(debris, PROGRAM_DEBRIS_SIZE);
		ifstrm_status(inFile, SCORES_FILE, true, false, false);
	}
	
	char choise;

	for (count = 0; count < scores_lines / 2; ++count) {
		clrscr();
		if (!strcmp(current->player_name, name[count])) {
			std::cout << "Player with name \"" << current->player_name
				  << "\" already exist!\n"
				     "Continue the game with this name - 1\n"
				     "Choose a new name - 2\n"
				     "Start a new game with this name - 3\n"
				     "Choise: ";

			std::cin.get(choise);
			cin_clear();
			clrscr();
			while (choise != '1' && choise != '2' && choise != '3') {
				clrscr();
				std::cout << "Enter a correct ansver: ";
				std::cin.get(choise);
			}
			
			if (choise == '1') {
				player_name_data.stts = 1;
				inFile.close();
				return;
			} 
			if (choise == '2') {
				player_name_data.stts = 2;
				inFile.close();
				return;
			}
			if (choise == '3') {
				player_name_data.stts = 3;
				inFile.close();
				return;
			} else {
				std::cout << mBOLD RED "Unknow choise ("
					  mITLC BLU "check_player_name()"
					  mBOLD RED ")\n" sRST;
				exit(EXIT_FAILURE);
			}
	
		}
	}

	inFile.close();
	player_name_data.stts = 3;
}
