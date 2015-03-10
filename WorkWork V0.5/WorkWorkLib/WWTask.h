//@author A0101014L
//WWTask.h

#ifndef WWTASK_H
#define WWTASK_H

#include <string>
#include "WWTaskTime.h"
#include "WWUtilities.h"

//WWTask is used to encapsulate the details of a task.
//By encapsulating the task details, WWTask is able to provide relevant information through the public methods

class WWTask {
public:

	WWTask();
	//field setters
	void setTaskName(std::string);
	void setStartDate(std::string);
	void setStartTime(std::string);
	void setEndDate(std::string);
	void setEndTime(std::string);
	void setStatus(bool);
	//to check if fields are empty
	bool hasTaskName();
	bool hasStartDate();
	bool hasStartTime();
	bool hasEndDate();
	bool hasEndTime();
	//field getters
	std::string getTaskName();
	std::string getStartDate();
	std::string getStartTime();
	std::string getEndDate();
    std::string getEndTime();
	bool        getStatus();
	bool        checkOverdue();
	bool        checkToday();
	WWUtilities::TaskType getTaskType();
	
private:

	std::string _taskName;
	std::string _startDate;
	std::string _startTime;
	std::string _endDate;
	std::string _endTime;
	bool        _isDone;
	bool        _isOverdue;
	bool        _isToday;

	WWUtilities::TaskType _taskType;
	WWTaskTime _taskTime;

	void refresh();
	void updateTaskType();
	void rearrangeDateTime();
	int  stringToInt(std::string);
};
#endif
