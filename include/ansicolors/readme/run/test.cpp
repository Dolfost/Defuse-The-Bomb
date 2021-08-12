#include "ansicolors.h"
#include <iostream>

int main(){
	
	std::cout << BRED "Hey this is the color red, and it's bold! \n" CLR_RST;
	std::cout << RED "If" BLU "you" YEL "are" GRN "bored" CYN "do" MAG "this! \n" CLR_RST; 
	std::cout << BRED "If" BBLU "you" BYEL "are" BGRN "bored" BCYN "do" BMAG "this! \n" CLR_RST; 
	std::cout << URED "If" UBLU "you" UYEL "are" UGRN "bored" UCYN "do" UMAG "this! \n" CLR_RST;
	std::cout << REDHB "ERROR: " CLR_RST; 

return 0;
}
