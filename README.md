# OpenGL Framework Set

An OpenGL framework set in C++ used by myself to create 2D/3D games.

## Introduction

The framework can be divided into two parts: one is about OpenGL tools, and another is common utilities.

Under the `include/` directory you can find the header files for the framework, and under the `src/` directory you can find the implementation details.

**The OpenGL tools** include `Shader` and `Texture` class. Through these classes you can manage OpenGL shader programs and textures easily. There is also a `ResourceManager` class to host all shaders and textures.

**The common utilities** are not for OpenGL only, they are also available when you use a different graphics API. They include functions like number-string conversion, detailed time-getting (yy-mm-dd hh:mm:ss) and logging.

## Code Length

Header files:

File name | class/struct defined | functionality | lines | sloc
----------|----------------------|---------------|-------|-----
debug.h | - | Debug functions. | 13 | 10
logger.h | Logger | Logging. | 49 | 41
resourcemanager.h | ResourceManager | Manage the resources (shaders and textures). | 49 | 39
shader.h | Shader | Simplified management to a shader. | 107 | 84
str.h | - | Number-string/string-number conversion. | 18 | 14
texture.h | Texture | Simplified management to a texture. | 32 | 25
tm.h | Time | Time getting. | 16 | 13
TOTAL | - | - | 284 | 226

Source files:

File name | lines | sloc
----------|-------|-----
debug.cpp | 26 | 24
logger.cpp | 39 | 35
resourcemanager.cpp | 69 | 59
shader.cpp | 85 | 75
texture.cpp | 22 | 19
tm.cpp | 21 | 17
TOTAL | 262 | 229

Total lines: 546

Total sloc: 455

Update time: 12:03, Apr 23, 2017

## Notes

1. When I'm creating games, I add the files to my project as part of the project (maybe with a few edits), not as dependencies.
1. If you like this, you can directly download this repository and use the framework!
