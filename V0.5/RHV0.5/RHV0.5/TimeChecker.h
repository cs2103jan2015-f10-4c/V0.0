

//@author A0116363L

#ifndef TIMECHECKER_H
#define TIMECHECKER_H
#include <time.h>
#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "TransformTime.h"


#define MAX_CHAR 255

//timeChecker is a class in charge of checking the endingTime of a task 
//against the system time and update the status to overdue accordingly. 
//The class is to support the refresh function of the program.
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