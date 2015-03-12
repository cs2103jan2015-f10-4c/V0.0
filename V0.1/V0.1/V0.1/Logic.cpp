#include "Logic.h"



Logic::Logic(void){}

Logic::~Logic(void){}

void Logic::addTask(string taskTitle, string startTime, string endTime) {
    taskList = storage.getTaskList();
    Task tempStorage;
    tempStorage.taskName = taskTitle;
    //tempStorage.date = taskDate;
    tempStorage.startingTime = startTime;
    tempStorage.endingTime = endTime;
    taskList.push_back(tempStorage);
    updateStorage();
    displayAll();
}

void Logic::updateStorage() {
    storage.updateTaskList (taskList);
}

void Logic::deleteTask(int index) {
    taskList = storage.getTaskList();
    /*if (index > taskList.size()) {
        display::displayError();
    }
    
    else {
        string deletedText;
		deletedText = taskList[index - 1];*/
		taskList.erase(taskList.begin() + (index - 1));
		updateStorage();
    
    displayAll();
}

void Logic::editTask(int index, string newTaskName, string newStartTime, string newEndTime){
	taskList = storage.getTaskList();
	taskList[index - 1].taskName = newTaskName;
	taskList[index - 1].startingTime = newStartTime;
	taskList[index - 1].endingTime = newEndTime;

	updateStorage();
    cout << "Editted result: " << taskList[index - 1].taskName << taskList[index - 1].startingTime << taskList[index - 1].endingTime << endl;
    displayAll();

}


/*void Logic::editTaskTitle(int index, string newName){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newName;
	//updateStorage();
}

/*Logic::editTaskDate(int index, string newDate){
    taskList = storage.getTaskList();
    taskList[index+1].taskDate = newDate;
}*/

/*void Logic::editTaskStartTime(int index, string newStartingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newStartingTime;
	//updateStorage();
}

void Logic::editTaskEndTime(int index, string newEndingTime){
    taskList = storage.getTaskList();
    taskList[index+1].taskName = newEndingTime;
	//updateStorage();
}*/

void Logic::searchTask(string keyPhrase){
	vector<Task> searchResult;
    taskList = storage.getTaskList();
    for (int i=0; i < taskList.size(); i++) {
        if (taskList[i].taskName.compare(keyPhrase) == 0) {
            searchResult.push_back(taskList[i]);
        }
    }
    displaySpecified(searchResult);
}

void Logic::displayAll() {
	taskList = storage.getTaskList();
	for (int i = 0; i < taskList.size(); i++) {
		cout << i + 1 << "." << taskList[i].taskName << taskList[i].startingTime << taskList[i].endingTime << endl;
	}
}

void Logic::displaySpecified(vector<Task> List) {
	for (int i = 0; i < List.size(); i++) {
		cout << i + 1 << "." << List[i].taskName << List[i].startingTime << List[i].endingTime << endl;
	}
}
