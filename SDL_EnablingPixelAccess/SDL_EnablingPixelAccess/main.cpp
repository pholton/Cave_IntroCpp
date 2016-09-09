#include <iostream>
#include <SDL.h>

int main(int argv, char* argc[]) {

	// Setup constants for the windows screen size
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Check to see if we can initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL init failed!" << std::endl;
		return 1;
	}

	// Create a SDL window
	SDL_Window *window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_HEIGHT, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	// If window creation fails, quit
	if (window == NULL) {
		std::cout << "Failed to create window." << std::endl;
		SDL_Quit();
		return 2;
	}

	// Create a renderer that will render textures in the window
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	// If the renderer fails to initialize then quit
	if (renderer == NULL) {
		std::cout << "Could not create renderer." << std::endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	// Create a texture pointer that will use the renderer to display textures to the window
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	// if the texture fails to initialize then quit
	if (texture == NULL) {
		std::cout << "Could not create texture." << std::endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4; 
	}

	// Create space in memory to store the texture "bitmap"
	Uint32 *buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

	// initialize the buffer to all white pixels, 255/0xFF
	memset(buffer, 0xFF, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
		buffer[i] = 0xFFFF00FF;
	}

	// Update the texture, clear the renderer, add texture to renderer, and render to the window
	// These commands will eventually move into the game loop
	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	// Game loop
	while (!quit) {
		// Update particles
		// Draw particles
		// Check for messages/events

		// Run while events are queued
		while (SDL_PollEvent(&event)) {
			// if the quit event is triggered, exit game loop
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Free memory, and destroy all of the SDL objects
	delete[] buffer;
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;

}