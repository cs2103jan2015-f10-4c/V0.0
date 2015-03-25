

#include "Logic.h"

string Logic::executeUserCommand(string userInput){
	string commandWord;
	commandWord = parser.getCommandWord(userInput);
	COMMAND_TYPE commandType;
	commandType = determineCommandType(commandWord);
	switch (commandType) {
	case ADD:
		return addTask();
	case DELETE:
		return deleteTask();
	case EDIT:
		return editTask();
	case SEARCH:
		return searchTask();
	case MARKDONE:
		return markDoneTask();
	case DISPLAY:
		return display();
	case UNDO:
		return undoTask();

COMMAND_TYPE Logic::determineCommandType(string commandWord){
	if (commandWord == "Add" || commandType == "add") {
		return COMMAND_TYPE::ADD;
	} else if (commandWord == "Delete" || commandType == "delete") {
		return COMMAND_TYPE::DELETE;
	} else if (commandType == "Edit" || commandType == "edit") {
		return COMMAND_TYPE::EDIT;
	} else if (commandWord == "Search" || commandWord == "search") {
		return COMMAND_TYPE::SEARCH;
	} else if (commandWord == "Mark done" || commandWord == "mark done" || commandWord == "mark") {
		return COMMAND_TYPE::MARKDONE;
	} else if (commandWord == "Display" || commandWord == "display") {
		return COMMAND_TYPE::DISPLAY;
	} else if (commandWord == "Undo" || commandWord == "undo") {
		return COMMAND_TYPE::UNDO;
	} else if (commandWord == "Redo" || commandWord == "redo") {
		return COMMAND_TYPE::REDO;
	}
}

void Logic::addTask(){
	string taskType = parser.getTaskType();
	if (taskType == "Timed") {
		string taskName = parser.getTaskName();
		string startTime = parser.getStartTime();
		string endTime = parser.getEndTime();
		add.addTask(taskName, startTime, endTime, taskType);
	} else if (taskType == "Deadline") {
		string taskName = parser.getTaskName();
		string endTime = parser.getEndTime();
		add.addDeadlineTask(taskName, endTime, taskType);
	} else if (taskType == "Floating") {
		string taskName == parser.getTaskName();
		add.addFloatingTask(taskName, taskType);
	}
}

void Logic::deleteTask(){
	int index = parser.getIndex();
	deleteTask.deleteTask(index);
}

void Logic::editTask(){
	int index = parser.getIndex();
	newTaskName = parser.getTaskName();
	newStartTime = parser.getStartTime();
	newEndTime = parser.getEndTime();
	edit.editTask(index, newTaskName, newStartTime, newEndTime);
}

void Logic::searchTask(){
	string keyPhrase = parser.getSearchWord();
	search.searchTask(keyPhrase);
}

void Logic::markDoneTask(){
	int index = parser.getIndex();
	mark.markDone(index);
}

void Logic::display(){
	string displayType = parser.getTaskType();
	if (displayType == "timed") {
		disp.displayTimed();
	} else if (displayType == "deadline") {
		disp.displayDeadline();
	} else if (displayType == "floating") {
		disp.displayFloating();
	} else if (displayType == "ongoing") {
		disp.displayOngong();
	} else if (displayType == "done") {
		disp.displayDone();
	} else if (displayType == "overdue") {
		disp.displayOverdue();
	}
}