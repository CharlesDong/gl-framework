#ifndef LOGGER_H_
#define LOGGER_H_

#include <string>
#include <fstream>

#define STREAM_INFO		Logger::get(LL_INFO)
#define STREAM_WARNING	Logger::get(LL_WARNING)
#define STREAM_ERROR	Logger::get(LL_ERROR)
#define STREAM_FATAL	Logger::get(LL_FATAL)

enum LogLevel
{
	LL_INFO,
	LL_WARNING,
	LL_ERROR,
	LL_FATAL
};

class Logger
{
private:
	std::string mFilename;
	std::ofstream mFile;
	static Logger logger;

	static const char * getLevelName(LogLevel level);
public:
	Logger();
	~Logger();
	template <typename T> Logger & operator<<(const T & val);

	static Logger & get(LogLevel level)
	{
		logger << getLevelName(level);
		return logger;
	}
};

template <typename T>
Logger & Logger::operator<<(const T & val)
{
	mFile.open(mFilename, std::ios_base::app);
	mFile << val;
	mFile.close();
	return *this;
}

#endif