#ifndef DELETEEXECUTOR_H_
#define DELETEEXECUTOR_H_

#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

class deleteExecutor{
private:
  
public:
   
    deleteExecutor();
    ~deleteExecutor();
	void deleteTask(int, vector<Task>&);
    
};
#endif
