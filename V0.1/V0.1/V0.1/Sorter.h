
//@author A0116363L

#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>
#include "Task.h"
#include <algorithm>
#include "TransformTime.h"

class Sorter{
private:



public:

	vector<Task> sortFloatingTaskList(vector<Task>);
	vector<Task> sortDeadlineTaskList(vector<Task>);
	vector<Task> sortTimedTaskList(vector<Task>);
	vector<Task> sortDoneTaskList(vector<Task>);
	vector<Task> sortOverdueTaskList(vector<Task>);
	vector<Task> sortOngoingTaskList(vector<Task>);
};

#endif