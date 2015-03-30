#include "Display.h"

const string Display::FLOATING_TASK ="floating";
const string Display::DEADLINE_TASK="deadline";
const string Display::TIMED_TASK="timed";
const string Display::OVERDUE_TASK="overdue";
const string Display::DONE_TASK="done";
const string Display::ONGOING_TASK="ongoing";

Display::Display(){}

Display::~Display(){}


void Display::setDefaultDisplay(vector<Task> &taskList){
	_mainDisplay.setContent(taskList);
	return;
}

void Display::setVariousDisplay(vector<Task>& taskList,string displayType){
	
	if (displayType ==FLOATING_TASK){
		_mainDisplay.setContent(getFloatingTask(taskList));
	}
	else if (displayType ==DEADLINE_TASK){
		_mainDisplay.setContent(getDeadlineTask(taskList));
	}
	else if (displayType == TIMED_TASK){
		_mainDisplay.setContent(getTimedTask(taskList));
	}
	else if (displayType == OVERDUE_TASK){
		_mainDisplay.setContent(getOverdueTask(taskList));
	}
	else if (displayType == DONE_TASK){
		_mainDisplay.setContent(getDoneTask(taskList));
	}
	else if (displayType ==ONGOING_TASK){
		_mainDisplay.setContent(getOngoingTask(taskList));
	}
}

vector<Task>Display::getFloatingTask(vector<Task> taskList){
	vector<Task> sortedFloatingTaskList;
	vector<Task> floatingTaskList;
	for (unsigned i = 0; i < taskList.size(); i++){
		if (taskList[i].type == FLOATING_TASK){
			floatingTaskList.push_back(taskList[i]);
		}
	}
	sortedFloatingTaskList = sorter.sortFloatingTaskList(floatingTaskList);

	return sortedFloatingTaskList;
}



vector<Task>Display::getDeadlineTask(vector<Task> taskList){
	vector<Task> deadlineTaskList;
	vector<Task> sortedDeadlineTaskList;
	for (unsigned i = 0; i < taskList.size(); i++){
		if (taskList[i].type == DEADLINE_TASK){
			deadlineTaskList.push_back(taskList[i]);
		}
	}
	sortedDeadlineTaskList = sorter.sortDeadlineTaskList(deadlineTaskList);

	return sortedDeadlineTaskList;
}

vector<Task>Display::getTimedTask(vector<Task> taskList){
	vector<Task> timedTaskList;
	vector<Task> sortedTimedTaskList;
	for (unsigned i = 0; i < taskList.size(); i++){
		if (taskList[i].type == TIMED_TASK){
			timedTaskList.push_back(taskList[i]);
		}
	}
	sortedTimedTaskList = sorter.sortTimedTaskList(timedTaskList);

	return sortedTimedTaskList;

}

vector<Task>Display::getOverdueTask(vector<Task> tasklist){
	vector<Task> overdueTaskList;
	vector<Task> sortedOverdueTaskList;

	for (unsigned i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == OVERDUE_TASK)
			overdueTaskList.push_back(tasklist[i]);
	}
	sortedOverdueTaskList = sorter.sortOverdueTaskList(overdueTaskList);

	return sortedOverdueTaskList;
}

vector<Task>Display::getDoneTask(vector<Task> tasklist){
	vector<Task> doneTaskList;
	vector<Task> sortedDoneTaskList;

	for (unsigned i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == DONE_TASK)
			doneTaskList.push_back(tasklist[i]);
	}
	sortedDoneTaskList = sorter.sortDoneTaskList(doneTaskList);

	return sortedDoneTaskList;
}

vector<Task>Display::getOngoingTask(vector<Task> tasklist){
	vector<Task> ongoingTaskList;
	vector<Task> sortedOngoingTaskList;

	for (unsigned i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == ONGOING_TASK)
			ongoingTaskList.push_back(tasklist[i]);
	}
	sortedOngoingTaskList = sorter.sortOngoingTaskList(ongoingTaskList);

	return sortedOngoingTaskList;
}


string Display::getContent(){
	return _mainDisplay.getContent();
}