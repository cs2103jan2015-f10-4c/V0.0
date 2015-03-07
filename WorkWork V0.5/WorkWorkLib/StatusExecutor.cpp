//@author A0105476E

//*****************************************************************
//					  Author: AI YUE
//
//					File: StatusExecutor.cpp
//*****************************************************************

#include <vector>
#include "WWDisplay.h"
#include "WWTask.h"
#include "WWUtilities.h"
#include "TaskSorter.h"
#include "StatusExecutor.h"

StatusExecutor::StatusExecutor(void){
}

void StatusExecutor::markDone(std::vector<WWTask>& taskStorage, unsigned int index, WWUtilities::PageType pageType, WWDisplay& display){
	bool markStatus = false;
	std::string taskName;
	TaskSorter taskSorter = TaskSorter::getInstance();

	if((!taskStorage.empty()) && (index >= 0) && (index < taskStorage.size())) {
		taskName = taskStorage[index].getTaskName();
		if(!taskStorage[index].getStatus()) {
			taskStorage[index].setStatus(true);
			markStatus = true;
		}	
	}
	
	taskSorter.sortTask(taskStorage);

	display.setMainDisplay(taskStorage, pageType);
	display.setSystemResponse(WWUtilities::DONE, taskName, markStatus);
};

void StatusExecutor::markUndone(std::vector<WWTask>& taskStorage, unsigned int index, WWUtilities::PageType pageType, WWDisplay& display){
	bool markStatus = false;
	std::string taskName;
	TaskSorter taskSorter = TaskSorter::getInstance();

	if((!taskStorage.empty()) && (index >= 0) && (index < taskStorage.size())) {
		taskName = taskStorage[index].getTaskName();
		if(taskStorage[index].getStatus()) {
			taskStorage[index].setStatus(false);
			markStatus = true;
		}	
	}
	
	taskSorter.sortTask(taskStorage);

	display.setMainDisplay(taskStorage, pageType);
	display.setSystemResponse(WWUtilities::UNDONE, taskName, markStatus);
};