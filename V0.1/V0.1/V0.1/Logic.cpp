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

void Logic::addDeadlineTask(string taskTitle, string endTime) {
	deadlineList = storage.getDeadlineTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "";
	tempStorage.endingTime = endTime;
	deadlineList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	updateDeadlineStorage();
	displaySpecified(deadlineList);
}

void Logic::addFloatingTask(string taskTitle) {
	floatingList = storage.getFloatingTaskList();
	taskList = storage.getTaskList();
	Task tempStorage;
	tempStorage.taskName = taskTitle;
	tempStorage.startingTime = "";
	tempStorage.endingTime = "";
	floatingList.push_back(tempStorage);
	taskList.push_back(tempStorage);
	updateFloatingStorage();
	updateStorage();
	displaySpecified(floatingList);
}


void Logic::updateStorage() {
    storage.updateTaskList (taskList);
}

void Logic::updateDeadlineStorage() {
	storage.updateDeadlineTaskList(deadlineList);
}

void Logic::updateFloatingStorage() {
	storage.updateFloatingTaskList(floatingList);
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
    cout << setw(10);
    cout << "Editted result: " << taskList[index - 1].taskName << setw(30) << taskList[index - 1].startingTime << setw(30) << taskList[index - 1].endingTime << endl;
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
		cout << setw(10);
        cout << i + 1 << "." << taskList[i].taskName << setw(30) << taskList[i].startingTime << setw(30) << taskList[i].endingTime << endl;
	}
}

void Logic::displaySpecified(vector<Task> List) {
	for (int i = 0; i < List.size(); i++) {
		cout << setw(10);
        cout << i + 1 << "." << List[i].taskName << setw(30) << List[i].startingTime << setw(30) << List[i].endingTime << endl;
	}
}
