#include "deleteExecutor.h"

deleteExecutor::deleteExecutor(void){}

deleteExecutor::~deleteExecutor(void){}

void deleteExecutor::deleteTask(int index, vector<Task>& taskList){
   
		taskList.erase(taskList.begin() + (index - 1));
	
}
