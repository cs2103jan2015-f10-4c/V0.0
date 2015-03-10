#infdef EDITEXECUTOR_H_
#define EDITEXECUTOR_H_

#include <vector>
#include <algorithm>
#include "Parser.h"
#include "Storage.h"
#include "Display.h"
#include "Task.h"

class editExecutor{

public:
    editExecutor(void);
    ~editExecutor(void);
    void editTask(int);
    
private:
    vector<Task> taskStorage;
};
#endif
