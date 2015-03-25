

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

	TransformTime time;
	vector<Task> sortFloatingTaskList(vector<Task>);
	vector<Task> sortDeadlineTaskList(vector<Task>);
	vector<Task> sortTimedTaskList(vector<Task>);
	vector<Task> sortDoneTaskList(vector<Task>);
	vector<Task> sortOverdueTaskList(vector<Task>);
	vector<Task> sortOngoingTaskList(vector<Task>);

	bool cmpEndingTime(Task, Task);
	bool cmpName(Task, Task);
	bool cmpStartingTime(Task, Task);

};

#endif