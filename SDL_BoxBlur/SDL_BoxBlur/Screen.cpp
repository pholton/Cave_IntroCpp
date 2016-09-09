#include "Screen.h"
#include <memory.h>

namespace cop {
	Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer1(NULL), m_buffer2(NULL) {

	}


	Screen::~Screen() {
	}

	bool Screen::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0){
			return false;
		}

		m_window = SDL_CreateWindow("Particle Fire Explosion",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (m_window == NULL) {
			SDL_Quit();
			return false;
		}

		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

		if (m_renderer == NULL) {
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

		if (m_texture == NULL) {
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		m_buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		m_buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(m_buffer1, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
		memset(m_buffer2, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

		return true;
	}

	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {

		// Not very efficient, but keeps program from crashing if a particle is off
		// screen i.e. the pixel is beyond the buffer address space.
		if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
			return;
		}

		// Safety on off chance that we try to set a pixel outside of the screen
		//if (x + y * SCREEN_WIDTH > LAST_PIXEL || x < 0 || y < 0) {
		//	return;
		//}


		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;

		// (y * SCREEN_WIDTH) will offset down y 'rows' of pixels
		// x will offset by x 'columns' of pixels
		m_buffer1[(y * SCREEN_WIDTH) + x] = color;
	}

	void Screen::boxBlur() {
		// Swap the buffers, so pixels are in m_buffer2 and we are drawing to m_buffer1
		Uint32 *temp = m_buffer1;
		m_buffer1 = m_buffer2;
		m_buffer2 = temp;

		// Loop through each row in the screen
		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			// Loop through each column in a given row
			for (int x = 0; x < SCREEN_WIDTH; x++) {

				/*
				 * We want to look at the color values in all of the pixels in
				 * a 3x3 grid surrounding and including the current pixel.
				 * Then we can sum up the color values and use the average of
				 * the color values to set the new color value in the swapped
				 * buffer.
				 * 
				 * 0 0 0 
				 * 0 1 0
				 * 0 0 0
				 *
				 */

				int redTotal = 0;
				int greenTotal = 0;
				int blueTotal = 0;

				// Loop through the row above the current row to the row below
				// the current row (adjacent rows)
				for (int row = -1; row <= 1; row++) {
					// Loop through the adjacent columns (1 to left - 1 to right)
					for (int col = -1; col <= 1; col++) {

						// store current x and y coordinates for the current offset pixel
						int currentX = x + col;
						int currentY = y + row;

						// Ensure that the surrounding pixels are on the screen
						if (currentX >= 0 && currentX < SCREEN_WIDTH && currentY >= 0 && currentY < SCREEN_HEIGHT) {
							// Get the color of the current pixel from m_buffer2 (which has m_buffer1's data)
							Uint32 color = m_buffer2[currentY * SCREEN_WIDTH + currentX];

							// Get the color values out of the current pixel
							Uint8 red = color >> 24;
							Uint8 green = color >> 16;
							Uint8 blue = color >> 8;

							// Add the color values from the current pixel to the
							// total for all adjacent pixels (and center pixel)
							redTotal += red;
							greenTotal += green;
							blueTotal += blue;
						}

					}
				}

				// After looping through all of the adjacent pixels, get an average color value
				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;

				// Set the center pixel to the averaged color
				setPixel(x, y, red, green, blue);
			}
		}
	}

	void Screen::update() {
		SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCREEN_WIDTH*sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);
	}

	bool Screen::processEvents(SDL_Event &event) {
		//SDL_Event event;

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				return false;
			}
		}
		return true;
	}

	void Screen::close() {
		delete[] m_buffer1;
		delete[] m_buffer2;
		SDL_DestroyTexture(m_texture);
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}