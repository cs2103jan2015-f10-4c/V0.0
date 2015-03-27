#include "commonExecutor.h"

commonExecutor::commonExecutor(void){}

commonExecutor::~commonExecutor(void){}

void commonExecutor::updateStorage(vector<Task> tasklist){
    storage.updateTaskList(tasklist);
}
