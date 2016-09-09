#ifndef ANIMALS_H_
#define ANIMALS_H_

#include <string>

namespace ani {

	const std::string CATNAME = "Snugglepuss";

	class Cat{
	public:
		Cat();
		~Cat();
		void speak();
	};
}

#endif