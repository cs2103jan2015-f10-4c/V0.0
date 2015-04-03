#ifndef EDITEXECUTOR_H_
#define EDITEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"
/*#include "Storage.h"
#include "History.h"
#include "commonExecutor.h"*/

using namespace std;

class editExecutor{
private:
   /* Storage storage;
	History history;
	Task task;
	commonExecutor executor;*/
	static string DEFAULT_TASK_STATUS;

public:
   // vector<Task> taskList;
    editExecutor();
    ~editExecutor();
    void editTask(int, string, string, string, string, vector<Task>&);
};

#endif
