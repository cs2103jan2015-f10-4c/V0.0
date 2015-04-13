#include "deleteExecutor.h"

DeleteExecutor::DeleteExecutor(void) {}

DeleteExecutor::~DeleteExecutor(void) {}

void DeleteExecutor::deleteTask(int index, vector<Task>& taskList) {
   
		taskList.erase(taskList.begin() + (index - 1));
	
}
