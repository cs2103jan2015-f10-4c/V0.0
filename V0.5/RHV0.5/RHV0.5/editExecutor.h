//@author A0115404W

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

using namespace std;

//EditExecutor class is used to perform actions related to edit
//This class has function to take in index of a task and relevant information has been modified by the user
//This class takes in the taskList from logic and makes modification directly in the list

class EditExecutor{
private:
   
	static string DEFAULT_TASK_STATUS;

public:
  
    EditExecutor();
    ~EditExecutor();
    void editTask(int, string, string, string, string, vector<Task>&);
};

#endif
