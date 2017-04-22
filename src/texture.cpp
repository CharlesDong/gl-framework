#include "texture.h"
#include <lodepng.h>

Texture::Texture()
{
}

Texture::~Texture()
{
}

void Texture::generate(const unsigned char * image, int w, int h, bool hasAlpha)
{
	glGenTextures(1, &mId);
	glBindTexture(GL_TEXTURE_2D, mId);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, /*hasAlpha ? GL_CLAMP_TO_EDGE : */GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, /*hasAlpha ? GL_CLAMP_TO_EDGE : */GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, hasAlpha ? GL_RGBA : GL_RGB, w, h, 0, hasAlpha ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
	glBindTexture(GL_TEXTURE_2D, 0);
}