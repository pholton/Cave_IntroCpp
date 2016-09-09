#include "Swarm.h"

namespace cop {

	// Create a swarm of NPARTICLES particles
	Swarm::Swarm(): lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];
	}

	// Delete the swarm of particles when object is destroyed
	Swarm::~Swarm() {
		delete[] m_pParticles;
	}

	void Swarm::update(int elapsed) {
		// determine how much time has passed between each call to
		// Swarm.update(). Normalizes speed for all systems.
		int interval = elapsed - lastTime;

		// Update the position of each particle in the swarm
		for (int i = 0; i < NPARTICLES; i++) {
			m_pParticles[i].update(interval);
		}

		lastTime = elapsed;
	}
}