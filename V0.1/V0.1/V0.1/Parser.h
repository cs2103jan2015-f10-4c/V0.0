

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Logic.h"


using namespace std;

class Parser{

private:
	Logic logic;
	static enum COMMAND_TYPE 
	{COMMAND_ADD,  COMMAND_DELETE, COMMAND_SEARCH, COMMAND_EDIT};

	static  string USER_PROMPT_TASKNAME ;
	static  string USER_PROMPT_STARTTIME;
	static  string USER_PROMPT_ENDTIME;
	static  string USER_PROMPT_INDEX;
	static  string USER_PROMPT_KEYWORD ;
	static  string USER_PROMPT_NEWTASKNAME ;
	static  string USER_PROMPT_NEWSTARTTIME ;
	static  string USER_PROMPT_NEWENDTIME ;

public:

	Parser();
	~Parser();

	bool determineCommandType(string);

	void processCommand(COMMAND_TYPE);


};

#endif