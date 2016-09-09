#ifndef CAT_H_
#define CAT_H_

#include <string>

namespace cats {

	const std::string CATNAME = "Mittens";

	class Cat{
	public:
		Cat();
		~Cat();
		void speak();
	};
}
#endif