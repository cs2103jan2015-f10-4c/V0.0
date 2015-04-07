#include "searchExecutor.h"

searchExecutor::searchExecutor(void){}

searchExecutor::~searchExecutor(void){}

vector<Task> searchExecutor::searchTask(string  keyPhrase, vector<Task>& taskList){
	vector<Task> searchResult;
   // taskList = storage.getTaskList();
    for (unsigned i=0; i < taskList.size(); i++) {
		size_t found = taskList[i].taskName.find(keyPhrase);
		if (found != std::string::npos){
            searchResult.push_back(taskList[i]);
        }
    }
	return searchResult;
    //displaySpecified(searchResult);
}

string searchExecutor::getSearchedResult(vector<Task> searchResult){
	if (searchResult.size() == 0) {
		return "";//return something else instead;
	} else {
		for (unsigned i = 0; i < searchResult.size(); i++) {
			return searchResult[i].ToString();
		}
	}
}   


