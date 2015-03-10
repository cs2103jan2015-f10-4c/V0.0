#include <vector>
#include 'addExecutor.h'

addExecutor::addExecutor(void){
}

void addExecutor::addTask(string taskName, string taskDate, string startTime, string duration, Storage& storage, Display& display) {
    taskList = storage.getTaskStorage();
    Task tempStorage;
    tempStorage.taskDescription = taskName;
    tempStorage.date = taskDate;
    tempStorage.startingTime = startTime;
    tempStorage.duration = duration;
    taskList.push_back(tempStorage);
    
