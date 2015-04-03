#ifndef COMMONEXECUTOR_H_
#define COMMONEXECUTOR_H_

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

class commonExecutor{
private:
    Storage storage;
public: 
    //vector<Task> taskList;
    commonExecutor();
    ~commonExecutor();
    void updateStorage(vector<Task>);
};
#endif
