//@author A0097547M

#ifndef WWMAINPARSER_H
#define WWMAINPARSER_H

#include <string>
#include <vector>
#include "WWCommandParser.h"
#include "WWDateParser.h"
#include "WWTimeParser.h"
#include "WWDateTimeProcessor.h"
#include "WWCommand.h"
#include "WWUtilities.h"

//WWMainParser is the coordinating class that schedules the operations of parsing
//WWMainParser will accept the user input through a string
//The order of parsing is as follows:
//CommandType, dates then time
//WWMainParser will then make use of WWDateTimeProcessor to sort the dates and time
//Finally, WWMainParser will compose the WWCommand object to return to Logic.
//The unused content after parsing will all be treated as task name.
//The dates and time are stored as strings within WWCommand with the format being YYYYMMDD and HHMM respectively.

class WWMainParser {
public:
	WWMainParser();

	void parseInput(std::string);
	WWCommand retrieveCommand();

private:
	std::string _inputString;

	WWUtilities::CommandType _commandType;
	std::string _unusedContent;
	std::vector<std::string> _dateStorage;
	std::vector<std::string> _timeStorage;

	WWCommandParser _commandParser;
	WWDateParser _dateParser;
	WWTimeParser _timeParser;
	WWDateTimeProcessor _dateTimeProcessor;
	WWCommand _command;

	void executeParsing();
	void parseCommandType();
	void parseDate();
	void parseTime();
	void processDateTime();
	void composeCommand();
	void composeCommandDetail();

	void trimLeadingWhitespace(std::string&);
};
#endif