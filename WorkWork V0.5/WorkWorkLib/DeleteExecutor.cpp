//@author A0105476E

//*************************************************************************
//					          Author: AI YUE
//
//					      File: DeleteExecutor.cpp
//*************************************************************************

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"
#include "WWStorage.h"
#include "WWUtilities.h"
#include "TaskSorter.h"
#include "DeleteExecutor.h"

DeleteExecutor::DeleteExecutor(void){
}

void DeleteExecutor::deleteTask(std::vector<WWTask>& taskStorage, unsigned int index, WWUtilities::PageType pageType, WWDisplay& display){
	bool deleteStatus = false;
	string taskName;
	 
	//check whether the index is valid
	if(index >= 0 && index < taskStorage.size()){
		taskName = taskStorage[index].getTaskName();
		taskStorage.erase(taskStorage.begin() + index);

		deleteStatus = true;
	}

	//pageType in display will stay in the original page
	display.setMainDisplay(taskStorage, pageType);
	display.setSystemResponse(WWUtilities::DELETE, taskName, deleteStatus);
}
