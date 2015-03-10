#infdef EDITEXECUTOR_H_
#define EDITEXECUTOR_H_

#include <vector>
#include <algorithm>
#include "Parser.h"
#include "Storage.h"
#include "Display.h"
#include "Task.h"

using namespace std;

class editExecutor{

public:
    editExecutor(void);
    ~editExecutor(void);
    void editTaskTitle(int, string);
    void editTaskDate(int, string);
    void editTaskStartTime(int, string);
    void editTaskDuration(int, string);
    
private:
    vector<Task> taskStorage;
};
#endif
