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

class editExecutor{
private:
   
	static string DEFAULT_TASK_STATUS;

public:
  
    editExecutor();
    ~editExecutor();
    void editTask(int, string, string, string, string, vector<Task>&);
};

#endif
