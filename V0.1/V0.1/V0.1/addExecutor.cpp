#include "addExecutor.h"

string addExecutor::DEFAULT_TASK_STATUS = "Ongoing";

addExecutor::addExecutor(void){}

addExecutor::~addExecutor(void){}

void addExecutor::addTask(string taskTitle, string startTime, string endTime, string taskType) {
    taskList = storage.getTaskList();
    Task tempStorage;
    tempStorage.taskName = taskTitle;
    //tempStorage.date = taskDate;
    tempStorage.startingTime = startTime;
    tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
	tempStorage.type = taskType;
    taskList.push_back(tempStorage);
	executor.updateStorage();
	storage.saveOperation();
    //displayAll();
}

void addExecutor::addDeadlineTask(string taskTitle, string endTime, string taskType) {
	deadlineList = storage.getDeadlineTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "None";
	tempStorage.endingTime = endTime;
	tempStorage.status = DEFAULT_TASK_STATUS;
	tempStorage.type = taskType;
	deadlineList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	//updateDeadlineStorage();
	executor.updateStorage();
	storage.saveOperation();
	//displayDeadline();
	//displayAll();
}

void addExecutor::addFloatingTask(string taskTitle, string taskType) {
	floatingList = storage.getFloatingTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "Not specified";
	tempStorage.endingTime = "Not specified";
	tempStorage.type = taskType;
	tempStorage.status = DEFAULT_TASK_STATUS;
	floatingList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	//updateFloatingStorage()t
	executor.updateStorage(taskList);
	storage.saveOperation();
	//displayFloating();
	//displayAll();
}
