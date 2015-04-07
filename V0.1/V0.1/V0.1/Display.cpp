//@ author A0116363L

#include "Display.h"

const string Display::FLOATING_TASK ="floating";
const string Display::DEADLINE_TASK="deadline";
const string Display::TIMED_TASK="timed";
const string Display::OVERDUE_TASK="overdue";
const string Display::DONE_TASK="done";
const string Display::ONGOING_TASK="ongoing";
const string Display::ALL_TASK = "all";
const string Display::INVALID_DISPLAYTYPE= "This display type is invalid";
const string Display::NO_DEADLINE ="There is no deadline task";
const string Display::NO_TIMED="There is no timed task";
const string Display::NO_FLOATING="There is no floating task";
const string Display::NO_DONE="There is no done task";
const string Display::NO_OVERDUE="There is no overdue task";
const string Display::NO_ONGOING = "There is no ongoing task";
const string Display::DISPLAYED = "The target tasklist has been displayed";


Display::Display(){}

Display::~Display(){}


void Display::setDefaultDisplay(vector<Task> &taskList){
	_mainDisplay.setContent(taskList);
	return;
}

string Display::setVariousDisplay(vector<Task>& taskList,string displayType){
	vector<Task> targetTasklist;
	if (displayType ==FLOATING_TASK){
		targetTasklist = getFloatingTask(taskList);
		_mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_FLOATING;
		}
	}
	else if (displayType ==DEADLINE_TASK){
		targetTasklist = getDeadlineTask(taskList);
		_mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_DEADLINE;
		}
	}
	else if (displayType == TIMED_TASK){
		targetTasklist = getTimedTask(taskList);
		_mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_TIMED;
		}
	}
	else if (displayType == OVERDUE_TASK){
		targetTasklist = getOverdueTask(taskList);
		_mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_OVERDUE;
		}
	}
	else if (displayType == DONE_TASK){
		targetTasklist = getDoneTask(taskList);
		_mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_DONE;
		}
	}
	else if (displayType == ONGOING_TASK){
		targetTasklist = getOngoingTask(taskList);
        _mainDisplay.setContent(targetTasklist);
		if (targetTasklist.empty()){
			return NO_ONGOING;
		}
	}
	else if (displayType == ALL_TASK){
		targetTasklist = taskList;
		_mainDisplay.setContent(targetTasklist);

	}
	else{
		return INVALID_DISPLAYTYPE;
	}
	return DISPLAYED;
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