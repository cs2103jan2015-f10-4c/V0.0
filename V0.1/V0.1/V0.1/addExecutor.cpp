//@author A0115404W

#include "addExecutor.h"

string AddExecutor::DEFAULT_TASK_STATUS = "ongoing";
string AddExecutor::EMPTY_STRING = "";

AddExecutor::AddExecutor(void) {}

AddExecutor::~AddExecutor(void) {}

void AddExecutor::addTimedTask(string taskTitle, string startTime, string endTime, string taskType, vector<Task>& taskList) {
    Task tempStorage;
    tempStorage.taskName = taskTitle;
    tempStorage.startingTime = startTime;
    tempStorage.endingTime = endTime;
    tempStorage.status = DEFAULT_TASK_STATUS;
    tempStorage.type = taskType;
    taskList.push_back(tempStorage);
   
}

void AddExecutor::addDeadlineTask(string taskTitle, string endTime, string taskType, vector<Task>& deadlineList, vector<Task>& taskList) {
	
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = EMPTY_STRING;
	tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
	tempStorage.type = taskType;
	deadlineList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	
}

void AddExecutor::addFloatingTask(string taskTitle, string taskType, vector<Task>& floatingList, vector<Task>& taskList) {
	
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = EMPTY_STRING;
	tempStorage.endingTime = EMPTY_STRING;
	tempStorage.type = taskType;
	tempStorage.status = DEFAULT_TASK_STATUS;
	floatingList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	
}
