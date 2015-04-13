#ifndef ADDEXECUTOR_H_
#define ADDEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

//AddExecutor class is used to perform actions related to add.
//This class includes add functions of three different types of tasks: timed, deadline and floating
//Each of these functions has return type: void 
//All of them take in respective informations related to a task such as taskName, startingTime, endingTime, taskType from logic
//All of them taske in taskList from logic and make direct modifications in taskList.

class AddExecutor{
private:
	
	static string DEFAULT_TASK_STATUS;
	static string EMPTY_STRING;

public:
	
	AddExecutor();
	~AddExecutor();
	void addTimedTask(string, string, string, string, vector<Task>&);
	void addDeadlineTask(string, string, string, vector<Task>&, vector<Task>&);
	void addFloatingTask(string, string, vector<Task>&, vector<Task>&);

};
#endif
