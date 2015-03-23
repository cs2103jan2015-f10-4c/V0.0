#ifndef EDITEXECUTOR_H_
#define EDITEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Storage.h"
#include "History.h"
#include "Task.h"

using namespace std;

class editExecutor{
private:
    Storage storage;
	History history;
	Task task;
	
public:
    vector<Task> taskList;
    editExecutor();
    ~editExecutor();
    void editTask(int, string, string, string);
};

#endif
