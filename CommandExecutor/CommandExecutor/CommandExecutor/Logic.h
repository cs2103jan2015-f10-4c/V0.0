//@RushHour
//This part is to determine the command type provided by user 
//And following actions can be executed respectively

#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include "addExecutor.h"
#include "deleteExecutor.h"
#include "displayExecutor.h"
#include "editExecutor.h"
#include "clearExecutor.h"
#include "sortExecutor.h"
#include "searchExecutor.h"
#include "Parser.h"


using namespace std;

class Logic{
private:

	static enum COMMAND_TYPE {
		COMMAND_ADD, COMMAND_DISPLAY, COMMAND_DELETE, COMMAND_EDIT, COMMAND_CLEAR, COMMAND_SORT, COMMAND_SEARCH,
		COMMAND_INVALID, COMMAND_EXIT
	}; //These are the possible command type.

	static vector <string> inputStorage;
	static vector <COMMAND_TYPE>  commandStorage;


public:

	Logic();
	~Logic();
	
	static void  processCommand(string);
	static COMMAND_TYPE getCommandType(string);



};

#endif