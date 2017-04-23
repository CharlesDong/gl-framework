# OpenGL Framework Set

An OpenGL framework set in C++ used by myself to create 2D/3D games.

## Introduction

The framework can be divided into two parts: one is about OpenGL tools, and another is common utilities.

Under the `include/` directory you can find the header files for the framework, and under the `src/` directory you can find the implementation details.

**The OpenGL tools** include `Shader` and `Texture` class. Through these classes you can manage OpenGL shader programs and textures easily. There is also a `ResourceManager` class to host all shaders and textures.

**The common utilities** are not for OpenGL only, they are also available when you use a different graphics API. They include functions like number-string conversion, detailed time-getting (yy-mm-dd hh:mm:ss) and logging.

## Code Length

File name | lines | sloc
----------|-------|-----
debug.h | 13 | 10
logger.h | 49 | 41
resourcemanager.h | 49 | 39
shader.h | 107 | 84
str.h | 18 | 14
texture.h | 32 | 25
tm.h | 16 | 13
debug.cpp | 26 | 24
logger.cpp | 39 | 35
resourcemanager.cpp | 69 | 59
shader.cpp | 85 | 75
texture.cpp | 22 | 19
tm.cpp | 21 | 17
total | 546 | 455

## Notes

1. The framework is currently incomplete, so the information upon is just planning.
2. When I'm creating games, I add the files to my project as part of the project (maybe with a few edits), not as dependencies.
3. If you like this, you can directly download this repository and use the framework!
