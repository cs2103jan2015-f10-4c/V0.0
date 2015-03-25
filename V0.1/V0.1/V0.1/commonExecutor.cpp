#include "commonExecutor.h"

commonExecutor::commonExecutor(void){}

commonExecutor::~commonExecutor(void){}

void commonExecutor::updateStorage(){
    storage.updateTaskList(taskList);
}
