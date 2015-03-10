#include "searchExecutor.h"

searchExecutor::searchExecutor(void){
}

void searchExecutor::searchTask(string keyPhrase, Display& display){
    taskList = storage.getTaskList();
    for (int i=0; i < taskList.size(); i++) {
        if (taskList[i].taskName.compare(keyPhrase) == 0) {
            searchResult.push_back(taskList[i]);
        }
    }
    display.displayRequired(searchResult);
}
