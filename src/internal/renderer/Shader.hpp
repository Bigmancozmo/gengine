#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <glm/glm.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "../../classes/Logger.hpp"
#include "../../dll.h"

namespace gengine {
	class GENGINE_API Shader {
		private:
			Logger* logger;
		public:
			unsigned int ID;

			Shader(const char* vertexPath, const char* fragmentPath);

			void use();

			void setBool(std::string& name, bool value);
			void setInt(std::string& name, int value);
			void setFloat(std::string& name, float value);

			void setVec2(std::string& name, glm::vec2& value);
			void setVec2(std::string& name, float x, float y);
			void setVec3(std::string& name, glm::vec3& value);
			void setVec3(std::string& name, float x, float y, float z);
			void setVec4(std::string& name, glm::vec4& value);
			void setVec4(std::string& name, float x, float y, float z, float w);

			void setMat2(std::string& name, glm::mat2& mat);
			void setMat3(std::string& name, glm::mat3& mat);
			void setMat4(std::string& name, glm::mat4& mat);
	};
}

#endif // SHADER_HPP