#ifndef SEARCHEXECUTOR_H_
#define SEARCHEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

class searchExecutor{
private:
  	
public:
    searchExecutor();
    ~searchExecutor();
    vector<Task> searchTask(string, vector<Task>&);
	string getSearchedResult(vector<Task>);
};

#endif
