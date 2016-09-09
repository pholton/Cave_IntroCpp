#include "Particle.h"
#include <stdlib.h>

namespace cop {

	Particle::Particle() {
		// set initial x and y values, later used to set coordinates for a give particle
		// rand()/RAND_MAX will return values between 0 and 1
		// so result is between 0 and 2
		m_x = (2.0 * rand()) / RAND_MAX;
		m_y = (2.0 * rand()) / RAND_MAX;
	}


	Particle::~Particle() {
	}
}