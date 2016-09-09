
#include <iostream>
#include <SDL.h>
#include "Screen.h"

int main(int argc, char* argv[]) {
	
	cop::Screen screen;
	if (!screen.init()) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	SDL_Event event;

	while (screen.processEvents(event) != false) {
		// Do stuff
		
	}

	screen.close();

	return 0;
}