#include "Display.h"

/*const string FLOATING_TASK ="floating";
const string DEADLINE_TASK="deadline";
const string TIMED_TASK="timed";
const string OVERDUE_TASK="overdue";
const string DONE_TASK="done";
const string ONGOING_TASK="ongoing";
*/
Display::Display(){}

Display::~Display(){}


void Display::setDefaultDisplay(vector<Task> &taskList){
	_mainDisplay.setContent(taskList);
	return;
}

void Display::setVariousDisplay(vector<Task>& taskList,string displayType){
	
	if (displayType =="floating"){
		_mainDisplay.setContent(getFloatingTask(taskList));
	}
	else if (displayType == "deadline"){
		_mainDisplay.setContent(getDeadlineTask(taskList));
	}
	else if (displayType == "timed"){
		_mainDisplay.setContent(getTimedTask(taskList));
	}
	else if (displayType == "overdue"){
		_mainDisplay.setContent(getOverdueTask(taskList));
	}
	else if (displayType == "done"){
		_mainDisplay.setContent(getDoneTask(taskList));
	}
	else if (displayType =="ongoing"){
		_mainDisplay.setContent(getOngoingTask(taskList));
	}
}

vector<Task>Display::getFloatingTask(vector<Task> taskList){
	vector<Task> sortedFloatingTaskList;
	vector<Task> floatingTaskList;
	for (int i = 0; i < taskList.size(); i++){
		if (taskList[i].type == "floating"){
			floatingTaskList.push_back(taskList[i]);
		}
	}
	sortedFloatingTaskList = sorter.sortFloatingTaskList(floatingTaskList);

	return sortedFloatingTaskList;
}



vector<Task>Display::getDeadlineTask(vector<Task> taskList){
	vector<Task> deadlineTaskList;
	vector<Task> sortedDeadlineTaskList;
	for (int i = 0; i < taskList.size(); i++){
		if (taskList[i].type == "deadline"){
			deadlineTaskList.push_back(taskList[i]);
		}
	}
	sortedDeadlineTaskList = sorter.sortDeadlineTaskList(deadlineTaskList);

	return sortedDeadlineTaskList;
}

vector<Task>Display::getTimedTask(vector<Task> taskList){
	vector<Task> timedTaskList;
	vector<Task> sortedTimedTaskList;
	for (int i = 0; i < taskList.size(); i++){
		if (taskList[i].type == "floating"){
			timedTaskList.push_back(taskList[i]);
		}
	}
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


