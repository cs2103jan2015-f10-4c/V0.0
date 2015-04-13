//@author A0115404W

#ifndef LOGIC_H_
#define LOGIC_H_


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <sys/stat.h>
#include "timeChecker.h"
#include "Task.h"
#include "Parser.h"
#include "addExecutor.h"
#include "deleteExecutor.h"
#include "editExecutor.h"
#include "searchExecutor.h"
#include "markDoneExecutor.h"
#include "Display.h"
#include "Storage.h"
#include "History.h"
#include "SystemResponse.h"
#include <stdio.h>

//Logic class employs the idea of facade pattern.
//It is responsible for the coordination between GUI and other internal components such as parser and storage. 
//Logic class contains public vectors such as taskList, deadlineList and floatingList which is passed to various components when the content in the taskList is modified. 
//The main role of Logic class is to coordinate with methods in other components, 
//to pass the information in the correct sequence and data type in which the recipient component is able to understand.   

class Logic{

private:

    Parser parse;
	AddExecutor add;
    DeleteExecutor deleteATask;
    EditExecutor edit;
	SearchExecutor search;
	MarkDoneExecutor mark;
	Storage storage;
	Display disp;
	History history;
	SystemResponse response;
	TimeChecker checker;


public:
	Logic();
	~Logic();
    vector<Task> taskList;
	vector<Task> deadlineList;
    vector<Task> floatingList;


	enum CommandType {

		_ADD, _DELETE, _EDIT, _SEARCH, _MARKDONE, _DISPLAY, _UNDO, _REDO, _INVALID, _DIRECTORY, _CLEAR, _EXIT 

	};
	
    void addTask();
	void deleteTask();
	void editTask();
	void searchTask();
	void markDoneTask();
	void displayVariousType();
	void undoTask();
	void redoTask();
	bool checkIndex(int);
	void getDirectory();
	void clearTaskList();
	void exitProgram();
	void showUserInvalidResponse();
	string tellGUI();
	string tellGUIResponse();
	void checkDirectory();
	void refreshStatus();
	bool checkFoundList(vector<Task>);
	CommandType determineCommandType(string);
    void executeUserCommand (string);

};
#endif