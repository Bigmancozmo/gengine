#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

namespace gengine {
	class Shader {
		public:
			unsigned int ID;

			Shader(const char* vertexPath, const char* fragmentPath);
			void use();
			void setBool(std::string& name, bool value);
			void setInt(std::string& name, int value);
			void setFloat(std::string& name, float value);
	};
}

#endif // SHADER_HPP