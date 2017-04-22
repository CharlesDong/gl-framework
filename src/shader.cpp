#include "shader.h"
#include <iostream>

Shader::Shader()
{
}

Shader::~Shader()
{
}

void Shader::generate(const char * vSource, const char * fSource)
{
	GLuint vShader = genShader(vSource, TS_VERTEX);
	GLuint fShader = genShader(fSource, TS_FRAGMENT);
	genProgram(vShader, fShader);
}

GLenum Shader::getEnum(TypeShader type) const
{
	switch (type)
	{
	case TS_VERTEX:
		return GL_VERTEX_SHADER;
	case TS_FRAGMENT:
		return GL_FRAGMENT_SHADER;
	default:
		return 0;
	}
}

const char * Shader::getName(TypeShader type) const
{
	switch (type)
	{
	case TS_VERTEX:
		return "vertex";
	case TS_FRAGMENT:
		return "fragment";
	default:
		return "UNKNOWN";
	}
}

GLuint Shader::genShader(const char * source, TypeShader type) const
{
	GLuint result = glCreateShader(getEnum(type));
	glShaderSource(result, 1, &source, nullptr);
	glCompileShader(result);

	GLint status;
	glGetShaderiv(result, GL_COMPILE_STATUS, &status);
	if (!status)
	{
		GLint len;
		glGetShaderiv(result, GL_INFO_LOG_LENGTH, &len);
		GLchar * log = new GLchar[len + 1];
		glGetShaderInfoLog(result, len + 1, nullptr, log);
		std::cout << "Shader compilation failed, type: " << getName(type) << ", info log:\n" << log << std::endl;
		delete[] log;
	}

	return result;
}

void Shader::genProgram(GLuint vShader, GLuint fShader)
{
	mId = glCreateProgram();
	glAttachShader(mId, vShader);
	glAttachShader(mId, fShader);
	glLinkProgram(mId);

	GLint status;
	glGetProgramiv(mId, GL_LINK_STATUS, &status);
	if (!status)
	{
		GLint len;
		glGetProgramiv(mId, GL_INFO_LOG_LENGTH, &len);
		std::cout << len << std::endl;
		GLchar * log = new GLchar[len + 1];
		glGetProgramInfoLog(mId, len + 1, nullptr, log);
		std::cout << "Shader program linking failed, info log:\n" << log << std::endl;
		delete[] log;
	}
}