//@author A0097547M

#include <algorithm>
#include <string>
#include "WWCommandParser.h"
#include "WWUtilities.h"
#include "WWLogger.h"

using namespace std;

const unsigned int COMMAND_STRING_STARTING_INDEX = 0;

//The various match cases for basic commands
const string ADD_COMMAND = "ADD";
const string DELETE_COMMAND = "DELETE";
const string EDIT_COMMAND = "EDIT";
const string DONE_COMMAND = "COMPLETE";
const string UNDONE_COMMAND = "INCOMPLETE";
const string SEARCH_COMMAND = "SEARCH";
const string UNDO_COMMAND = "UNDO";
const string REDO_COMMAND = "REDO";
const string VIEW_COMMAND = "VIEW";
const string REFRESH_COMMAND = "REFRESH";
const string EXIT_COMMAND = "QUIT";

//The various match cases for delete type command
const string DELETETYPE_ALL = "ALL";
const string DELETETYPE_DONE = "COMPLETE";

//The various match cases for view type command
const string VIEWTYPE_ALL = "ALL";
const string VIEWTYPE_DEADLINE = "DEADLINE";
const string VIEWTYPE_TIMED = "TIMED";
const string VIEWTYPE_FLOATING = "FLOATING";
const string VIEWTYPE_TODAY = "TODAY";
const string VIEWTYPE_DONE = "COMPLETE";
const string VIEWTYPE_UNDONE = "INCOMPLETE";
const string VIEWTYPE_OVERDUE = "OVERDUE";
const string VIEWTYPE_SEARCH = "SEARCH";

const string WHITESPACE_TAB = " \t";

//strings that are used for logging
const string LOG_PARSECOMMAND = "parseCommand is called, received ";
const string LOG_RETRIEVECOMMANDTYPE = "retrieveCommandType is called";
const string LOG_RETRIEVEUNUSEDCONTENT = "retrieveUnusedContent is called, returned ";

WWCommandParser::WWCommandParser() {
}

void WWCommandParser::parseCommand(string inputString) {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PARSECOMMAND + inputString);
	logger.saveLog();

	trimLeadingWhitespace(inputString);
	try {
		determineCommandType(inputString);
	}
	catch (char*) {
		_commandType = WWUtilities::INVALID;
	}
}

WWUtilities::CommandType WWCommandParser::retrieveCommandType() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_RETRIEVECOMMANDTYPE);
	logger.saveLog();

	return _commandType;
}

string WWCommandParser::retrieveUnusedContent() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_RETRIEVEUNUSEDCONTENT + _unusedContent);
	logger.saveLog();

	return _unusedContent;
}

void WWCommandParser::determineCommandType(string inputString) {
	string inputCommand = extractFirstWord(inputString);

	if(inputString.empty()) {
		throw ("inputString is empty");
	} 

	_commandType = WWUtilities::INVALID;

	if(inputCommand == ADD_COMMAND) {
		_commandType = WWUtilities::ADD;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == DELETE_COMMAND) {
		string inputWithoutDelete = inputString.substr(inputCommand.size());
		_commandType = determineDeleteType(inputWithoutDelete);
	}

	if(inputCommand == EDIT_COMMAND) {
		_commandType = WWUtilities::EDIT;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == DONE_COMMAND) {
		_commandType = WWUtilities::DONE;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == UNDONE_COMMAND) {
		_commandType = WWUtilities::UNDONE;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == SEARCH_COMMAND) {
		_commandType = WWUtilities::SEARCH;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == UNDO_COMMAND) {
		_commandType = WWUtilities::UNDO;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == REDO_COMMAND) {
		_commandType = WWUtilities::REDO;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == VIEW_COMMAND) {
		string inputWithoutView = inputString.substr(inputCommand.size());
		_commandType = determineViewType(inputWithoutView);
	}

	if(inputCommand == REFRESH_COMMAND) {
		_commandType = WWUtilities::REFRESH;
		_unusedContent = inputString.substr(inputCommand.size());
	}

	if(inputCommand == EXIT_COMMAND) {
		_commandType = WWUtilities::EXIT;
		_unusedContent = inputString.substr(inputCommand.size());
	}
}

WWUtilities::CommandType WWCommandParser::determineDeleteType(string inputString) {
	trimLeadingWhitespace(inputString);
	string inputDeleteType = extractFirstWord(inputString);

	WWUtilities::CommandType deleteCommand = WWUtilities::DELETE;
	
	_unusedContent = inputString;

	if(inputDeleteType == DELETETYPE_ALL) {
		deleteCommand = WWUtilities::DELETEALL;
		_unusedContent = inputString.substr(inputDeleteType.size());
	}
	
	return deleteCommand;
}

WWUtilities::CommandType WWCommandParser::determineViewType(string inputString) {
	trimLeadingWhitespace(inputString);
	string inputViewType = extractFirstWord(inputString);

	WWUtilities::CommandType viewCommand = WWUtilities::INVALID;

	if(inputViewType == VIEWTYPE_ALL) {
		viewCommand = WWUtilities::VIEWALL;
	}

	if(inputViewType == VIEWTYPE_DEADLINE) {
		viewCommand = WWUtilities::VIEWDEADLINE;
	}

	if(inputViewType == VIEWTYPE_TIMED) {
		viewCommand = WWUtilities::VIEWTIMED;
	}
	
	if(inputViewType == VIEWTYPE_FLOATING) {
		viewCommand = WWUtilities::VIEWFLOATING;
	}
	
	if(inputViewType == VIEWTYPE_TODAY) {
		viewCommand = WWUtilities::VIEWTODAY;
	}
	
	if(inputViewType == VIEWTYPE_DONE) {
		viewCommand = WWUtilities::VIEWDONE;
	}
	
	if(inputViewType == VIEWTYPE_UNDONE) {
		viewCommand = WWUtilities::VIEWUNDONE;
	}
	
	if(inputViewType == VIEWTYPE_OVERDUE) {
		viewCommand = WWUtilities::VIEWOVERDUE;
	}

	if(inputViewType == VIEWTYPE_SEARCH) {
		viewCommand = WWUtilities::VIEWSEARCH;
	}

	_unusedContent = inputString.substr(inputViewType.size());

	return viewCommand;
}

string WWCommandParser::extractFirstWord(string inputString) {
	trimLeadingWhitespace(inputString);

	unsigned int firstSpaceIndex = inputString.string::find_first_of(WHITESPACE_TAB);

	string firstWord = inputString.substr(COMMAND_STRING_STARTING_INDEX, firstSpaceIndex);
	toUpperCase(firstWord);

	return firstWord;
}

void WWCommandParser::toUpperCase(string& input) {
	transform(input.begin(), input.end(), input.begin(), toupper);
}

void WWCommandParser::trimLeadingWhitespace(string& input) {
	unsigned int firstNonSpaceIndex = input.string::find_first_not_of(WHITESPACE_TAB);

	if(firstNonSpaceIndex != string::npos) {
		input = input.substr(firstNonSpaceIndex);
	} else {
		input.clear();
	}
}