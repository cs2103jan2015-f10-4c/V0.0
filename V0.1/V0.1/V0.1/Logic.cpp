

#include "Logic.h"


Logic::Logic(){}
Logic::~Logic(){}


void Logic::retriveStorage(){
	storage.readFile();
}
void Logic::executeUserCommand(string userInput){
	string commandWord;
	commandWord = parse.getCommandWord(userInput);
	//cout << commandWord; test passed
	COMMAND_TYPE commandType;
	commandType = determineCommandType(commandWord);
	switch (commandType) {
	case _ADD:
		return addTask();
	case _DELETE:
		return deleteTask();
	case _EDIT:
		return editTask();
	case _SEARCH:
		return searchTask();
	case _MARKDONE:
		return markDoneTask();
	case _DISPLAY:
		return display();
	case _UNDO:
		return undoTask();
	case _REDO:
		return redoTask();
	default:
		break;
	}
}


Logic:: COMMAND_TYPE Logic::determineCommandType(string commandWord){
	if (commandWord == "Add" || commandWord == "add") {
		return COMMAND_TYPE::_ADD;
	} else if (commandWord == "Delete" || commandWord == "delete") {
		return COMMAND_TYPE::_DELETE;
	} else if (commandWord == "Edit" || commandWord == "edit") {
		return COMMAND_TYPE::_EDIT;
	} else if (commandWord == "Search" || commandWord == "search") {
		return COMMAND_TYPE::_SEARCH;
	} else if (commandWord == "Mark done" || commandWord == "mark done" || commandWord == "mark") {
		return COMMAND_TYPE::_MARKDONE;
	} else if (commandWord == "Display" || commandWord == "display") {
		return COMMAND_TYPE::_DISPLAY;
	} else if (commandWord == "Undo" || commandWord == "undo") {
		return COMMAND_TYPE::_UNDO;
	} else if (commandWord == "Redo" || commandWord == "redo") {
		return COMMAND_TYPE::_REDO;
	}
}


void Logic::addTask(){
	string taskType = parse.getTaskType();
	//cout << taskType; test passed
	if (taskType == "timed") {
		string taskName = parse.getTaskName();
		string startTime = parse.getStartTime();
		string endTime = parse.getEndTime();
		add.addTask(taskName, startTime, endTime, taskType);
	} else if (taskType == "deadline") {
		string taskName = parse.getTaskName();
		//cout << taskName; passed
		string endTime = parse.getEndTime();
		//cout << endTime; debugged
		add.addDeadlineTask(taskName, endTime, taskType);
	} else if (taskType == "floating") {
		string taskName = parse.getTaskName();
		add.addFloatingTask(taskName, taskType);
	}
	history.saveOperation(taskList);
	disp.setDefaultDisplay(taskList);
}

void Logic::deleteTask(){
	int index = parse.getIndex();
	deleteATask.deleteTask(index, taskList);
	history.saveOperation(taskList);
	disp.setDefaultDisplay(taskList);
}

void Logic::editTask(){
	int index = parse.getIndex();
	string newTaskName = parse.getTaskName();
	string newStartTime = parse.getStartTime();
	string newEndTime = parse.getEndTime();
	edit.editTask(index, newTaskName, newStartTime, newEndTime, taskList);
	history.saveOperation(taskList);
	disp.setDefaultDisplay(taskList);
}

void Logic::searchTask(){
	string keyPhrase = parse.getSearchWord();
	disp.setDefaultDisplay(search.searchTask(keyPhrase, taskList));
	
}

void Logic::markDoneTask(){
	int index = parse.getIndex();
	mark.markDoneTask(index, taskList);
	history.saveOperation(taskList);
	disp.setDefaultDisplay(taskList);
}

void Logic::undoTask(){
	taskList = history.undo();
	disp.setDefaultDisplay(taskList);
}

void Logic::redoTask(){
	taskList = history.redo();
	disp.setDefaultDisplay(taskList);
}

void Logic::display(){
	string displayType = parse.getTaskType();
	disp.setVariousDisplay(taskList, displayType);
}
