#ifndef ADDEXECUTOR_H_
#define ADDEXECUTOR_H_

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

class addExecutor{
private:
	Storage storage;
	History history;
	Task task;

public:
	vector<Task> taskList;
    vector<Task> deadlineList;
    vector<Task> floatingList;
	addExecutor();
	~addExecutor();
	void addTask(string, string, string);
	void addDeadlineTask(string, string);
	void addFloatingTask(string);

};
#endif
