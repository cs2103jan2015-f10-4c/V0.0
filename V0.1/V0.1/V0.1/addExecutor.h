#ifndef ADDEXECUTOR_H_
#define ADDEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
//#include "Storage.h"
//#include "History.h"
#include "Task.h"
//#include "commonExecutor.h"

using namespace std;

class addExecutor{
private:
	/*Storage storage;
	History history;*/
	Task task;
	//commonExecutor executor;
	static string DEFAULT_TASK_STATUS;

public:
	vector<Task> taskList;
    /*vector<Task> deadlineList;
    vector<Task> floatingList;*/
	addExecutor();
	~addExecutor();
	void addTask(string, string, string, string, vector<Task>&);
	void addDeadlineTask(string, string, string, vector<Task>&, vector<Task>&);
	void addFloatingTask(string, string, vector<Task>&, vector<Task>&);

};
#endif
