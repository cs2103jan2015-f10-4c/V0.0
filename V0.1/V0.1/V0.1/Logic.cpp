

#include "Logic.h"


Logic::Logic(){}
Logic::~Logic(){}


/*void Logic::retriveStorage(){
	storage.readFile();
}*/
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
}// take not of default return type ??? exceptions 


void Logic::addTask(){
	string taskType = parse.getTaskType();
	//cout << taskType; test passed
	if (taskType == "timed") {
		string taskName = parse.getTaskName();
		string startTime = parse.getStartTime();
		string endTime = parse.getEndTime();
		add.addTask(taskName, startTime, endTime, taskType, taskList);
	} else if (taskType == "deadline") {
		string taskName = parse.getTaskName();
		//cout << taskName; passed
		string endTime = parse.getEndTime();
		//cout << endTime; debugged
		add.addDeadlineTask(taskName, endTime, taskType, deadlineList,taskList);
	} else if (taskType == "floating") {
		string taskName = parse.getTaskName();
		add.addFloatingTask(taskName, taskType, floatingList, taskList);
	}
	history.saveOperation(taskList);
	response.addResponse();
	disp.setDefaultDisplay(taskList);
	storage.saveFile(taskList);
}

void Logic::deleteTask() {
	bool isCorrectIndex = false;
	int index = parse.getIndex();
	if (checkIndex(index)) {
		isCorrectIndex = true;
	    deleteATask.deleteTask(index, taskList);
	    history.saveOperation(taskList);
		response.deleteResponse(isCorrectIndex, index);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.deleteResponse(isCorrectIndex, index);
	}
}

void Logic::editTask(){
	bool isCorrectIndex = false;
	int index = parse.getIndex();
	if (checkIndex(index)) {
		isCorrectIndex = true;
	    string newTaskName = parse.getTaskName();
	    string newStartTime = parse.getStartTime();
	    string newEndTime = parse.getEndTime();
	    edit.editTask(index, newTaskName, newStartTime, newEndTime, taskList);
	    history.saveOperation(taskList);
		response.editResponse(isCorrectIndex, index);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.editResponse(isCorrectIndex, index);
	}
}

void Logic::searchTask(){
	string keyPhrase = parse.getSearchWord();
	disp.setDefaultDisplay(search.searchTask(keyPhrase, taskList));
	
}

void Logic::markDoneTask(){
	bool isCorrectIndex = false;
	int index = parse.getIndex();
	if (checkIndex(index)) {
		isCorrectIndex = true;
	    mark.markDoneTask(index, taskList);
	    history.saveOperation(taskList);
		response.markDoneResponse(isCorrectIndex, index);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.markDoneResponse(isCorrectIndex, index);
	}
}

void Logic::undoTask(){
	bool isSuccessful = false;
	isSuccessful = history.checkUndoEmpty();
	if (isSuccessful) {
		taskList = history.undo();
		response.undoResponse(isSuccessful);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.undoResponse(isSuccessful);
	}
}

void Logic::redoTask(){
	bool isSuccessful = false;
	isSuccessful = history.checkRedoEmpty();
	if (isSuccessful) {
		taskList = history.redo();
		response.redoResponse(isSuccessful);
	    disp.setDefaultDisplay(taskList);
	    storage.saveFile(taskList);
	} else {
		response.redoResponse(isSuccessful);
	}
}

void Logic::display(){
	string displayType = parse.getTaskType();
	bool isCorrectType = true;
	isCorrectType = disp.setVariousDisplay(taskList, displayType);
	if (!isCorrectType) {
		response.dispVariousResponse(isCorrectType);
	}
}

string Logic::tellGUI(){
	return disp.getContent();
}

bool checkIndex(int index) {
	for (int i = 0; i < taskList.size(); i++) {
		if (index == i + 1) {
			return true;
		} else {
			return false;
		}
	}
}