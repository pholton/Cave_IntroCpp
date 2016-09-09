#include "Swarm.h"

namespace cop {

	// Create a swarm of NPARTICLES particles
	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];
	}

	// Delete the swarm of particles when object is destroyed
	Swarm::~Swarm() {
		delete[] m_pParticles;
	}
}