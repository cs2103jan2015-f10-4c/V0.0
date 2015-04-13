//@author A0115404W

#ifndef MARKDONEEXECUTOR_H_
#define MARKDONEEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

//MarkDoneExecutor class is used to perform actions related to mark done
//This class takes in index of the task to be marked done and the taskList from the logic
//Status of the task specified will be modified directly in the list.

class MarkDoneExecutor {

private:
   
public:
   
    MarkDoneExecutor();
    ~MarkDoneExecutor();
    void markDoneTask(int, vector<Task>&);
};

#endif
