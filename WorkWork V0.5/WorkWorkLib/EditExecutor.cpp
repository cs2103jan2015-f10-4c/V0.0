//@author A0105476E

//**************************************************************
//					  Author: AI YUE
//
//					File: EditExecutor.cpp
//**************************************************************

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"
#include "WWUtilities.h"
#include "TaskSorter.h"
#include "EditExecutor.h"

EditExecutor::EditExecutor(void){
}

void EditExecutor::editTask(std::vector<WWTask>& taskStorage, unsigned int index, WWTask newTask, WWUtilities::PageType pageType, WWDisplay& display){
	bool editStatus = false;
	std::string taskName;
	TaskSorter taskSorter = TaskSorter::getInstance();

	if((!taskStorage.empty()) && (index >= 0) && (index < taskStorage.size())) {

		//if newTask has taskName, overwrite the taskname using the taskName in newTask
		if(newTask.hasTaskName()){                                       
			taskStorage[index].setTaskName(newTask.getTaskName());		
		}

		//if newTask has startDate, overwrite the startDate using the startDate of newTask
		if(newTask.hasStartDate()){                                    
			taskStorage[index].setStartDate(newTask.getStartDate());	
		}

		//if newTask has startTime, overwrite the startTime using the startTime of newTask
		if(newTask.hasStartTime()){
			taskStorage[index].setStartTime(newTask.getStartTime());	
		}

		//if newTask has endDate, overwrite the endDate using the endDate of newTask
		if(newTask.hasEndDate()){
			taskStorage[index].setEndDate(newTask.getEndDate());		
		}

		//if newTask has endTime, overwrite the endTime using the endTime of newTask
		if(newTask.hasEndTime()){
			taskStorage[index].setEndTime(newTask.getEndTime());		
		}

		editStatus = true;

		taskName = taskStorage[index].getTaskName();
	}

	//sort the taskStorage after editing
	taskSorter.sortTask(taskStorage);

	display.setMainDisplay(taskStorage, pageType);
	display.setSystemResponse(WWUtilities::EDIT, taskName, editStatus);
}
