#include "searchExecutor.h"

searchExecutor::searchExecutor(void){}

searchExecutor::~searchExecutor(void){}

void searchExecutor::searchTask(string  keyPhrase, vector<Task>& taskList){
	vector<Task> searchResult;
   // taskList = storage.getTaskList();
    for (int i=0; i < taskList.size(); i++) {
        if (taskList[i].taskName.compare(keyPhrase) == 0) {
            searchResult.push_back(taskList[i]);
        }
    }

    //displaySpecified(searchResult);
}

string searchExecutor::getSearchedResult(vector<Task> searchResult){
	if (searchResult.size() == 0) {
		return NULL;
	} else {
		for (int i = 0; i < searchResult.size(); i++) {
			return searchResult[i].ToString();
		}
	}
}


