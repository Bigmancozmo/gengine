#ifndef EBO_HPP
#define EBO_HPP

#include "glad/glad.h"

namespace gengine {
	class EBO {
		private:
			unsigned int ID;
		public:
			EBO();
			void bind();
	};
}

#endif // EBO_HPP