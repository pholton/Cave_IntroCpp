#include <iostream>
#include "SDL.h"

int main(int argc, char* argv[]){

	// Setup window height and width
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Check to make sure that SDL is working, and quit if it fails to initialize
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL init failed." << std::endl;
		return 1;
	}

	// Create a new SDL window
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// If the window fails to be created, return the SDL error code, and quit
	if (window == NULL) {
		std::cout << SDL_GetError() << std::endl;
		SDL_Quit();
		return 2;
	}

	// Setup variables for game loop
	bool quit = false;
	SDL_Event event;

	// Game/event loop, runs until close window button is clicked
	while (!quit) {
		// Update particles
		// Draw particles
		// Check for messages/events

		// Processes the events in the SDL window
		while (SDL_PollEvent(&event)) {
			// if the quit event is called, exit game loop
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Remove the window from memory
	SDL_DestroyWindow(window);

	// Quit all SDL processes
	SDL_Quit();

	return 0;
}