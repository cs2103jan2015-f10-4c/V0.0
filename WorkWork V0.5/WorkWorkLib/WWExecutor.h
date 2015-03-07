//@author A0105476E

//***************************************************************
//			         Class WWExecutor
//					  Author: AI YUE
//
//			       File: WWExecutor.h
//
// WWExecutor class is used to execute different commands and set
// proper display for GUI
//***************************************************************

#ifndef WWEXECUTOR_H
#define WWEXECUTOR_H

#include <string>
#include <vector>
#include "WWTask.h"
#include "WWStorage.h"
#include "WWDisplay.h"
#include "WWUtilities.h"
#include "AddExecutor.h"
#include "DeleteExecutor.h"
#include "SearchExecutor.h"
#include "EditExecutor.h"
#include "StatusExecutor.h"

class WWExecutor {
public:

	WWExecutor();

	WWDisplay openFile();
	WWDisplay addTask(WWTask);	
	WWDisplay deleteAll();
	WWDisplay deleteTask	(int, WWUtilities::PageType);
	WWDisplay editTask		(int, WWTask, WWUtilities::PageType);
	WWDisplay markDone		(int, WWUtilities::PageType);
	WWDisplay markUndone	(int, WWUtilities::PageType);
	WWDisplay searchTask	(std::vector<std::string>);
	WWDisplay undo			(WWUtilities::PageType);
	WWDisplay redo			(WWUtilities::PageType);
	WWDisplay refresh		(WWUtilities::PageType);

	WWDisplay viewAll();
	WWDisplay viewDone();
	WWDisplay viewUndone();
	WWDisplay viewToday();
	WWDisplay viewOverdue();
	WWDisplay viewSearch();
	WWDisplay viewTimedTask();
	WWDisplay viewDeadlineTask();
	WWDisplay viewFloatingTask();

	WWDisplay invalidCommand(WWUtilities::PageType);

private:
	bool				_isOpeningDisplay;
	std::vector<WWTask> _taskStorage;
	std::vector<WWTask> _searchResult;

	WWStorage			_storage;
	WWDisplay			_display;

	AddExecutor			_addExecutor;
	DeleteExecutor		_deleteExecutor; 
	SearchExecutor		_searchExecutor;
	EditExecutor		_editExecutor;
	StatusExecutor		_statusExecutor;

	int determineIndexReference(int, WWUtilities::PageType);
};
#endif