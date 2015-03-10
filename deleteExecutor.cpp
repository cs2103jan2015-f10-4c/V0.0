#include "deleteExecutor.h"

deleteExecutor::deleteExecutor(void){
}

void deleteExecutor::deleteTask(size_t index, Display& display, Storage& storage) {
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

void deleteExecutor::updateStorage(vector<Task> taskList, Storage& storage) {
    storage.updateFile (taskList);
}
