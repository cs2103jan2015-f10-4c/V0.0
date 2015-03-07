//@author A0097547M

#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include "WWMainParser.h"
#include "WWCommandParser.h"
#include "WWDateParser.h"
#include "WWTimeParser.h"
#include "WWDateTimeProcessor.h"
#include "WWCommand.h"
#include "WWUtilities.h"
#include "WWLogger.h"

using namespace std;

const string WHITESPACE_TAB = " \t";

const string LOG_PARSEINPUT = "parseInput is called, received ";
const string LOG_RETRIEVECOMMAND = "retrieveCommand is called";
const string LOG_PARSECOMMANDTYPE = "parseCommandType is called, passing ";
const string LOG_PARSEDATE = "parseDate is called, passing ";
const string LOG_PARSETIME = "parseTime is called, passing ";
const string LOG_PROCESSDATETIME = "processDateTime is called";
const string LOG_COMPOSECOMMAND = "composeCommand is called";
const string LOG_COMPOSECOMMANDDETAIL = "composeCommandDetail is called, returned ";

WWMainParser::WWMainParser() {
}

void WWMainParser::parseInput(string inputString) {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PARSEINPUT + inputString);
	logger.saveLog();

	_dateStorage.clear();
	_timeStorage.clear();
	_inputString = inputString;
	executeParsing();
}

WWCommand WWMainParser::retrieveCommand() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_RETRIEVECOMMAND);
	logger.saveLog();

	return _command;
}

void WWMainParser::executeParsing() {
	assert(_dateStorage.empty());
	assert(_timeStorage.empty());

	trimLeadingWhitespace(_inputString);

	parseCommandType();
	parseDate();
	parseTime();
	processDateTime();
	composeCommand();
}
	
void WWMainParser::parseCommandType() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PARSECOMMANDTYPE + _inputString);
	logger.saveLog();

	_commandParser.parseCommand(_inputString);
	_commandType = _commandParser.retrieveCommandType();
	_unusedContent = _commandParser.retrieveUnusedContent();
}
	
void WWMainParser::parseDate() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PARSEDATE + _unusedContent);
	logger.saveLog();

	_dateParser.parseDate(_unusedContent);
	_dateParser.retrieveDate(_dateStorage);
	_unusedContent = _dateParser.retrieveUnusedContent();
}
	
void WWMainParser::parseTime() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PARSETIME + _unusedContent);
	logger.saveLog();

	_timeParser.parseTime(_unusedContent);
	_timeParser.retrieveTime(_timeStorage);
	_unusedContent = _timeParser.retrieveUnusedContent();
}

void WWMainParser::processDateTime() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_PROCESSDATETIME);
	logger.saveLog();

	_dateTimeProcessor.processDateTime(_dateStorage, _timeStorage);
}

void WWMainParser::composeCommand() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_COMPOSECOMMAND);
	logger.saveLog();

	_command.clearCommand();
	_command.setCommand(_commandType);
	composeCommandDetail();

	if(_dateStorage.size() > 0) {
		_command.setDate1(_dateStorage[0]);
	}
	if(_timeStorage.size() > 0) {
		_command.setTime1(_timeStorage[0]);
	}
	if(_dateStorage.size() > 1) {
		_command.setDate2(_dateStorage[1]);
	}
	if(_timeStorage.size() > 1) {
		_command.setTime2(_timeStorage[1]);
	}
}

//The unused content after parsing will all be treated as task name.
//The extra whitespaces are removed and each token are treated as a standalone word.
void WWMainParser::composeCommandDetail() {
	_unusedContent.erase(remove(_unusedContent.begin(), _unusedContent.end(), '\\'), _unusedContent.end());
	istringstream iss(_unusedContent);

	string unusedToken;
	vector<string> unusedTokenStorage;

	while(iss >> unusedToken) {
		unusedTokenStorage.push_back(unusedToken);
	}

	string detailString;

	for(unsigned int i = 0; i != unusedTokenStorage.size(); i++) {
		if(i == unusedTokenStorage.size() - 1) {
			detailString = detailString + unusedTokenStorage[i];
		} else {
			detailString = detailString + unusedTokenStorage[i] + " ";
		}
	}

	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_COMPOSECOMMANDDETAIL + detailString);
	logger.saveLog();

	_command.setDetail(detailString);
}

void WWMainParser::trimLeadingWhitespace(string& input) {
	unsigned int firstNonSpaceIndex = input.string::find_first_not_of(WHITESPACE_TAB);

	if(firstNonSpaceIndex != string::npos) {
		input = input.substr(firstNonSpaceIndex);
	} else {
		input.clear();
	}
}