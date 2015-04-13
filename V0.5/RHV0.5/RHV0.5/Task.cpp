//@author A0115404W

#include "Task.h"
#include <string>


Task::Task(){
}

Task::~Task(){}

void Task::setTaskName(string inputTaskName) {
	taskName = inputTaskName;
}

void Task::setStartingTime(string inputStartingTime) {
	startingTime = inputStartingTime;
}

void Task::setEndingTime(string inputEndingTime) {
	endingTime = inputEndingTime;
}

void Task::setDone(string inputDone) {
	status = inputDone;
}

void Task::setType(string inputType) {
	type = inputType;
}

string Task::ToString() {
	ostringstream oss;
	oss << taskName <<" from "<< startingTime <<" to "<<endingTime<<" "<<status<<" "<<type <<"\n";

	return oss.str();
}
