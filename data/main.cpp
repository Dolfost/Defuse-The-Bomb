// main.cpp -- the main file of game Defuse The Bomb!

#include <iostream>
#include <limits>

#include "../include/fcheck/fcheck.h"
#include "../include/clrscr/clrscr.h"
#include "../include/sleep/sleep.h"
#include "../include/txtanimation/txtanimation.h"
#include "../include/ansicolors/ansicolors.h"

#include "bin/corefunctions.h"
#include "bin/anims.h"
#include "bin/constants.h"
#include "bin/scores.h"
#include "bin/settings.h"

// functions prototypes:
void call_menu(void);
unsigned int read_menu_chosie(void);

void on_start(void);

void run_game(void);
void run_settings(dtb_settings *current_settings);
void run_scores(void);
void run_exit(void);

void get_player_name(dtb_scores *current);

int main(void) {
	dtb_settings *current_settings = read_settings();
	unsigned int choise;
	on_start();
	runa_loading();
	while (true) {
		call_menu();
		choise = read_menu_chosie();
		switch (choise) {
		case 1 : clrscr(); run_game(); break;
		case 2 : clrscr(); run_scores(); break;
		case 3 : clrscr(); run_settings(current_settings); break;
		case 4 : clrscr(); run_exit(); break; }
	}
	return 0;
}

void call_menu(void) {
	system(PROGRAM_MENU);
}
unsigned int read_menu_chosie(void) {
	std::ifstream inFile;

	inFile.open(PROGRAM_MENU_CHOISE_FILE);
	is_open(inFile, PROGRAM_MENU_CHOISE_FILE, true);

	unsigned int choise;
	inFile >> choise;

	ifstrm_status(inFile, PROGRAM_MENU_CHOISE_FILE,true, false, false);
	inFile.close();

	return choise;
}

void get_player_name(dtb_scores *current) {
	char answr;
	std::cout << "Enter a player name <q for exit>: ";
	std::cin.get(current->player_name, SCORES_NAMELENGHT).get();
	cin_empty(current->player_name, SCORES_NAMELENGHT);

	clrscr();
	if (current->player_name[0] == 'q' && current->player_name[1] == '\0')
		run_exit();
	std::cout << "Are you sure to start game with name \"" << current->player_name << "\"? <y/n> ";
	std::cin.get(answr); 
	cin_clear();
	check_ansver(answr);

	while (answr == 'n') {
		clrscr();
		std::cout << "Enter a new name: ";
		std::cin.get(current->player_name, SCORES_NAMELENGHT).get();
		cin_empty(current->player_name, SCORES_NAMELENGHT);
		clrscr();
		if (current->player_name[0] == 'q' && current->player_name[1] == '\0')
			run_exit();
		std::cout << "Start game with name \"" << current->player_name << "\"? <y/n> ";
		std::cin.get(answr);
		check_ansver(answr);
		cin_clear();
	}
}

void run_game(void) {
	dtb_scores current_scores;
	while (player_name_data.stts == 2) {
		get_player_name(&current_scores);
		check_player_name(&current_scores);
	}
	runa_intro();


}
void run_scores(void) {
	dtb_scores *global_scores = copy_scores();

	std::cout << "\n\t   " mBOLD BLK bYEL "    SCORES   " sRST "\n\n";

	if (scores_lines == 0) {
		std::cout << "\t   " mBOLD BLK bRED "   <empty>   " sRST "\n\n";
		// stopper
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//		cin_clear();
		return; }

	unsigned long count;
	unsigned short count2;

	for (count = 0; count < scores_lines / 2; ++count) {
		std::cout << "  " mBOLD BLU "Player #" sRST RED << count + 1 << sRST
			     mBOLD BLU ":" sRST "\t\t" mITLC MAG << (global_scores + count)->player_name << sRST "\n";
		std::cout << "  " mBOLD BLU "Best Combos:\t" sRST  BLUh "| ";

		for (count2 = 0; count2 < SCORES_COMBO; ++count2) {
			std::cout << sRST mUNDRLN GRN << (global_scores + count)->combo[count2] 
				  << sRST BLUh " | "; }

		std::cout << "\n  " sRST mBOLD BLU "Wins:\t\t" sRST BLUh "| " mUNDRLN GRN
			  << (global_scores + count)->wins_fails[0]
		          << sRST "\n  " mBOLD BLU "Booms:\t" sRST BLUh "| " mUNDRLN GRN
			  << (global_scores + count)->wins_fails[1]
			  << sRST "\n  " mBOLD BLU "Luck:\t\t" sRST BLUh "| " mUNDRLN GRN;

		if ((global_scores + count)->wins_fails[0] == 0)
			++(global_scores + count)->wins_fails[0];

		if ((global_scores + count)->wins_fails[1] == 0)
			++(global_scores + count)->wins_fails[1];
		
		std::cout << (double((global_scores + count)->wins_fails[0])/
			     double((global_scores + count)->wins_fails[1])) - 1
			  << "\n\n" sRST; }

	// stopper
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//	cin_clear();
}

void run_settings(dtb_settings *current_settings) {
	std::cout << "Settings\n";
}

void run_exit(void) {
	std::cout << "run exit\n";
	exit(EXIT_SUCCESS);
}

void on_start(void) {
	scores_lines = count_lines(SCORES_FILE);
}


// last edit: 26/07/2021
