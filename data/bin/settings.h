// settings.h -- settings structure for game Defuse The Bomb

#ifndef DTB_SETTINGS_H
#define DTB_SETTINGS_H

struct dtb_settings {
	unsigned short language;
};

dtb_settings* read_settings(void) {
	std::ifstream inFile;
	inFile.open(PROGRAM_SETTINGS_FILE);
	is_open(inFile, PROGRAM_SETTINGS_FILE, true);
	dtb_settings *current_settings = new dtb_settings;
	// read current language
	inFile >> current_settings->language;

	// check for errors
	ifstrm_status(inFile, PROGRAM_SETTINGS_FILE, true, false, false);
	inFile.close();
	return current_settings;
}

#endif

// last edit 27/07/2021
