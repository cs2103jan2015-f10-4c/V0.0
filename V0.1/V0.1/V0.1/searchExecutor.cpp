#include "searchExecutor.h"

searchExecutor::searchExecutor(void){}

searchExecutor::~searchExecutor(void){}

void searchExecutor::searchTask(string  keyPhrase){
	vector<Task> searchResult;
    taskList = storage.getTaskList();
    for (int i=0; i < taskList.size(); i++) {
        if (taskList[i].taskName.compare(keyPhrase) == 0) {
            searchResult.push_back(taskList[i]);
        }
    }
    //displaySpecified(searchResult);
}
