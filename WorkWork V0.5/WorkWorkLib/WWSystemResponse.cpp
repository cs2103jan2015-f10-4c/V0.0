//@author A0105476E

//*************************************************************
//			      Class WWSystemResponse
//					  Author: AI YUE
//
//			    File: WWSystemResponse.cpp
//
// WWSystemResponse class is used to set the system response of 
// different actions
//**************************************************************

#include <string>
#include <iostream>
#include <sstream>
#include <exception>
#include <assert.h>
#include "WWUtilities.h"
#include "WWSystemResponse.h"

using namespace std;

const int MAX			 = 99;
const int TASK_NAME_MAX  = 50;
const int START_POSITION = 0;

const string OPENFILE_SUCCESS_FEEDBACK  = "Welcome to WorkWork!";
const string OPENFILE_FAILURE_FEEDBACK  = "File is corrupted!";
const string ADD_SUCCESS_FEEDBACK		= "%s created";
const string ADD_FAIL_FEEDBACK			= "Please input task name";
const string DELETE_SUCCESS_FEEDBACK	= "%s deleted";
const string EDIT_SUCCESS_FEEDBACK		= "%s edited";
const string DONE_SUCCESS_FEEDBACK		= "%s is marked as completed";
const string DONE_FAIL_FEEDBACK			= "%s is already completed";
const string UNDONE_SUCCESS_FEEDBACK	= "%s is marked as incomplete";
const string UNDONE_FAIL_FEEDBACK		= "%s is already incomplete";
const string SEARCH_FEEDBACK			= "%d results are found";
const string DELETEALL_SUCCESS_FEEDBACK	= "All your tasks are deleted";
const string VIEW_ALL_FEEDBACK			= "You have %d tasks in total";
const string VIEW_TODAY_FEEDBACK		= "You have %d tasks for today";
const string VIEW_OVERDUE_FEEDBACK		= "You have %d overdue tasks in total";
const string VIEW_TIMED_FEEDBACK		= "You have %d timed tasks in total";
const string VIEW_DEADLINE_FEEDBACK		= "You have %d deadline tasks in total";
const string VIEW_FLOATING_FEEDBACK		= "You have %d floating tasks in total";
const string VIEW_UNDONE_FEEDBACK		= "You have %d incomplete tasks in total";
const string VIEW_DONE_FEEDBACK			= "You have %d completed tasks in total";
const string UNDO_SUCCESS_FEEDBACK		= "Undo successful";
const string UNDO_FAIL_FEEDBACK			= "Undo not available";
const string REDO_SUCCESS_FEEDBACK		= "Redo successful";
const string REDO_FAIL_FEEDBACK			= "Redo not available";
const string INDEX_NOT_FOUND_FEEDBACK	= "Index not found";
const string INVALID_COMMAND_FEEDBACK	= "Invalid command";

const string ELLIPSIS_STRING			= "...";

const string INVALID_COMMAND_TYPE       = "Invalid command type. You may used a wrong set systemResponse function.";

WWSystemResponse::WWSystemResponse() {
}

void WWSystemResponse::setSystemResponseOpenFile(bool openFileStatus) {
	char buffer [MAX];

	if(openFileStatus) {
		sprintf_s(buffer, OPENFILE_SUCCESS_FEEDBACK.c_str());
	} else {
		sprintf_s(buffer, OPENFILE_FAILURE_FEEDBACK.c_str());
	}

	_systemResponse = buffer;
}

