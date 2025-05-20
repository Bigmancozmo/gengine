#include "Shader.hpp"

namespace gengine {
	Shader::Shader(const char* vertexPath, const char* fragmentPath)
	{
        this->ID = 0;

        logger = new Logger("Shader");
        logger->log(INFO, "Started shader creation");

        std::string vertexCode, fragmentCode;
        std::ifstream vShaderFile, fShaderFile;
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);
            std::stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            vShaderFile.close();
            fShaderFile.close();
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            logger->log(ERROR, "Failed to load shader files");
            return;
        }

        logger->log(INFO, "Successfully loaded files");

        const char* vertexShaderSource = vertexCode.c_str();
        const char* fragmentShaderSource = fragmentCode.c_str();

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);

        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
            logger->log(ERROR, "Failed to compile vertex shader: " + std::string(infoLog));
            return;
        }

        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            logger->log(ERROR, "Failed to compile fragment shader: " + std::string(infoLog));
            return;
        }

        this->ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, NULL, infoLog);
            logger->log(ERROR, "Failed to link shader program: " + std::string(infoLog));
            return;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
        logger->log(INFO, "Successfully created shader");
	}
    void Shader::use()
    {
        glUseProgram(ID);
    }
    void Shader::setBool(std::string& name, bool value)
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
    }
    void Shader::setInt(std::string& name, int value)
    {
        glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
    }
    void Shader::setFloat(std::string& name, float value)
    {
        glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
    }
    void Shader::setVec2(std::string& name, glm::vec2& value)
    {
        glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void Shader::setVec2(std::string& name, float x, float y)
    {
        glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
    }
    void Shader::setVec3(std::string& name, glm::vec3& value)
    {
        glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void Shader::setVec3(std::string& name, float x, float y, float z)
    {
        glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
    }
    void Shader::setVec4(std::string& name, glm::vec4& value)
    {
        glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
    }
    void Shader::setVec4(std::string& name, float x, float y, float z, float w)
    {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
    void Shader::setMat2(std::string& name, glm::mat2& mat)
    {
        glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    void Shader::setMat3(std::string& name, glm::mat3& mat)
    {
        glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    void Shader::setMat4(std::string& name, glm::mat4& mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
}