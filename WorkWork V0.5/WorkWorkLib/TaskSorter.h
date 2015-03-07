//@author A0105476E

//*********************************************************
//			         Class TaskSorter
//					  Author: AI YUE
//
//					File: TaskSorter.h
//
// TaskSorter class is used to sort a task vector by time
// Sample usage: 
//		TaskSorter::taskSorter = TaskSorter::getInstance();
//		taskSorter.sortTask(taskStorage);
//*********************************************************

#ifndef TASKSORTER_H
#define TASKSORTER_H

#include <vector>
#include "WWTask.h"

class TaskSorter{
public:
	static TaskSorter& getInstance() {
		static TaskSorter instance;
		return instance;
	}

	// this method sort the tasks inside the vector passed in according to time
	// 1. all the completed tasks will be put at the end
	// 2. floating tasks will be put behind timed and deadline tasks
	// 3. timed and deadline tasks will be sorted according to time
	void sortTask(std::vector<WWTask>&);

private:
	TaskSorter();
};

#endif
