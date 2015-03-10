#ifndef SEARCHEXECUTOR_H_
#define SEARCHEXECUTOR_H_

#include <vector>
#include <string>
#include <
#include "Display.h"
#include "Task.h"
#include "Storage.h"

using namespace std;

class searchExecutor{

public:
    searchExecutor(void);
    ~searchExecutor(void);
    
    void searchTask(string, Display&);
    
private:
    vector<Task> taskList;
    vector<Task> searchResult;
};
#endif
