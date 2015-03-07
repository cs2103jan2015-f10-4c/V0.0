//@author A0101014L
// WWTaskTime.cpp

#include "WWTaskTime.h"
#include "WWUtilities.h"
#include "WWConverter.h"
#include <string>
#include <cassert>

using namespace std;

WWTaskTime::WWTaskTime() {
}

//we define overdue tasks as follows
//a FLOATING task will never be overdue
//a DEADLINE task is overdue when its deadline is earlier than the current system date(time)
//a TIMED task is overdue when its start date(time) is earlier than the current system time
//if there is no start time for a TIMED task and its start date is today, it is not overdue
bool WWTaskTime::isOverdue(string startDate, string startTime) {
	string curDate;
	string curTime;
	WWConverter converter;

	assert(!startDate.empty());  //startDate must not be empty

	WWUtilities& Time = WWUtilities::getInstance();  //retrieving system date and time

	// extract the components needed from system date and time
	int curMin  = Time.getCurrentMinute();
	int curHr   = Time.getCurrentHour();
	int curDay  = Time.getCurrentDay();
	int curMon  = Time.getCurrentMonth();
	int curYear = Time.getCurrentYear();

	converter.convertIntDateToString(curDay, curMon, curYear, curDate);
	converter.convertIntTimeToString(curHr, curMin, curTime);

	//convert integer string to integer for easier comparison
	int curDateInt = atoi(curDate.c_str());
	int curTimeInt = atoi(curTime.c_str());

	int startDateInt = atoi(startDate.c_str());
	int startTimeInt = atoi(startTime.c_str());

	_overdue = false;
	if(startDateInt < curDateInt) {
		_overdue = true;
	} 
	if((startDateInt == curDateInt) && (!startTime.empty()) && (startTimeInt < curTimeInt)) {
		_overdue = true;
	}

	return _overdue;
}

//we define today tasks as follows
//a FLOATING task is not a today task
//a DEADLINE task is a today task if its deadline date is current system date
//a TIMED task is a today task if its start date is current system date
bool WWTaskTime::isToday(string startDate) {
	string curDate;
	WWConverter converter;

	assert(!startDate.empty());  //startDate must not be empty

	WWUtilities& Time = WWUtilities::getInstance();  //retrieving system date and time

	// extract the components needed from system date and time
	int curMin  = Time.getCurrentMinute();
	int curHr   = Time.getCurrentHour();
	int curDay  = Time.getCurrentDay();
	int curMon  = Time.getCurrentMonth();
	int curYear = Time.getCurrentYear();

	converter.convertIntDateToString(curDay, curMon, curYear, curDate);

	//convert integer string to integer for easier comparison
	int curDateInt   = atoi(curDate.c_str());
	int startDateInt = atoi(startDate.c_str());

	_today = (startDateInt == curDateInt); 

	return _today;
}