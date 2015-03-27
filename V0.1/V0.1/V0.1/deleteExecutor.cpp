#include "deleteExecutor.h"

deleteExecutor::deleteExecutor(void){}

deleteExecutor::~deleteExecutor(void){}

void deleteExecutor::deleteTask(int index){
     taskList = storage.getTaskList();
    /*if (index > taskList.size()) {
        display::displayError();
    }
    
    else {
        string deletedText;
		deletedText = taskList[index - 1];*/
		taskList.erase(taskList.begin() + (index - 1));
		executor.updateStorage(taskList);
		storage.saveOperation();
    cout << "Task " << index << " is deleted!" << endl;
    //displayAll();
}
