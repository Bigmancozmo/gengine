#ifndef VAO_HPP
#define VAO_HPP

#include "../../dll.h"
#include "glad/glad.h"

namespace gengine {
	class GENGINE_API VAO {
		private:
			unsigned int ID;
		public:
			VAO();
			void bind();
	};
}

#endif // VAO_HPP