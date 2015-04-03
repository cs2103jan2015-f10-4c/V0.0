#include "timeChecker.h"

const string TimeChecker::NON_TARGET_TYPE = "floating";
const string TimeChecker::STATUS_OVERDUE = "overdue";


TimeChecker::TimeChecker(){};
TimeChecker::~TimeChecker(){};


void TimeChecker::updateStatus(vector<Task>& tasklist){

	for (unsigned i = 0; i < tasklist.size(); i++){
		if (tasklist[i].type != NON_TARGET_TYPE){
			if (checkStatus(tasklist[i].endingTime) && tasklist[i].status!="done"){
				tasklist[i].status = STATUS_OVERDUE;
			}
		}
	}


}

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


