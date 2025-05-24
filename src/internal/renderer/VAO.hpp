#ifndef VAO_HPP
#define VAO_HPP

#include "glad/glad.h"

namespace gengine {
	class VAO {
		private:
			unsigned int ID;
		public:
			VAO();
			void bind();
	};
}

#endif // VAO_HPP