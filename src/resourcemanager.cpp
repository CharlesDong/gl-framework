#include "resourcemanager.h"
#include <fstream>
#include <lodepng.h>
#include "debug.h"

ResourceManager ResourceManager::resourceMgr;

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::clear() const
{
	for (auto it : mShaders)
		it.second.clear();
	for (auto it : mTextures)
		it.second.clear();
}

Shader ResourceManager::loadShaderFromFile(const char * vFilename, const char * fFilename)
{
	std::ifstream fin;
	int size;
	char * vSource;
	char * fSource;

	// TODO: use a getFileSize() function to get file size
	fin.open(vFilename);
	assertWithMsg(fin.is_open(), "Failed to open shader file, type: vertex!");
	fin.seekg(0, std::ios_base::end);
	size = (int)fin.tellg();
	fin.seekg(0, std::ios_base::beg);
	vSource = new char[size + 1]{ '\0' };
	fin.read(vSource, size);
	fin.close();

	// TODO: use a getFileSize() function to get file size
	fin.open(fFilename);
	assertWithMsg(fin.is_open(), "Failed to open shader file, type: fragment!");
	fin.seekg(0, std::ios_base::end);
	size = (int)fin.tellg();
	fin.seekg(0, std::ios_base::beg);
	fSource = new char[size + 1]{ '\0' };
	fin.read(fSource, size);
	fin.close();

	Shader shader;
	shader.generate(vSource, fSource);
	delete[] vSource;
	delete[] fSource;
	return shader;
}

Texture ResourceManager::loadTextureFromFile(const char * filename, bool hasAlpha)
{
	//unsigned char * image;
	std::vector<unsigned char> image;
	unsigned w, h;
	//lodepng_decode_file(&image, &w, &h, filename, hasAlpha ? LCT_RGBA : LCT_RGB, hasAlpha ? 32 : 24);
	lodepng::decode(image, w, h, filename);

	Texture texture;
	texture.generate(image.data(), (int)w, (int)h, hasAlpha);
	return texture;
}