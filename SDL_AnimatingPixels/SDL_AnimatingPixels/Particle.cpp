#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>

namespace cop {

	Particle::Particle() {
		// set initial x and y values, later used to set coordinates for a give particle
		// rand()/RAND_MAX will return values between 0 and 1
		// so result is between -1 and 1
		//m_x = ((2.0 * rand()) / RAND_MAX) - 1;
		//m_y = ((2.0 * rand()) / RAND_MAX) - 1;
		m_x = 0;
		m_y = 0;

		// direction of movement is set when the object is constructed.
		// So movement is in a consistent direction for a given particle
		m_xspeed = 0.002 * ((2.0 * rand()) / RAND_MAX - 1);
		m_yspeed = 0.002 * ((2.0 * rand()) / RAND_MAX - 1);
	}

	Particle::~Particle() {
	}

	void Particle::update() {

		// Move the particle by m_xspeed and m_yspeed. These are constant for a given particle
		// since they are initialized in the constructor for each particle.
		m_x += m_xspeed;
		m_y += m_yspeed;

		// if m_x moves outside of its accepted range (moves off screen),
		// reverse its direction (bounces off edge of screen)
		if (m_x <= -1.0 || m_x >= 1.0) {
			m_xspeed = -m_xspeed;
		}

		// if m_y moves outside of its accepted range (moves off screen),
		// reverse its direction (bounces off edge of screen)
		if (m_y <= -1.0 || m_y >= 1.0) {
			m_yspeed = -m_yspeed;
		}

	}
}