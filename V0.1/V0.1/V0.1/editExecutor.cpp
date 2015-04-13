#include "editExecutor.h"

string EditExecutor::DEFAULT_TASK_STATUS = "ongoing";

EditExecutor::EditExecutor(void) {}

EditExecutor::~EditExecutor(void) {}

void EditExecutor::editTask(int index, string newTaskName, string newStartTime, string newEndTime, string newTaskType, vector<Task>& taskList) {
	
	taskList[index - 1].taskName = newTaskName;
	taskList[index - 1].startingTime = newStartTime;
	taskList[index - 1].endingTime = newEndTime;
	taskList[index - 1].type = newTaskType;
	taskList[index - 1].status = DEFAULT_TASK_STATUS;

}
