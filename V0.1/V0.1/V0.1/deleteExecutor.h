#ifndef DELETEEXECUTOR_H_
#define DELETEEXECUTOR_H_

#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Storage.h"
#include "History.h"
#include "Task.h"

using namespace std;

class deleteExecutor{
private:
    Storage storage;
	History history;
	Task task;

public:
    deleteExecutor();
    ~deleteExecutor();
    void deleteTask(int);
    
};
#endif
