#include "addExecutor.h"

string addExecutor::DEFAULT_TASK_STATUS = "ongoing";
string addExecutor::EMPTY_STRING = "";

addExecutor::addExecutor(void){}

addExecutor::~addExecutor(void){}

void addExecutor::addTimedTask(string taskTitle, string startTime, string endTime, string taskType, vector<Task>& taskList) {
    Task tempStorage;
    tempStorage.taskName = taskTitle;
    tempStorage.startingTime = startTime;
    tempStorage.endingTime = endTime;
    tempStorage.status = DEFAULT_TASK_STATUS;
    tempStorage.type = taskType;
    taskList.push_back(tempStorage);
   
}

void addExecutor::addDeadlineTask(string taskTitle, string endTime, string taskType, vector<Task>& deadlineList, vector<Task>& taskList) {
	
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = EMPTY_STRING;
	tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
	tempStorage.type = taskType;
	deadlineList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	
}

void addExecutor::addFloatingTask(string taskTitle, string taskType, vector<Task>& floatingList, vector<Task>& taskList) {
	
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = EMPTY_STRING;
	tempStorage.endingTime = EMPTY_STRING;
	tempStorage.type = taskType;
	tempStorage.status = DEFAULT_TASK_STATUS;
	floatingList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	
}
