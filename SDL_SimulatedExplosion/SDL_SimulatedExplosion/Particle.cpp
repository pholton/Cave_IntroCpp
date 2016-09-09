#include "Particle.h"
#include "Screen.h"
#include <stdlib.h>
#include <math.h>

namespace cop {

	Particle::Particle(): m_x(0), m_y(0) {
		
		// can move in any direction (2*pi radians == 360 degrees)
		m_direction = (2 * M_PI * rand()) / RAND_MAX;
		// give the particles a random speed
		m_speed = (0.0002 * rand()) / RAND_MAX;
	}

	Particle::~Particle() {
	}

	// Pass interval to ensure constant speed regardless of system performance
	void Particle::update(int interval) {
		// get the x and y speed using trig functions
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		// increment the x and y movement
		m_x += xspeed * interval;
		m_y += yspeed * interval;

	}
}