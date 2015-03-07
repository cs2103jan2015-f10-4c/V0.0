//@author A0105476E

//**********************************************************
//					  Author: AI YUE
//
//					File: AddExecutor.cpp
//**********************************************************

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"
#include "WWUtilities.h"
#include "TaskSorter.h"
#include "AddExecutor.h"

AddExecutor::AddExecutor(void){
}


void AddExecutor::addTask(std::vector<WWTask>& taskStorage, WWTask newTask, WWDisplay& display) {
	bool addStatus = false;
	std::string taskName;
	TaskSorter& taskSorter = TaskSorter::getInstance();

	if(newTask.hasTaskName()) {
		taskStorage.push_back(newTask);
		taskName = newTask.getTaskName();
		addStatus = true;
	}

	//auto sort the taskList after added in the new task
	taskSorter.sortTask(taskStorage);

	//pageType in display will be set to PAGEALL
	display.setMainDisplay(taskStorage, WWUtilities::PAGEALL);
	display.setSystemResponse(WWUtilities::ADD, taskName, addStatus);
}