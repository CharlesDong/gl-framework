#ifndef RESOURCEMANAGER_H_
#define RESOURCEMANAGER_H_

#include <map>
#include "shader.h"
#include "texture.h"

class ResourceManager
{
private:
	std::map<std::string, Shader> mShaders;
	std::map<std::string, Texture> mTextures;
	static ResourceManager resourceMgr;

	Shader loadShaderFromFile(const char * vFilename, const char * fFilename);
	Texture loadTextureFromFile(const char * filename, bool hasAlpha);
public:
	ResourceManager();
	~ResourceManager();

	void clear() const;

	void loadShader(const char * name, const char * vFilename, const char * fFilename)
	{
		mShaders[name] = loadShaderFromFile(vFilename, fFilename);
	}

	void loadTexture(const char * name, const char * filename, bool hasAlpha)
	{
		mTextures[name] = loadTextureFromFile(filename, hasAlpha);
	}

	Shader & getShader(const char * name)
	{
		return mShaders[name];
	}

	Texture & getTexture(const char * name)
	{
		return mTextures[name];
	}

	static ResourceManager & get()
	{
		return resourceMgr;
	}
};

#endif