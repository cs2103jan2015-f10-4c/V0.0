//@author A0116363L

#include "timeChecker.h"
#include "Logger.h"

const string TimeChecker::NON_TARGET_TYPE = "floating";
const string TimeChecker::STATUS_OVERDUE = "overdue";
const string TimeChecker::STATUS_ONGOING = "ongoing";
const string TimeChecker::MESSAGE_MARKOVERDUE = "Task\"%s\" is marked as overdue";

TimeChecker::TimeChecker(){};
TimeChecker::~TimeChecker(){};


//To update non-floating and ongoing task's status if it is overdue
//logger is used to keep track which task is marked as overdue 
void TimeChecker::updateStatus(vector<Task>& tasklist){
	RHLogger logger = RHLogger::getInstance();

	for (unsigned i = 0; i < tasklist.size(); i++){
		if (tasklist[i].type != NON_TARGET_TYPE){
			if (checkStatus(tasklist[i].endingTime) && tasklist[i].status == STATUS_ONGOING){
				tasklist[i].status = STATUS_OVERDUE;
				string indexString = to_string(i);
				sprintf_s(outputBuffer, MESSAGE_MARKOVERDUE.c_str(), indexString.c_str());
				logger.addLog(outputBuffer);
				logger.saveLog();
			}
		}
	}
}

//To compare current time with endingTime of a task
//If the time is passed, the task is said to be overdue
bool TimeChecker::checkStatus(string endingTime){

	bool isOverdue = false;
	string currentTime = transformTime.getCurrentTime();
	time_t currentT = transformTime.stringToTime(currentTime);
	time_t endTime = transformTime.stringToTime(endingTime);
	if (currentT > endTime){
		isOverdue = true;
	}
	return isOverdue;
}    


