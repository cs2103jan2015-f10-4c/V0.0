#include "editExecutor.h"

string editExecutor::DEFAULT_TASK_STATUS = "ongoing";

editExecutor::editExecutor(void){}

editExecutor::~editExecutor(void){}

void editExecutor::editTask(int index, string newTaskName, string newStartTime, string newEndTime, string newTaskType, vector<Task>& taskList){
	
	taskList[index - 1].taskName = newTaskName;
	taskList[index - 1].startingTime = newStartTime;
	taskList[index - 1].endingTime = newEndTime;
	taskList[index - 1].type = newTaskType;
	taskList[index - 1].status = DEFAULT_TASK_STATUS;

}
