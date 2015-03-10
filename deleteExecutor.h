#ifndef DELETEEXECUTOR_H_
#define DELETEEXECUTOR_H_

#include <string>
#include <vector>
#include <algorithm>
#include "parser.h"
#include "Logic.h"
#include "Task.h"
#include "Display.h"
#include "Storage.h"


using namespace std;

class deleteExecutor {
    
public:
    deleteExecutor(void);
    ~deleteExecutor(void);
    
    void deleteTask(size_t index, Display&, Storage&);
    void updateStorage(vector<Task> taskList, Storage&);
    
private:
    vector<Task> taskList;
};
#endif
