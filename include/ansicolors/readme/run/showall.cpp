#include <iostream>

#include "../../ansicolors.h"

int main(){
	
	std::cout << mBLD RED "Hey this is the color red, and it's bold!" sRST "\n";
	std::cout << mSTRIKETHROUGH RED "If " BLU "you " YEL "are " GRN "bored " CYN "do " MAG "this! " sRST "\n"; 
	std::cout << mITALIC RED "If " BLU "you " YEL "are " GRN "bored " CYN "do " MAG "this " sRST "\n"; 
	std::cout << mUNDERLINE RED "If " BLU "you " YEL "are " GRN "bored " CYN "do " MAG "this! " sRST "\n";

	std::cout << mITLC "Enter a terminal color code <0-255> " sRST;
	int code;
	std::cin >> code;
	setFOREGROUND(code);
	std::cout << "\nThis text in color #" << code << "!" sRST "\n"
		     "But this sentence not colorful...\n";
	return 0;
}
