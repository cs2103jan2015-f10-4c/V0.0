static const string USER_PROMPT_TASKNAME = "Please enter task tile: ";
static const string USER_PROMPT_STARTTIME = "Star time: ";
static const string USER_PROMPT_ENDTIME = "End time: ";
static const string USER_PROMPT_INDEX = "Please the index of the targeted task: ";
static const string USER_PROMPT_KEYWORD = "Please enter the Keyword to search for: ";
static const string USER_PROMPT_NEWTASKNAME = "Please enter the new task name: ";
static const string USER_PROMPT_NEWSTARTTIME = "Please enter the new start time: ";
static const string USER_PROMPT_NEWENDTIME = "Please enter the new end time: ";

#include "Parser.h"

bool Parser::determineCommandType(string userCommand){
	 
	bool systemFeedback = false;
	if (userCommand == "add"){
		COMMAND_TYPE command = COMMAND_ADD;
		systemFeedback = true;
	}
	else if (userCommand == "delete"){
		COMMAND_TYPE command = COMMAND_DELETE;
		systemFeedback = true;
	}
	else if (userCommand == "search"){
		COMMAND_TYPE command = COMMAND_SEARCH;
		systemFeedback = true;
	}
	else if (userCommand == "edit"){
		COMMAND_TYPE command = COMMAND_EDIT;
		systemFeedback = true;
	}
	else return systemFeedback;

	processCommand(command);
	
	return systemFeedback;

}

void Parser::processCommand(COMMAND_TYPE command){
	switch (command)
	{
	case Parser::COMMAND_ADD:{
		string taskName;
		string startTime;
		string endTime;
		cout << USER_PROMPT_TASKNAME;
		cin >> taskName;
		cout << USER_PROMPT_STARTTIME;
		cin >> startTime;
		cout << USER_PROMPT_ENDTIME;
		cin >> endTime;
		logic.addExecutor(taskName, startTime, endTime);
		break;

	}case Parser::COMMAND_DELETE:{
		int index;
		cout << USER_PROMPT_INDEX;
		cin >> index;
		logic.deleteExecutor(index);
		break;
	}case Parser::COMMAND_SEARCH:{
		string keyWord;
		cout << USER_PROMPT_KEYWORD;
		cin >> keyWord;
		logic.searchExecutor(keyWord);
		break;
	}case Parser::COMMAND_EDIT:{
		int index;
		string newTaskName;
		string newStartTime;
		string newEndTime;
		cout << USER_PROMPT_INDEX;
		cin >> index;
		cout << USER_PROMPT_NEWTASKNAME;
		cin >> newTaskName;
		cout << USER_PROMPT_NEWSTARTTIME;
		cin >> newStartTime;
		cout << USER_PROMPT_ENDTIME;
		cin >> newEndTime;
		logic.editExecutor(index, newTaskName, newStartTime, newEndTime);
		break;
	}default:
		break;
	}
}