

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Logic.h"
#include "UI.h"

using namespace std;

class Parser{
private:
	Logic logic;
	static enum COMMAND_TYPE 
	{COMMAND_ADD,  COMMAND_DELETE, COMMAND_SEARCH, COMMAND_EDIT};


public:

	Parser();
	~Parser();

	bool determineCommandType(string);

	void processCommand(COMMAND_TYPE)


};

#endif