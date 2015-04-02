

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
	case _DIRECTORY:
		return getDirectory();
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
	bool isAdded = true;
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
	response.addResponse(isAdded);
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
		string newTaskType = parse.getTaskType();
	    edit.editTask(index, newTaskName, newStartTime, newEndTime, newTaskType, taskList);
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
	bool isEmptyList = checkFoundList(search.searchTask(keyPhrase, taskList));
	if (isEmptyList) {
		response.searchResponse(isEmptyList);
	} else {
		disp.setDefaultDisplay(search.searchTask(keyPhrase, taskList));
	}
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
	//bool isCorrectType = true;
	string outputMsg = disp.setVariousDisplay(taskList, displayType);
	response.dispVariousResponse(outputMsg);
}

string Logic::tellGUI(){
	return disp.getContent();
}

string Logic::tellGUIResponse() {
	return response.tellResponse();
}

void Logic::checkDirectory() {
	bool hasDirectory;
	hasDirectory = storage.hasDirectory();
	if (hasDirectory) {
		response.welcomeExistingMessage();
		storage.readFile(taskList);
	} else {
		response.noDirectoryResponse();
	}
}

void Logic::getDirectory() {
	struct stat sb;
		string pathname;
	do {
		response.invalidDirectoryResponse();
		pathname = parse.getTaskType();
		storage.setUserInputPath(pathname);
		storage.readFile(taskList);
		}
		while (stat(pathname.c_str(), &sb) != 0 || !(S_IFDIR & sb.st_mode));
}

bool Logic::checkIndex(int index) {
	for (unsigned i = 0; i < taskList.size(); i++) {
		if (i == index-1) {
			return true;
		} else {
			return false;
		}
	}
}

void Logic::refreshStatus() {
	checker.updateStatus(taskList);
}

bool Logic::checkFoundList(vector<Task> foundList) {
	if (foundList.size() == 0) {
		return true;
	} else {
		return false;
	}
}