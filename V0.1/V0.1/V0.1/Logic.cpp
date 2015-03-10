#include "Logic.h"

Logic::addTask(string taskName, string taskDate, string startTime, string duration, Storage& storage, Display& display) {
    taskList = storage.getTaskStorage();
    Task tempStorage;
    tempStorage.taskDescription = taskName;
    tempStorage.date = taskDate;
    tempStorage.startingTime = startTime;
    tempStorage.duration = duration;
    taskList.push_back(tempStorage);
}

Logic::updateStorage(vector<Task> taskList, Storage& storage) {
    storage.updateFile (taskList);
}

Logic::deleteTask(size_t index, Display& display, Storage& storage) {
    taskList = storage.getTaskStorage();
    if (index > taskList.size()) {
        display::displayError();
    }
    
    else {
        string deletedText;
		deletedText = taskList[index - 1];
		taskList.erase(taskList.begin() + (index - 1));
    }
    display.displayAll(vector<Task> taskList);
}

Logic::editTaskTitle(int index, string newName){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newName;
}

Logic::editTaskDate(int index, string newDate){
    taskList = storage.getTaskList();
    taskList[index+1].taskDate = newDate;
}

Logic::editTaskStartingTime(int index, string newStartingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newStartingTime;
}

Logic::editTaskEndingTime(int index, string newEndingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newEndingTime;
}

Logic::searchTask(string keyPhrase, Display& display){
    taskList = storage.getTaskList();
    for (int i=0; i < taskList.size(); i++) {
        if (taskList[i].taskName.compare(keyPhrase) == 0) {
            searchResult.push_back(taskList[i]);
        }
    }
    display.displayRequired(searchResult);
}
