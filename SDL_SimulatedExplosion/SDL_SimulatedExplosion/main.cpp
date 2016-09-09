
#include <iostream>
#include <SDL.h>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

int main(int argc, char* argv[]) {
	
	// seed random number function for use in Particle class
	srand((int)time(NULL));

	cop::Screen screen;
	if (!screen.init()) {
		std::cout << "Error initialising SDL." << std::endl;
	}

	// Create a new swarm of particles
	cop::Swarm swarm;

	SDL_Event event;
	int elapsed;
	int xOffset = cop::Screen::SCREEN_WIDTH / 2;
	int yOffset = cop::Screen::SCREEN_HEIGHT / 2;
	while (screen.processEvents(event) != false) {

		// Get elapsed time window has been open for
		elapsed = SDL_GetTicks();

		// clear screen of prior loops particle positions
		screen.clear();
		swarm.update(elapsed);

		// Use 1 + trig functions to get numbers that cycle between 0 and 2
		// multiply by 128 to get numbers between 0 and 255
		// store in an unsigned char to ensure that we never go above 255
		// unsigned char will overflow to a number between 0 and 255
		unsigned char red = (unsigned char)((1 + cos(elapsed * 0.0004)) * 128);
		unsigned char green = (unsigned char)((1 + cos(elapsed * 0.0006)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);

		// gets pointer to the particles in swarm (pointer to the array of 5000 particles)
		const cop::Particle * const pParticles = swarm.getParticles();

		// Loop through all of the particles in the swarm
		for (int i = 0; i < cop::Swarm::NPARTICLES; i++) {
			// create a particle object to represent one of the particles in the swarm
			// Constructor for particle creates a random x and y value
			cop::Particle particle = pParticles[i];

			// set x and y coordinates for the single particle object based on its
			// random x and y values assigned during initialization (between -1 and 1)
			int x = (int)((particle.m_x + 1) * xOffset);
			// m_y * xOffset will allow the y movement to be on the same scale as the x movement
			// (circular instead of oval). the add in yOffset to get the pixels to start in the 
			// center of the screen
			int y = (int)(particle.m_y * xOffset + yOffset);

			// set pixel for a given particle
			screen.setPixel(x, y, red, green, blue);
		}
		
		// Draw the texture to the screen
		screen.update();
		
	}

	// clean up and close all SDL objects
	screen.close();

	return 0;
}