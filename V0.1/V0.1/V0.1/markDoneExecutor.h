#ifndef MARKDONEEXECUTOR_H_
#define MARKDONEEXECUTOR_H_

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
#include "commonExecutor.h"

using namespace std;

class markDoneExecutor{
private:
    Storage storage;
	History history;
	Task task;
	commonExecutor executor;

public:
    vector<Task> taskList;
    vector<Task> deadlineList;
    vector<Task> floatingList;
    markDoneExecutor();
    ~markDoneExecutor();
    void markDoneTask(int);
};

#endif
