#pragma once

namespace cop {

	struct Particle {
		double m_x;
		double m_y;

	private:
		double m_speed;
		double m_direction;

	private:
		void init();

	public:
		Particle();
		~Particle();
		void update(int interval);
	};

}