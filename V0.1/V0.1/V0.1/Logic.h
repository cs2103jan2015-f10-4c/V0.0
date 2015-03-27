
#ifndef LOGIC_H_
#define LOGIC_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "Task.h"
#include "Parser.h"
#include "addExecutor.h"
#include "deleteExecutor.h"
#include "editExecutor.h"
#include "searchExecutor.h"
#include "markDoneExecutor.h"
#include "Display.h"
#include "Storage.h"
#include <stdio.h>

class Logic{

private:


	Parser parse;

	vector<Task> taskList;
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

		_ADD, _DELETE, _EDIT, _SEARCH, _MARKDONE, _DISPLAY, _UNDO, _REDO, _ERROR

	};
	void retriveStorage();
    void addTask();
	void deleteTask();
	void editTask();
	void searchTask();
	void markDoneTask();
	void display();
	void undoTask();
	void redoTask();
	COMMAND_TYPE determineCommandType(string);
    void executeUserCommand (string);

};
#endif