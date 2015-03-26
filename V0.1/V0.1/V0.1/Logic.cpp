

#include "Logic.h"

Logic:: COMMAND_TYPE Logic::determineCommandType(string commandWord){
    if (commandWord == "Add" || commandWord == "add") {
        return COMMAND_TYPE::ADD;
    } else if (commandWord == "Delete" || commandWord == "delete") {
        return COMMAND_TYPE::DELETE;
    } else if (commandWord == "Edit" || commandWord == "edit") {
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
    }  else return COMMAND_TYPE::ERROR;
}

void Logic::executeUserCommand(string userInput){
	string commandWord;
	commandWord = parse.getCommandWord(userInput);
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
	case REDO:
		return redoTask();
	default:
		break;
	}
}

<<<<<<< HEAD

=======

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

>>>>>>> 723c00640015219699b2d4ce36c6cbe5bcca1fc0

void Logic::addTask(){
	string taskType = parse.getTaskType();
	if (taskType == "Timed") {
		string taskName = parse.getTaskName();
		string startTime = parse.getStartTime();
		string endTime = parse.getEndTime();
		add.addTask(taskName, startTime, endTime, taskType);
	} else if (taskType == "Deadline") {
		string taskName = parse.getTaskName();
		string endTime = parse.getEndTime();
		add.addDeadlineTask(taskName, endTime, taskType);
	} else if (taskType == "Floating") {
		string taskName = parse.getTaskName();
		add.addFloatingTask(taskName, taskType);
	}
}

void Logic::deleteTask(){
	int index = parse.getIndex();
	deleteATask.deleteTask(index);
}

void Logic::editTask(){
	int index = parse.getIndex();
	string newTaskName = parse.getTaskName();
	string newStartTime = parse.getStartTime();
	string newEndTime = parse.getEndTime();
	edit.editTask(index, newTaskName, newStartTime, newEndTime);
}

void Logic::searchTask(){
	string keyPhrase = parse.getSearchWord();
	search.searchTask(keyPhrase);
}

void Logic::markDoneTask(){
	int index = parse.getIndex();
	mark.markDoneTask(index);
}

void Logic::undoTask(){
	storage.undo();
	taskList = storage.getTaskList();
	disp.setDefaultDisplay();
}

void Logic::redoTask(){
	storage.redo();
	taskList = storage.getTaskList();
	disp.setDefaultDisplay();
}

void Logic::display(){
	string displayType = parse.getTaskType();
	disp.setVariousDisplay(displayType);
}
