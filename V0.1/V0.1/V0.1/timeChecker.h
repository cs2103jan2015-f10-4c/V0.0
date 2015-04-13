

//@author A0116363L

#ifndef TIMECHECKER_H
#define TIMECHECKER_H
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "TransformTime.h"
//#include 

#define MAX_CHAR 255

class TimeChecker{

private:
	TransformTime _transformTime;
	static const string NON_TARGET_TYPE;
	static const string STATUS_OVERDUE;
	static const string STATUS_ONGOING;
	static const string MESSAGE_MARKOVERDUE;
public:
	char outputBuffer[MAX_CHAR];
	void updateStatus(vector<Task>&);
	bool checkStatus(string);

	TimeChecker();
	~TimeChecker();
};

#endif