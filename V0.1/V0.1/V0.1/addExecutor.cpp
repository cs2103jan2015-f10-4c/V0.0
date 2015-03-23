#include "addExecutor.h"

addExecutor::addExecutor(void){}

addExecutor::~addExecutor(void){}

void addExecutor::addTask(string taskTitle, string startTime, string endTime) {
    taskList = storage.getTaskList();
    Task tempStorage;
    tempStorage.taskName = taskTitle;
    //tempStorage.date = taskDate;
    tempStorage.startingTime = startTime;
    tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
    taskList.push_back(tempStorage);
	updateStorage();
    //displayAll();
}

void addExecutor::addDeadlineTask(string taskTitle, string endTime) {
	deadlineList = storage.getDeadlineTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "None";
	tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
	deadlineList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	updateDeadlineStorage();
	updateStorage();
	//displayDeadline();
	//displayAll();
}

void addExecutor::addFloatingTask(string taskTitle) {
	floatingList = storage.getFloatingTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "Not specified";
	tempStorage.endingTime = "Not specified";
	tempStorage.status = DEFAULT_TASK_STATUS;
	floatingList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	updateFloatingStorage();
	updateStorage();
	//displayFloating();
	//displayAll();
}
