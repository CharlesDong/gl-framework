#include "debug.h"
#include "logger.h"
#include <conio.h>

void onAssert(bool value, const char * expression, const char * file, int line)
{
	if (!value)
	{
		STREAM_FATAL << "Debug assertion failed!\n"
			<< "File: " << file << "\n"
			<< "Line: " << line << "\n"
			<< "Expression: " << expression << "\n";
		_getch();
		exit(EXIT_FAILURE);
	}
}

void assertWithMsg(bool value, const char * message)
{
	if (!value)
	{
		STREAM_FATAL << message << "\n";
		_getch();
		exit(EXIT_FAILURE);
	}
}