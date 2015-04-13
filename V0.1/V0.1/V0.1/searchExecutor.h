#ifndef SEARCHEXECUTOR_H_
#define SEARCHEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

//SearchExecutor class is used to perform actions related to search.
//This class takes in keyword that is specified by user from logic
//This class also takes in the taskList from logic and use find function to search relevant result
//This class only supports search according to keyword which is taskName, but not according to time
//Partial search is supported

class SearchExecutor {
private:
  	
public:
    SearchExecutor();
    ~SearchExecutor();
    vector<Task> searchTask(string, vector<Task>&);
	string getSearchedResult(vector<Task>);
};

#endif
