#include "markDoneExecutor.h"

markDoneExecutor::markDoneExecutor(void){}

markDoneExecutor::~markDoneExecutor(void){}

void markDoneExecutor::markDoneTask(int index, vector<Task>& taskList){
   
	taskList[index - 1].status = "done";
	
}
