#ifndef DEBUG_H_
#define DEBUG_H_

#ifdef _DEBUG
#define ASSERT(expression) onAssert((bool)(expression), #expression, __FILE__, __LINE__)
#else
#define ASSERT(expression)
#endif

void onAssert(bool value, const char * expression, const char * file, int line);
void assertWithMsg(bool value, const char * message);

#endif