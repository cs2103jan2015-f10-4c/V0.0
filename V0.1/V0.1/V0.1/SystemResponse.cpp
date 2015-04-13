#include "SystemResponse.h"

const string SystemResponse::MESSAGE_WELCOME = "Welcome to RushHour!";
const string SystemResponse::MESSAGE_WELCOME_EXISTING_USER = "Hi! Welcome back!";
const string SystemResponse::MESSAGE_ADD = "The task is added successfully.";
const string SystemResponse::MESSAGE_ADD_FAIL_INCORRECT_FORMAT = "Failed to add task. Please enter in the correct format.";
const string SystemResponse::MESSAGE_ADD_FAIL_INVALID_TIME = "Failed to add task. Starting time is later than ending time.";
const string SystemResponse::MESSAGE_DELETE = "Task %s is deleted successfully.";
const string SystemResponse::MESSAGE_DELETE_FAIL = "Failed to delete the task. Task \"%s\" is not in the list.";
const string SystemResponse::MESSAGE_EDIT = "Task %s is edited successfully.";
const string SystemResponse::MESSAGE_EDIT_FAIL = "Fail to edit task. Task \"%s\" is not in the list.";
const string SystemResponse::MESSAGE_MARK_DONE = "Task %s is done.";
const string SystemResponse::MESSAGE_MARK_DONE_FAIL = "Failed to mark done the task. Task\"%s\" is not in the list.";
const string SystemResponse::MESSAGE_MARK_DONE_FAIL_ALREADY_DONE = "Task %s is already done.";
const string SystemResponse::MESSAGE_SEARCH_FAIL = "There is no result found.";
const string SystemResponse::MESSAGE_SEARCH_SUCCESSFUL = "Search Result is displayed.";
const string SystemResponse::MESSAGE_UNDO = "Undo successful.";
const string SystemResponse::MESSAGE_UNDO_FAIL = "Failed to undo. Exceed number of actions performed.";
const string SystemResponse::MESSAGE_REDO = "Redo successful.";
const string SystemResponse::MESSAGE_REDO_FAIL = "Failed to redo. No undo action performed.";
const string SystemResponse::MESSAGE_FAIL_TO_DISPLAY_VARIOUS = "Failed to display due to incorrect type specified.";
const string SystemResponse::MESSAGE_NO_DIRECTORY = "Please specify a valid directory.";
const string SystemResponse::MESSAGE_INVALID_DIRECTORY = "Directory invalid, please re-enter.";
const string SystemResponse::MESSAGE_VALID_DIRECTORY = "Directory valid, file created.";
const string SystemResponse::MESSAGE_INVALID_COMMAND = "Command invalid, please re-enter.";
const string SystemResponse::MESSAGE_CLEAR_SUCCESSFUL = "The task list has been cleared.";


SystemResponse::SystemResponse(void) {}

SystemResponse::~SystemResponse(void) {}

string SystemResponse::welcomeExistingMessage() {
	sprintf_s(outputBuffer, MESSAGE_WELCOME_EXISTING_USER.c_str());
	return outputBuffer;
}

string SystemResponse::noDirectoryResponse() {
	sprintf_s(outputBuffer, MESSAGE_NO_DIRECTORY.c_str());
	return outputBuffer;
}

string SystemResponse::DirectoryResponse(bool isValid) {
	if (isValid){
		sprintf_s(outputBuffer, MESSAGE_VALID_DIRECTORY.c_str());
	}
	else{
		sprintf_s(outputBuffer, MESSAGE_INVALID_DIRECTORY.c_str());
	}
	return outputBuffer;
}

string SystemResponse::addResponse(bool isValidTime, bool isCorrectFormat) {
	if (isValidTime && isCorrectFormat) {
		sprintf_s(outputBuffer, MESSAGE_ADD.c_str());
	} else if (!isValidTime) {
		sprintf_s(outputBuffer, MESSAGE_ADD_FAIL_INVALID_TIME.c_str());
	} else if (!isCorrectFormat) {
		sprintf_s(outputBuffer, MESSAGE_ADD_FAIL_INCORRECT_FORMAT.c_str());
	}
	return outputBuffer;
}

string SystemResponse::deleteResponse(bool isDeleted, int index) {
	string indexString = to_string(index);
	if (isDeleted) {
		sprintf_s(outputBuffer, MESSAGE_DELETE.c_str(), indexString.c_str());
	} else {
		sprintf_s(outputBuffer,MESSAGE_DELETE_FAIL.c_str(), indexString.c_str() );
	}
	return outputBuffer;
}

string SystemResponse::editResponse(bool isEditted, int index) {
	string indexString = to_string(index);
	if (isEditted) {
		sprintf_s(outputBuffer, MESSAGE_EDIT.c_str(), indexString.c_str());
	} else {
		sprintf_s(outputBuffer, MESSAGE_EDIT_FAIL.c_str(), indexString.c_str());
	}
	return outputBuffer;
}

string SystemResponse::markDoneResponse(bool isCorrectIndex,bool isDone, int index) {
	string indexString = to_string(index);
	if (isCorrectIndex && !isDone) {
		sprintf_s(outputBuffer, MESSAGE_MARK_DONE.c_str(), indexString.c_str());
	}
	else if (isCorrectIndex && isDone){
		sprintf_s(outputBuffer, MESSAGE_MARK_DONE_FAIL_ALREADY_DONE.c_str(), indexString.c_str());
	}
	else{
		sprintf_s(outputBuffer, MESSAGE_MARK_DONE_FAIL.c_str(), indexString.c_str()); //Not complete yet, different fail cases.
	}
	return outputBuffer;
}

string SystemResponse::searchResponse(bool isEmpty) {
	if (isEmpty) {
		sprintf_s(outputBuffer, MESSAGE_SEARCH_FAIL.c_str());
	}
	else{
		sprintf_s(outputBuffer, MESSAGE_SEARCH_SUCCESSFUL.c_str());
	}
	return outputBuffer;
}

string SystemResponse::undoResponse(bool isPerformed) {
	if (isPerformed) {
		sprintf_s(outputBuffer, MESSAGE_UNDO.c_str());
	} else {
		sprintf_s(outputBuffer, MESSAGE_UNDO_FAIL.c_str());
	}
	return outputBuffer;
}

string SystemResponse::redoResponse(bool isPerformed) {
	if (isPerformed) {
		sprintf_s(outputBuffer, MESSAGE_REDO.c_str());
	} else {
		sprintf_s(outputBuffer,MESSAGE_REDO_FAIL.c_str());
	}
	return outputBuffer;
}

string SystemResponse::dispVariousResponse(string message) {
	sprintf_s(outputBuffer, message.c_str());
	return outputBuffer;
}

string SystemResponse::invalidResponse(){
	sprintf_s(outputBuffer, MESSAGE_INVALID_COMMAND.c_str());
	return outputBuffer;
}

string SystemResponse::clearAllResponse() {
	sprintf_s(outputBuffer, MESSAGE_CLEAR_SUCCESSFUL.c_str());
	return outputBuffer;
}

string SystemResponse::tellResponse() {
	RHLogger logger = RHLogger::getInstance();
	logger.addLog(outputBuffer);
	logger.saveLog();
	return outputBuffer;
}
