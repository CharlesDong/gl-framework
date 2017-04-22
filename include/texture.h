#ifndef TEXTURE_H_
#define TEXTURE_H_

#include <GL/glew.h>

class Texture
{
private:
	GLuint mId;
public:
	Texture();
	~Texture();

	void generate(const unsigned char * image, int w, int h, bool hasAlpha = false);

	void clear() const
	{
		glDeleteTextures(1, &mId);
	}

	void bind() const
	{
		glBindTexture(GL_TEXTURE_2D, mId);
	}

	GLuint getId() const
	{
		return mId;
	}
};

#endif