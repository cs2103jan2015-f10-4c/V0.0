#ifndef SEARCHEXECUTOR_H_
#define SEARCHEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
/*#include "Storage.h"
#include "History.h"*/
#include "Task.h"

using namespace std;

class searchExecutor{
private:
   /* Storage storage;
	History history;
	Task task;*/
	
public:
    //vector<Task> taskList;
    searchExecutor();
    ~searchExecutor();
    vector<Task> searchTask(string, vector<Task>&);
	string getSearchedResult(vector<Task>);
};

#endif
