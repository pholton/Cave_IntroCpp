
#include <iostream>
#include <SDL.h>
#include "Screen.h"

int main(int argc, char* argv[]) {
	
	cop::Screen screen;
	if (!screen.init()) {
		std::cout << "Error initialising SDL." << std::endl;
	}


	SDL_Event event;
	int elapsed;
	while (screen.processEvents(event) != false) {

		// Get elapsed time window has been open for
		elapsed = SDL_GetTicks();
		// Use 1 + trig functions to get numbers that cycle between 0 and 2
		// multiply by 128 to get numbers between 0 and 255
		// store in an unsigned char to ensure that we never go above 255
		// unsigned char will overflow to a number between 0 and 255
		unsigned char red = (unsigned char)((1 + cos(elapsed * 0.0004)) * 128);
		unsigned char green = (unsigned char)((1 + cos(elapsed * 0.0006)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);

		// Loop through all of the pixels and set them to purple (128, 0, 255)
		for (int y = 0; y < cop::Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < cop::Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		// Draw the texture to the screen
		screen.update();
		
	}

	screen.close();

	return 0;
}