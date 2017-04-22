#include "tm.h"
#include <ctime>

Time getTime()
{
	time_t curTime;
	tm timeStruct;
	Time result;

	curTime = time(nullptr);
	localtime_s(&timeStruct, &curTime);

	result.year = timeStruct.tm_year - 100;		// tm_year is years since 1900
	result.month = timeStruct.tm_mon + 1;		// tm_mon is months since January
	result.day = timeStruct.tm_mday;
	result.hour = timeStruct.tm_hour;
	result.minute = timeStruct.tm_min;
	result.second = timeStruct.tm_sec;

	return result;
}