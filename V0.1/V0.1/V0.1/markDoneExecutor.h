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

class markDoneExecutor{
private:
   
public:
   
    markDoneExecutor();
    ~markDoneExecutor();
    void markDoneTask(int, vector<Task>&);
};

#endif
