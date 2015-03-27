#include "markDoneExecutor.h"

markDoneExecutor::markDoneExecutor(void){}

markDoneExecutor::~markDoneExecutor(void){}

void markDoneExecutor::markDoneTask(int index){
    taskList = storage.getTaskList();
	deadlineList = storage.getDeadlineTaskList();
	floatingList = storage.getFloatingTaskList();
	string doneTaskTitle = taskList[index - 1].taskName;
	taskList[index - 1].status = "Done";
	executor.updateStorage(taskList);
	storage.saveOperation();

	//update respective task in deadlineList:
	/*for (int i = 0; i < deadlineList.size(); i++) {
		if (deadlineList[i].taskName == doneTaskTitle) {
			deadlineList[i].status = "Done";
			updateDeadlineStorage();
		} 
	}

	//update respective task in floatingList:
	for (int j = 0; j < floatingList.size(); j++) {
		if (floatingList[j].taskName == doneTaskTitle) {
			floatingList[j].status = "Done";
			updateFloatingStorage();
		}
	}*/

}
