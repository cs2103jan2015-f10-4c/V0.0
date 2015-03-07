//@author A0097547M

#ifndef WWCOMMANDPARSER_H
#define WWCOMMANDPARSER_H

#include <string>
#include "WWUtilities.h"

//WWCommandParser can receive a string through the parseCommand API.
//WWCommandParser will then attempt to parse the first word found in the string as a command
//If the first word does not match any of the command types, then WWCommandParser will set the command type as invalid.
//Any leading whitespace will not be considered for parsing.
//An empty string will return an invalid command type.
//The enumeration of the command type can be found in WWUtilities.h.
//WWCommandParser can also return a string that contains content which are not used in the parsing.

class WWCommandParser {
public:
	WWCommandParser();
	
	void parseCommand(std::string);
	WWUtilities::CommandType retrieveCommandType();
	std::string retrieveUnusedContent();

private:
	WWUtilities::CommandType _commandType;
	std::string _unusedContent;

	void determineCommandType(std::string);
	WWUtilities::CommandType determineDeleteType(std::string);
	WWUtilities::CommandType determineViewType(std::string);
	std::string extractFirstWord(std::string);

	void toUpperCase(std::string&);
	void trimLeadingWhitespace(std::string&);
};
#endif