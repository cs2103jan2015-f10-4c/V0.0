//@author A0099689W
#include <cctype>

#include "WWCommandInterpreter.h"
#include "assert.h"


using namespace std;

const int    WWCommandInterpreter::INVALID_INDEX        = -1;
const string WWCommandInterpreter::EMPTY_CONTENT        = "";
const string WWCommandInterpreter::SPACE                = " "; 
const string WWCommandInterpreter::NO_INDEX_EXCEPTION   = "No Index found£¡";
const string WWCommandInterpreter::INTERPRET_ADD_LOG    = "Interpreting add command.";
const string WWCommandInterpreter::INTERPRET_EDIT_LOG   = "Interpreting edit command.";
const string WWCommandInterpreter::INTERPRET_DELETE_LOG = "Interpreting delete command.";
const string WWCommandInterpreter::INTERPRET_DONE_LOG   = "Interpreting done command.";
const string WWCommandInterpreter::INTERPRET_UNDONE_LOG = "Interpreting undone command.";
const string WWCommandInterpreter::INTERPRET_SEARCH_LOG = "Interpreting search command.";

WWCommandInterpreter::WWCommandInterpreter(){
}

// This function extract the task to be added from the WWCommand object
// and store into a WWTask object.
// precondition : 1. The WWCommand object must have a commandType of ADD.
//                2. The WWTask object should be a empty task.  
// postcondition: task details of the new task is stored into taskToBeAdded
void WWCommandInterpreter::interpretAdd(WWCommand addCommand, WWTask& taskToBeAdded) {
	// the commandtype must be ADD in order for the method to function correctly
	assert (addCommand.getCommand() == WWUtilities::CommandType::ADD);
	
	WWLogger& logAdd = WWLogger::getInstance();
	logAdd.addLog(INTERPRET_ADD_LOG);
	logAdd.saveLog();

	if(addCommand.hasDetail()) {
		taskToBeAdded.setTaskName(addCommand.getDetail());
	} else {
		taskToBeAdded.setTaskName(EMPTY_CONTENT);
	}

	if(addCommand.hasDate1()) {
		taskToBeAdded.setStartDate(addCommand.getDate1());
	} else {
		taskToBeAdded.setStartDate(EMPTY_CONTENT);
	}

	if(addCommand.hasTime1()) {
		taskToBeAdded.setStartTime(addCommand.getTime1());
	} else {
		taskToBeAdded.setStartTime(EMPTY_CONTENT);
	}

	if(addCommand.hasDate2()) {
		taskToBeAdded.setEndDate(addCommand.getDate2());
	} else {
		taskToBeAdded.setEndDate(EMPTY_CONTENT);
	}

	if(addCommand.hasTime2()) {
		taskToBeAdded.setEndTime(addCommand.getTime2());
	} else {
		taskToBeAdded.setEndTime(EMPTY_CONTENT);
	}
}

// This function helped to identify the index of the target task to be edited
// and store the edit details into a WWTask object.
// precondition : 1.The WWCommand object must have a commandType of EDIT.
//                2.The editIndex should not be initialised before 
//                  passing to the function.
//                3.The WWTask object should be a empty task.
// postcondition: 1.The desired modification to different attributes of the 
//                  target task are stored separatedy in the taskToBeEdited.
//                2.editIndex is adjusted to the index of the target task to be edited.
void WWCommandInterpreter::interpretEdit(WWCommand editCommand, int& editIndex, WWTask& taskToBeEdited) {
	assert (editCommand.getCommand() == WWUtilities::CommandType::EDIT);
	
	WWLogger& logEdit = WWLogger::getInstance();
	logEdit.addLog(INTERPRET_EDIT_LOG);
	logEdit.saveLog();

	string editDetail = editCommand.getDetail();
	string editedTaskName;
	
	try {
		// extract the index of the target task and the new task name
	    // proposed by the user from the editDetail string.
		separateIndexDetail(editDetail, editIndex, editedTaskName); 
	} catch (string&){
		// the exception thrown indicates that the function is unable to
		// obtain a valid index in the editDetail
		editIndex = INVALID_INDEX; 
	}
	if(!editedTaskName.empty()){
		taskToBeEdited.setTaskName(editedTaskName);
	} else {
		taskToBeEdited.setTaskName(EMPTY_CONTENT);
	}

	if(editCommand.hasDate1()) {
		taskToBeEdited.setStartDate(editCommand.getDate1());
	} else {
		taskToBeEdited.setStartDate(EMPTY_CONTENT);
	}

	if(editCommand.hasTime1()) {
		taskToBeEdited.setStartTime(editCommand.getTime1());
	} else {
		taskToBeEdited.setStartTime(EMPTY_CONTENT);
	}

	if(editCommand.hasDate2()) {
		taskToBeEdited.setEndDate(editCommand.getDate2());
	} else {
		taskToBeEdited.setEndDate(EMPTY_CONTENT);
	}

	if(editCommand.hasTime2()) {
		taskToBeEdited.setEndTime(editCommand.getTime2());
	} else {
		taskToBeEdited.setEndTime(EMPTY_CONTENT);
	}
}

