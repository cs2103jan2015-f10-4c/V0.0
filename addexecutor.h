#ifndef ADDEXECUTOR_H_
#define ADDEXECUTOR_H_

#include <iostream>
#include <vector>
#include <string>
#include "Task.h"
#include "Logic.h"
#include "Storage.h"
#include "Display.h"

using namespace std;

class addExecutor { 
    
public:
    
    addExecutor(void);
    ~addExecutor(void);
    
    void addTask(string, string, string, string, vector<Task>&, Storage&, Display&);
    void updateStorage(vector<Task>&, Storage&);
    
private:
    vector<Task> taskList;
};
#endif
