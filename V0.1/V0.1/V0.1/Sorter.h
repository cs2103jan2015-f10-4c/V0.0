
//@author A0116363L

#ifndef SORTER_H
#define SORTER_H

#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"
#include "TransformTime.h"

//This class is to sort the target list according a specific algorithm
//It is called when a specific display type is required
//Different type of tasks will be sorted differently
//For e.g Floating Ongoing Overdue Done tasks are sorted accroding to 
//alphabetical order of task name
//Deadline tasks are sorted according to ascending endingTime
//Timed tasks are sorted accordingt to ascending startingTime

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