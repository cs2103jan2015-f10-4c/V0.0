#include "markDoneExecutor.h"

MarkDoneExecutor::MarkDoneExecutor(void) {}

MarkDoneExecutor::~MarkDoneExecutor(void) {}

void MarkDoneExecutor::markDoneTask(int index, vector<Task>& taskList) {
   
	taskList[index - 1].status = "done";
	
}
