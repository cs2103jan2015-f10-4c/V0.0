#include "editExecutor.h"

editExecutor::editExecutor(void){
}

void editExecutor::editTaskTitle(int index, string newName){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newName;
}

void editExecutor::editTaskDate(int index, string newDate){
    taskList = storage.getTaskList();
    taskList[index+1].taskDate = newDate;
}
    
void editExecutor::editTaskStartingTime(int index, string newStartingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newStartingTime;
}
    
void editExecutor::editTaskEndingTime(int index, string newEndingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newEndingTime;
}
