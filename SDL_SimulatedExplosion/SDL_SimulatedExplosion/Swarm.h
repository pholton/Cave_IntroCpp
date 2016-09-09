#pragma once

#include "Particle.h"

namespace cop {

	class Swarm {
	public:
		// Number of particles in a swarm
		const static int NPARTICLES = 5000;

	private:
		// pointer to a Particle class, used to build particle array in swarm
		Particle *m_pParticles;
		int lastTime;

	public:
		Swarm();
		~Swarm();
		void update(int elapsed);
		// safe method of returning the pointer to the particle array
		const Particle * const getParticles() { return m_pParticles; };
	};

}