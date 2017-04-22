#include "logger.h"
#include "str.h"
#include "tm.h"

Logger Logger::logger;

Logger::Logger()
{
	Time t = getTime();
	mFilename = "log-" + 
		toString(t.year) + "-" +
		toString(t.month) + "-" +
		toString(t.day) + "-" +
		toString(t.hour) + "." +
		toString(t.minute) + "."
		+ toString(t.second)
		+ ".txt";
}

Logger::~Logger()
{
}

const char * Logger::getLevelName(LogLevel level)
{
	switch (level)
	{
	case LL_INFO:
		return "[INFO]";
	case LL_WARNING:
		return "[WARNING]";
	case LL_ERROR:
		return "[ERROR]";
	case LL_FATAL:
		return "[FATAL]";
	default:
		return "[?]";
	}
}