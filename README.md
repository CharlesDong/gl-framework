# OpenGL Framework Set

An OpenGL framework set in C++ used by myself to create 2D/3D games.

## Introduction

The framework can be divided into two parts: one is about OpenGL tools, and another is common utilities.

Under the `include/` directory you can find the header files for the framework, and under the `src/` directory you can find the implementation details.

**The OpenGL tools** include `Shader` and `Texture` class. Through these classes you can manage OpenGL shader programs and textures easily. There is also a `ResourceManager` class to host all shaders and textures.

**The common utilities** are not for OpenGL only, they are also available when you use a different graphics API. They include functions like number-string conversion, detailed time-getting (yy-mm-dd hh:mm:ss) and logging.

## Notes

1. The framework is currently incomplete, so the following is just planning.
2. When I'm creating games, I add the files to my project as part of the project (maybe with a few edits), not as dependencies.
3. If you like this, you can directly download this repository and use the framework!