// This function helps to interpret the seachCommand by extracting the 
// relevant search keywords and store them in a vector of string.
// precondition : The WWCommand object must have a commandType of SEARCH.
// postcondition: The different search keywords that required by the user are extracted and
//                stored into keywordStorage separately. The vector stores a maximum of 
//                5 strings. 
void WWCommandInterpreter::interpretSearch(WWCommand searchCommand, vector<string>& keywordStorage) {
	assert (searchCommand.getCommand() == WWUtilities::CommandType::SEARCH);
	
	WWLogger& logSearch = WWLogger::getInstance();
	logSearch.addLog(INTERPRET_SEARCH_LOG);
	logSearch.saveLog();
	
	keywordStorage.clear();

	if(searchCommand.hasDetail()) {
		keywordStorage.push_back(searchCommand.getDetail());
	} else {
		keywordStorage.push_back(EMPTY_CONTENT);
	}
	
	if(searchCommand.hasDate1()) {
		keywordStorage.push_back(searchCommand.getDate1());
	} else {
		keywordStorage.push_back(EMPTY_CONTENT);
	}

	if (searchCommand.hasTime1()) {
		keywordStorage.push_back(searchCommand.getTime1());
	} else {
		keywordStorage.push_back(EMPTY_CONTENT);
	}

	if (searchCommand.hasDate2()) {
		keywordStorage.push_back(searchCommand.getDate2());
	} else {
		keywordStorage.push_back(EMPTY_CONTENT);
	}

	if (searchCommand.hasTime2()) {
		keywordStorage.push_back(searchCommand.getTime2());
	} else {
		keywordStorage.push_back(EMPTY_CONTENT);
	}

}

// precondition : The WWCommand object must have a commandType of DELETE.
// postcondition: 1. deleteIndex is adjusted to the index of the task to be deleted
//                   if the index exists, otherwise, an exception is thrown
void WWCommandInterpreter::interpretDelete(WWCommand deleteCommand, int& deleteIndex) {
	assert (deleteCommand.getCommand() == WWUtilities::CommandType::DELETE);
	
	WWLogger& logDelete = WWLogger::getInstance();
	logDelete.addLog(INTERPRET_DELETE_LOG);
	logDelete.saveLog();

	string deleteIndexString = deleteCommand.getDetail();
	try {
		deleteIndex              = convertStringToInt(deleteIndexString);
	} catch (string& ) {
		deleteIndex = INVALID_INDEX;
	}
}

// precondition : The WWCommand object must have a commandType of DONE.
// postcondition: doneIndex is adjusted to the index of the task to be marked done
//                if the index exists, otherwise, an exception is thrown
void WWCommandInterpreter::interpretDone(WWCommand doneCommand, int& doneIndex) {
	assert (doneCommand.getCommand() == WWUtilities::CommandType::DONE);

	WWLogger& logDone = WWLogger::getInstance();
	logDone.addLog(INTERPRET_DONE_LOG);
	logDone.saveLog();

	string doneIndexString = doneCommand.getDetail();

	try {
		doneIndex              = convertStringToInt(doneIndexString);
	} catch (string&) {
		doneIndex = INVALID_INDEX;
	} 
}

// precondition : The WWCommand object must have a commandType of UNDONE.
// postcondition: undoneIndex is adjusted to the index of the task to be marked undone.
//                if the index exists, otherwise, an exception is thrown
void WWCommandInterpreter::interpretUndone(WWCommand undoneCommand, int& undoneIndex) {
	assert (undoneCommand.getCommand() == WWUtilities::CommandType::UNDONE);

	WWLogger& logUndone = WWLogger::getInstance();
	logUndone.addLog(INTERPRET_UNDONE_LOG);
	logUndone.saveLog();

	string undoneIndexString = undoneCommand.getDetail();

	try {
		undoneIndex              = convertStringToInt(undoneIndexString);
	} catch (string&){
		// exception will be thrown if there is no information for index
		undoneIndex = INVALID_INDEX;
	}

}


// This function serves to separate the index of the task to be edited and the proposed 
// new task name by the user from a string editDetail.
// precondition : The index is located at the beginning of editDetail and separated
//                with the rest by a space.
// postcondition: 1. Index of the target task is stored in editIndex.
//                2. An exception is thrown if no valid index found.
//                2. The new task name is stored into editedTaskName.
void WWCommandInterpreter::separateIndexDetail(string editDetail, int& editIndex, string& editedTaskName) {
	int taskNameLocation;
	int indexLocation = editDetail.find_first_of(SPACE);

	if(indexLocation != string::npos) {
		string indexString = editDetail.substr(0, indexLocation);
		editIndex          = convertStringToInt(indexString);
		taskNameLocation = editDetail.find_first_not_of(SPACE, ++indexLocation);
		editedTaskName     = editDetail.substr(taskNameLocation);
	} else if(!editDetail.empty()) {
		editIndex = convertStringToInt(editDetail);
		editedTaskName = EMPTY_CONTENT;
	} else {
		throw NO_INDEX_EXCEPTION;
	}
	
	
}

int WWCommandInterpreter::convertStringToInt(string convertString) {
	if(convertString.empty()){
		throw NO_INDEX_EXCEPTION;
	} else {
		return atoi(convertString.c_str());
	}
}