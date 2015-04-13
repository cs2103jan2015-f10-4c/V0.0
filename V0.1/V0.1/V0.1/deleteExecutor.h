#ifndef DELETEEXECUTOR_H_
#define DELETEEXECUTOR_H_

#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Task.h"

using namespace std;

//DeleteExecutor class is used to perform delete related actions
//This class has function to take in index of the task to be deleted from logic
//It also take in taskList from logic and will delete the specified task from the list directly.

class DeleteExecutor{
private:
  
public:
   
    DeleteExecutor();
    ~DeleteExecutor();
	void deleteTask(int, vector<Task>&);
    
};
#endif
