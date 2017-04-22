#ifndef TM_H_
#define TM_H_

struct Time
{
	int year;		// years since 2000
	int month;		// [1, 12]
	int day;		// [1, 31]
	int hour;		// [0, 23]
	int minute;		// [0, 59]
	int second;		// [0, 59]
};

Time getTime();

#endif