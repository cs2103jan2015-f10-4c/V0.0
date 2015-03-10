#include "display.h"

Display::display(void){
}

void Display::displayAll() {
    vector<Task> taskStorage;
    taskStorage = storage.getTaskList();
    int lineNumber = 1;

	if (taskStorage.empty()) {
		cout << "File is empty" << endl;   //error message
	}
	else {
		for (size_t i = 0; i < taskStorage.size(); i++) {
			cout << lineNumber << "." << taskStorage[i] << endl;
			lineNumber++;
            }
	}
}

void Display::displayRequired(vector<Task> taskList){
    for (int i = 0; i < taskList.size(); i++) {
        cout << i+1 << "." << taskList[i] << endl;
    }
}