void WWSystemResponse::setSystemResponse(WWUtilities::CommandType command, string taskName, bool status) {
	char buffer [MAX];

	// we chop the task name to a max of 50 characters
	// if task name is over 50, chop the part exceed 50 characters and add ... behind 
	taskName = chopTaskName(taskName);

	// after chopping, the task name should have a length of at most TASK_NAME_MAX + ELLIPSIS.length()
	assert(taskName.length() <= (unsigned int) TASK_NAME_MAX + ELLIPSIS_STRING.length());

	try{
		switch (command)
		{
		case WWUtilities::ADD:
			if(status) {
				sprintf_s(buffer, ADD_SUCCESS_FEEDBACK.c_str(), taskName.c_str());
			} else {
				sprintf_s(buffer, ADD_FAIL_FEEDBACK.c_str());
			}
			break;
		case WWUtilities::DELETE:
			if(status) {
				sprintf_s(buffer, DELETE_SUCCESS_FEEDBACK.c_str(), taskName.c_str());
			} else {
				sprintf_s(buffer, INDEX_NOT_FOUND_FEEDBACK.c_str());
			}
			break;
		case WWUtilities::EDIT:
			if(status) {
				sprintf_s(buffer, EDIT_SUCCESS_FEEDBACK.c_str(), taskName.c_str());
			} else {
				sprintf_s(buffer, INDEX_NOT_FOUND_FEEDBACK.c_str());
			}
			break;
		case WWUtilities::DONE:
			if(status) {
				sprintf_s(buffer, DONE_SUCCESS_FEEDBACK.c_str(), taskName.c_str());
			} else {
				if(taskName.empty()) {
					sprintf_s(buffer, INDEX_NOT_FOUND_FEEDBACK.c_str());
				} else {
					sprintf_s(buffer, DONE_FAIL_FEEDBACK.c_str(), taskName.c_str());
				}
			}
			break;
		case WWUtilities::UNDONE:
			if(status) {
				sprintf_s(buffer, UNDONE_SUCCESS_FEEDBACK.c_str(), taskName.c_str());
			} else {
				if(taskName.empty()) {
					sprintf_s(buffer, INDEX_NOT_FOUND_FEEDBACK.c_str());
				} else {
					sprintf_s(buffer, UNDONE_FAIL_FEEDBACK.c_str(), taskName.c_str());
				}
			}
			break;
		default:
			// if the command is none of the above, throw an exeception of INVALID_COMMAND_TYPE
			throw INVALID_COMMAND_TYPE;
			break;
		}
		_systemResponse = buffer;
	}
	catch(std::string & exception){
		std::cout << exception << endl;
	}
}

void WWSystemResponse::setSystemResponseDeleteAll() {
	char buffer[MAX];
	sprintf_s(buffer, DELETEALL_SUCCESS_FEEDBACK.c_str());
	_systemResponse = buffer;
}

void WWSystemResponse::setSystemResponseUndoRedo(WWUtilities::CommandType command, bool status){
	try{
		switch (command)
		{
		case WWUtilities::UNDO:
			if(status){
				_systemResponse = UNDO_SUCCESS_FEEDBACK;
			} else {
				_systemResponse = UNDO_FAIL_FEEDBACK;
			}
			break;
		case WWUtilities::REDO:
			if(status){
				_systemResponse = REDO_SUCCESS_FEEDBACK;
			} else {
				_systemResponse = REDO_FAIL_FEEDBACK;
			}
			break;
		default:
			// if the command is none of the above, throw an exeception of INVALID_COMMAND_TYPE
			throw INVALID_COMMAND_TYPE;
			break;
		}
	}
	catch(std::string& exception){
		std::cout << exception << endl;
	}
}

void WWSystemResponse::setSystemResponseSearch(int numResult) {
	char buffer[MAX];
	sprintf_s(buffer, SEARCH_FEEDBACK.c_str(), numResult);
	_systemResponse = buffer;
} 

void WWSystemResponse::setSystemResponseView(WWUtilities::CommandType command, int numResult) {
	char buffer [MAX];

	try{
		switch (command){
		case WWUtilities::VIEWALL:
			sprintf_s(buffer, VIEW_ALL_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWDEADLINE:
			sprintf_s(buffer, VIEW_DEADLINE_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWTIMED:
			sprintf_s(buffer, VIEW_TIMED_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWFLOATING:
			sprintf_s(buffer, VIEW_FLOATING_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWTODAY:
			sprintf_s(buffer, VIEW_TODAY_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWDONE:
			sprintf_s(buffer, VIEW_DONE_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWUNDONE:
			sprintf_s(buffer, VIEW_UNDONE_FEEDBACK.c_str(), numResult);
			break;
		case WWUtilities::VIEWOVERDUE:
			sprintf_s(buffer, VIEW_OVERDUE_FEEDBACK.c_str(), numResult);
			break;
		default:
			// if the command is none of the above, throw an exeception of INVALID_COMMAND_TYPE
			throw INVALID_COMMAND_TYPE;
			break;
		}
		_systemResponse = buffer;
	}
	catch(std::string& exception){
		std::cout << exception << endl;
	}
}

void WWSystemResponse::setSystemResponseInvalid() {
	_systemResponse = INVALID_COMMAND_FEEDBACK;
}

string WWSystemResponse::getSystemResponse() {
	return _systemResponse;
}

string WWSystemResponse::chopTaskName(string taskName){
	if(taskName.length() > TASK_NAME_MAX){
		return taskName.substr(START_POSITION, TASK_NAME_MAX) + ELLIPSIS_STRING;
	} else {
		return taskName;
	}
}