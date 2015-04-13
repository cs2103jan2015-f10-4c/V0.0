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
