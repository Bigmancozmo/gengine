#ifndef EBO_HPP
#define EBO_HPP

#include "../../dll.h"
#include "glad/glad.h"

namespace gengine {
	class GENGINE_API EBO {
		private:
			unsigned int ID;
		public:
			EBO();
			void bind();
	};
}

#endif // EBO_HPP