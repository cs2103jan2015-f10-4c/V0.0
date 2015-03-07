//@author A0101014L
// WWTask.cpp

#include <string>
#include <cassert>
#include "WWTask.h"
#include "WWTaskTime.h"
#include "WWUtilities.h"

using namespace std;

WWTask::WWTask() {
	_isDone = false;
	_isOverdue = false;
	_isToday = false;
}

void WWTask::setTaskName(string inputTaskName) {
	_taskName = inputTaskName;
}

void WWTask::setStartDate(string inputDate) {
	_startDate = inputDate;
}

void WWTask::setStartTime(string inputTime) {
	_startTime = inputTime;
}

void WWTask::setEndDate(string inputDate) {
	_endDate = inputDate;
}

void WWTask::setEndTime(string inputTime) {
	_endTime = inputTime;
}

void WWTask::setStatus(bool inputStatus) {
	_isDone = inputStatus;
}
	
bool WWTask::hasTaskName() {
	return (!_taskName.empty());
}

bool WWTask::hasStartDate() {
	return (!_startDate.empty());
}

bool WWTask::hasStartTime() {
	return (!_startTime.empty());
}

bool WWTask::hasEndDate() {
	return (!_endDate.empty());
}

bool WWTask::hasEndTime() {
	return (!_endTime.empty());
}

string WWTask::getTaskName() {
	return _taskName;
}

string WWTask::getStartDate() {
	return _startDate;
}

string WWTask::getStartTime() {
	return _startTime;
}

string WWTask::getEndDate() {
	return _endDate;
}

string WWTask::getEndTime() {
	return _endTime;
}

bool WWTask::getStatus() {
	return _isDone;
}

bool WWTask::checkOverdue() {
	refresh();
	return _isOverdue;
}

bool WWTask::checkToday() {
	refresh();
	return _isToday;
}

WWUtilities::TaskType WWTask::getTaskType() {
	refresh();
	return _taskType;
}

//refresh is used to update _taskType, _isOverdue and _isToday which are determined by other date and time fields
//these three attributes are not set by users, but only updated with private methods
void WWTask::refresh() {
	updateTaskType();

	if(_taskType == WWUtilities::TIMED) {
		rearrangeDateTime();
	}

	if(_taskType != WWUtilities::FLOATING) {
		_isOverdue = _taskTime.isOverdue(_startDate, _startTime);
		_isToday = _taskTime.isToday(_startDate);
	}
}

//update _taskType attribute of a WWTask object, depending on the date and time attributes it has
//i.e. a WWTask object without a start date and an end date will be classified as a FLOATING task
void WWTask::updateTaskType() {
	if(!hasStartDate() && !hasStartTime() && !hasEndDate() && !hasEndTime()) {
		_taskType = WWUtilities:: FLOATING;
	}

	if(hasStartDate() && !hasEndDate()) {
		_taskType = WWUtilities:: DEADLINE;   //we store the deadline date in _startDate, deadline time in _startTime
	}

	if(hasStartDate() && hasEndDate()) {
		_taskType = WWUtilities:: TIMED;
	}
}

//make sure that the end date of a TIMED task is always later than its start date
//if a TIMED task starts and ends on the same day, the end time should always be later than the start time
void WWTask::rearrangeDateTime() {
	int startDateInt = stringToInt(_startDate);
	int endDateInt = stringToInt(_endDate);

	if(startDateInt > endDateInt) {
		string temp;
		
		temp       = _startDate;
		_startDate = _endDate;
		_endDate   = temp;

		if(!_endTime.empty()) {
			temp       = _startTime;
			_startTime = _endTime;
			_endTime   = temp;
		}
	} 
	
	if(startDateInt == endDateInt) {
		int startTimeInt = stringToInt(_startTime);
		int endTimeInt   = stringToInt(_endTime);

		if(startTimeInt > endTimeInt) {
			string temp;
		
			temp       = _startTime;
			_startTime = _endTime;
			_endTime   = temp;
		}
	}

	startDateInt = stringToInt(_startDate);
	endDateInt   = stringToInt(_endDate);

	assert(startDateInt <= endDateInt);  //_startDate must be earlier or equal to _endDate after this rearrange method
}

int WWTask::stringToInt(string inputString) {
	return atoi(inputString.c_str());
}