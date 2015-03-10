#include "Parser.h"

string Parser::USER_PROMPT_TASKNAME = "Please enter task title: ";
string Parser::USER_PROMPT_STARTTIME = "Start time: ";
string Parser::USER_PROMPT_ENDTIME = "End time: ";
string Parser::USER_PROMPT_INDEX = "Please enter the index of the targeted task: ";
string Parser::USER_PROMPT_KEYWORD = "Please enter the Keyword to search for: ";
string Parser::USER_PROMPT_NEWTASKNAME = "Please enter the new task name: ";
string Parser::USER_PROMPT_NEWSTARTTIME = "Please enter the new start time: ";
string Parser::USER_PROMPT_NEWENDTIME = "Please enter the new end time: ";


Parser::Parser() {}
Parser::~Parser(){}

bool Parser::determineCommandType(string userCommand){
	COMMAND_TYPE command;
	bool systemFeedback = false;
	if (userCommand == "add"){
		 command = COMMAND_ADD;
		systemFeedback = true;
	}
	else if (userCommand == "delete"){
		command = COMMAND_DELETE;
		systemFeedback = true;
	}
	else if (userCommand == "search"){
		command = COMMAND_SEARCH;
		systemFeedback = true;
	}
	else if (userCommand == "edit"){
		command = COMMAND_EDIT;
		systemFeedback = true;
	}
	else return false;

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
		logic.addTask(taskName, startTime, endTime);
		break;

	}case Parser::COMMAND_DELETE:{
		int index;
		cout << USER_PROMPT_INDEX;
		cin >> index;
		logic.deleteTask(index);
		break;
	}case Parser::COMMAND_SEARCH:{
		string keyWord;
		cout << USER_PROMPT_KEYWORD;
		cin >> keyWord;
		logic.searchTask(keyWord);
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
		logic.editTask(index, newTaskName, newStartTime, newEndTime);
		break;
	}default:
		break;
	}
}