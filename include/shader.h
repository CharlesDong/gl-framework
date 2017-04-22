#ifndef SHADER_H_
#define SHADER_H_

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

enum TypeShader
{
	TS_VERTEX,
	TS_FRAGMENT
};

class Shader
{
private:
	GLuint mId;

	GLuint genShader(const char * source, TypeShader type) const;
	void genProgram(GLuint vShader, GLuint fShader);

	GLint getLoc(const char * name) const
	{
		return glGetUniformLocation(mId, name);
	}

	GLenum getEnum(TypeShader type) const;
	const char * getName(TypeShader type) const;

public:
	Shader();
	~Shader();

	void generate(const char * vSource, const char * fSource);

	void clear() const
	{
		glDeleteProgram(mId);
	}

	void use() const
	{
		glUseProgram(mId);
	}

	GLuint getId() const
	{
		return mId;
	}
	
	void uniformi(const char * name, int val) const
	{
		glUniform1i(getLoc(name), val);
	}

	void uniformf(const char * name, float val) const
	{
		glUniform1f(getLoc(name), val);
	}

	void uniformd(const char * name, double val) const
	{
		glUniform1d(getLoc(name), val);
	}

	void uniform2f(const char * name, const glm::vec2 & vec) const
	{
		glUniform2fv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform2d(const char * name, const glm::dvec2 & vec) const
	{
		glUniform2dv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform3f(const char * name, const glm::vec3 & vec) const
	{
		glUniform3fv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform3d(const char * name, const glm::dvec3 & vec) const
	{
		glUniform3dv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform4f(const char * name, const glm::vec4 & vec) const
	{
		glUniform4fv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform4d(const char * name, const glm::dvec4 & vec) const
	{
		glUniform4dv(getLoc(name), 1, glm::value_ptr(vec));
	}

	void uniform4x4f(const char * name, const glm::mat4 & mat) const
	{
		glUniformMatrix4fv(getLoc(name), 1, GL_FALSE, glm::value_ptr(mat));
	}

	void uniform4x4d(const char * name, const glm::dmat4 & mat) const
	{
		glUniformMatrix4dv(getLoc(name), 1, GL_FALSE, glm::value_ptr(mat));
	}
};

#endif