//@author A0097547M

#include <string>
#include "WWParser.h"
#include "WWMainParser.h"
#include "WWCommand.h"
#include "WWLogger.h"

using namespace std;

const string LOG_PARSEINPUT = "WWParser::parseInput is called, received ";
const string LOG_RETRIEVECOMMAND = "WWParser::retrieveCommand is called";

WWParser::WWParser() {
}

 void WWParser::parseInput(string inputString) {
	 WWLogger& logger = WWLogger::getInstance();
	 logger.addLog(LOG_PARSEINPUT + inputString);
	 logger.saveLog();

	 _mainParser.parseInput(inputString);
}

WWCommand WWParser::retrieveCommand() {
	WWLogger& logger = WWLogger::getInstance();
	logger.addLog(LOG_RETRIEVECOMMAND);
	 logger.saveLog();

	return _mainParser.retrieveCommand();
}