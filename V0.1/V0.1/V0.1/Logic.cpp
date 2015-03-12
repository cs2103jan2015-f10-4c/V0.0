#include "Logic.h"

string Logic::OPENNING_MSG_FOR_DEADLINETASK_DISPLAYING = "Deadline need to be met:\n";
string Logic::OPENING_MSG_FOR_FLOATINGTASK_DISPLAYING = "Floating Task:\n";
string Logic::DEFAULT_TASK_STATUS = "Ongoing";
string Logic::OPENING_MSG_FOR_SEARCH_RESULT = "Search result\n";

Logic::Logic(void){}

Logic::~Logic(void){}

void Logic::addTask(string taskTitle, string startTime, string endTime) {
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

void Logic::addDeadlineTask(string taskTitle, string endTime) {
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

void Logic::addFloatingTask(string taskTitle) {
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
    cout << "Task " << index << " is deleted!" << endl;
    //displayAll();
}

void Logic::editTask(int index, string newTaskName, string newStartTime, string newEndTime){
	taskList = storage.getTaskList();
	taskList[index - 1].taskName = newTaskName;
	taskList[index - 1].startingTime = newStartTime;
	taskList[index - 1].endingTime = newEndTime;
	taskList[index - 1].status = DEFAULT_TASK_STATUS;


	updateStorage();
    cout << "Editted result: " << taskList[index - 1].taskName << setw(15) << taskList[index - 1].startingTime << setw(15) <<
		taskList[index - 1].endingTime << setw(15) << taskList[index - 1].status <<endl;
    //displayAll();

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

void Logic::sortTask() {}

void Logic::markdone(int index) {
	taskList = storage.getTaskList();
	deadlineList = storage.getDeadlineTaskList();
	floatingList = storage.getFloatingTaskList();
	string doneTaskTitle = taskList[index - 1].taskName;
	taskList[index - 1].status = "Done";
	updateStorage();

	//update respective task in deadlineList:
	for (int i = 0; i < deadlineList.size(); i++) {
		if (deadlineList[i].taskName == doneTaskTitle) {
			deadlineList[i].status = "Done";
			updateDeadlineStorage();
		} 
	}

	//update respective task in floatingList:
	for (int j = 0; j < floatingList.size(); j++) {
		if (floatingList[j].taskName == doneTaskTitle) {
			floatingList[j].status = "Done";
			updateFloatingStorage();
		}
	}

}


void Logic::displayAll() {
	taskList = storage.getTaskList();
	for (int i = 0; i < taskList.size(); i++) {
		cout << i + 1 << "." << taskList[i].taskName  << setw(15) << taskList[i].startingTime << setw(15) << 
			taskList[i].endingTime << setw(15) << taskList[i].status << endl;
	}
}

void Logic::displayDeadline() {
	deadlineList = storage.getDeadlineTaskList();
	cout << OPENNING_MSG_FOR_DEADLINETASK_DISPLAYING;
	for (int i = 0; i < deadlineList.size(); i++) {
		cout << "Task " << i + 1 << ": " << deadlineList[i].taskName << "is due by " << deadlineList[i].endingTime <<
			",\t" << deadlineList[i].status << endl;
	}
}

void Logic::displayFloating() {
	floatingList = storage.getFloatingTaskList();
	cout << OPENING_MSG_FOR_FLOATINGTASK_DISPLAYING;
	for (int i = 0; i < floatingList.size(); i++) {
		cout << "Task " << i + 1 << ": " << floatingList[i].taskName << setw(15) << floatingList[i].status << endl;
	}
}

void Logic::displaySpecified(vector<Task> List) {
	for (int i = 0; i < List.size(); i++) {
		cout << OPENING_MSG_FOR_SEARCH_RESULT;
		cout << i + 1 << "." << List[i].taskName << setw(15) << List[i].startingTime << setw(15) << 
			List[i].endingTime << setw(15) << List[i].status << endl;
	}
}
