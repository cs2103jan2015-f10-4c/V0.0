
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
//<<<<<<< HEAD
//    Parser parse;
//=======

	Parser parse;
//>>>>>>> 723c00640015219699b2d4ce36c6cbe5bcca1fc0
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
<<<<<<< HEAD
		ADD, DELETE, EDIT, SEARCH, MARKDONE, DISPLAY, UNDO, REDO, ERROR,
=======
		_ADD, _DELETE, _EDIT, _SEARCH, _MARKDONE, _DISPLAY, _UNDO, _REDO, _ERROR
>>>>>>> 723c00640015219699b2d4ce36c6cbe5bcca1fc0
	};

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