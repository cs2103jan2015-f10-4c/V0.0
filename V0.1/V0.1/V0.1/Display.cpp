#include "Display.h"

const string FLOATING_TASK ="floating";
const string DEADLINE_TASK="deadline";
const string TIMED_TASK="timed";
const string OVERDUE_TASK="overdue";
const string DONE_TASK="done";
const string ONGOING_TASK="ongoing";

Display::Display(){}

Display::~Display(){}


void Display::setDefaultDisplay(){
	vector<Task> taskList = storage.getTaskList();
	_mainDisplay.setContent(taskList);
	return;
}

void Display::setVariousDisplay(string displayType){
	vector<Task> taskList = storage.getTaskList();
	if (displayType == FLOATING_TASK){
		_mainDisplay.setContent(getFloatingTask());
	}
	else if (displayType == DEADLINE_TASK){
		_mainDisplay.setContent(getDeadlineTask());
	}
	else if (displayType == TIMED_TASK){
		_mainDisplay.setContent(getTimedTask());
	}
	else if (displayType == OVERDUE_TASK){
		_mainDisplay.setContent(getOverdueTask(taskList));
	}
	else if (displayType == DONE_TASK){
		_mainDisplay.setContent(getDoneTask(taskList));
	}
	else if (displayType == ONGOING_TASK){
		_mainDisplay.setContent(getOngoingTask(taskList));
	}
}

vector<Task>Display::getFloatingTask(){
	vector<Task> sortedFloatingTaskList;
	vector<Task> floatingTaskList;
	floatingTaskList = storage.getFloatingTaskList();
	sortedFloatingTaskList = sorter.sortFloatingTaskList(floatingTaskList);


	return sortedFloatingTaskList;
}



vector<Task>Display::getDeadlineTask(){
	vector<Task> deadlineTaskList;
	vector<Task> sortedDeadlineTaskList;
	deadlineTaskList = storage.getDeadlineTaskList();
	sortedDeadlineTaskList = sorter.sortDeadlineTaskList(deadlineTaskList);

	return sortedDeadlineTaskList;
}

vector<Task>Display::getTimedTask(){
	vector<Task> timedTaskList;
	vector<Task> sortedTimedTaskList;
	timedTaskList = storage.getTimedTaskList();
	sortedTimedTaskList = sorter.sortTimedTaskList(timedTaskList);

	return sortedTimedTaskList;

}

vector<Task>Display::getOverdueTask(vector<Task> tasklist){
	vector<Task> overdueTaskList;
	vector<Task> sortedOverdueTaskList;

	for (int i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == "overdue")
			overdueTaskList.push_back(tasklist[i]);
	}
	sortedOverdueTaskList = sorter.sortOverdueTaskList(overdueTaskList);

	return sortedOverdueTaskList;
}

vector<Task>Display::getDoneTask(vector<Task> tasklist){
	vector<Task> doneTaskList;
	vector<Task> sortedDoneTaskList;

	for (int i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == "done")
			doneTaskList.push_back(tasklist[i]);
	}
	sortedDoneTaskList = sorter.sortDoneTaskList(doneTaskList);

	return sortedDoneTaskList;
}

vector<Task>Display::getOngoingTask(vector<Task> tasklist){
	vector<Task> ongoingTaskList;
	vector<Task> sortedOngoingTaskList;

	for (int i = 0; i < tasklist.size(); i++){
		if (tasklist[i].status == "ongoing")
			ongoingTaskList.push_back(tasklist[i]);
	}
	sortedOngoingTaskList = sorter.sortOngoingTaskList(ongoingTaskList);

	return sortedOngoingTaskList;
}


