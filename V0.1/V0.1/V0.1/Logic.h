

#ifndef LOGIC_H_
#define LOGIC_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <sstream>
#include "Parser.h"
#include "UI.h"
#include "addExecutor.h"
#include "deleteExecutor.h"
#include "editExecutor.h"
#include "searchExecutor.h"
#include "markDoneExecutor.h"
#include "Display.h"
#include "Storage.h"

using namespace std;

class Logic{
private:
    
	vector<Task> taskList;
	Parser parser;
    addExecutor add;
	deleteExecutor deleteATask;
	editExecutor edit;
	searchExecutor search;
	markDoneExecutor mark;
	Storage storage;
	Display disp;


public:
	Logic();
	~Logic();
	enum COMMAND_TYPE {
		ADD, DELETE, EDIT, SEARCH, MARKDONE, DISPLAY, UNDO, REDO
	};
	
    void addTask();
	void deleteTask();
	void editTask();
	void searchTask();
	void markDoneTask();
	void display();
	void undoTask();
	COMMAND_TYPE determineCommandType(string);
	static void executeUserCommand (string);

};
#endif