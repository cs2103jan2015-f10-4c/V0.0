//@author A0097547M

#ifndef WWPARSER_H
#define WWPARSER_H

#include <string>
#include "WWMainParser.h"
#include "WWCommand.h"

//WWParser is the facade class of the Parser component

class WWParser {
public:
	WWParser();

	void parseInput(std::string);
	WWCommand retrieveCommand();

private:
	WWMainParser _mainParser;
};
#endif