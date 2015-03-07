//@author A0105476E

//************************************************************************
//			                  Class WWDisplay
//					          Author: AI YUE
//
//					        File: WWDisplay.h
//
// WWDisplay class is used as a container of all the information 
// the GUI would need to show display to the user
// Executor will put information in a WWDisplay object
// GUI can get 4 types of information from a WWDisplay object:
// 1. getMainDisplay() returns the task details in a vector<vector<string>>
// 2. getPageIndex() returns a integer represent the page GUI need to print
//    the task details to
// 3. getSystemResponse() returns a string containing the system response
// 4. getFloatingTask() returns a string containing a random incomplete
//    floating task name
//*************************************************************************

#ifndef WWDISPLAY_H
#define WWDISPLAY_H

#include <string>
#include <vector>
#include "WWTask.h"
#include "WWUtilities.h"
#include "WWDisplayWindow.h"
#include "WWSystemResponse.h"
#include "WWDisplayFloating.h"

class WWDisplay{
public:
	WWDisplay();

	// set the content of display in the main task details window
	// pageIndex is set inside setMainDisplay, and a floating task is automatically set
	void setMainDisplay	(std::vector<WWTask>, WWUtilities::PageType);

	//********************************************************************************
	//the following set of functions are used for Executor to set the system response
	//********************************************************************************
	void setSystemResponseOpenFile		(bool);
	void setSystemResponse				(WWUtilities::CommandType, std::string, bool);
	void setSystemResponseDeleteAll		();
	void setSystemResponseSearch		(int);
	void setSystemResponseView			(WWUtilities::CommandType);
	void setSystemResponseUndoRedo		(WWUtilities::CommandType, bool);
	void setSystemResponseInvalid		();

	//**********************************************************************
	//the following set of functions are used for GUI to extract information
	//**********************************************************************
	std::vector<std::vector<std::string>>&	getMainDisplay();
	std::string								getFloatingTask();
	std::string								getSystemResponse();
	int										getPageIndex();

private:
	WWDisplayWindow			_mainDisplay;		
	WWSystemResponse		_systemResponse;	
	WWUtilities::PageType	_pageIndex;			//for GUI to know which page to print the content
	WWDisplayFloating		_floatingTask;		//for GUI to display a random floating task
	unsigned int			_numOfItems;		//to keep a record of the number of items in current vector for main display

	//***************************************************************
	// the following set of functions are used to get different types
	// of tasks from the vector<WWTask>
	//***************************************************************
	std::vector<WWTask> getFloatingTask			(std::vector<WWTask>);
	std::vector<WWTask> getUndoneFloatingTask	(std::vector<WWTask>);
	std::vector<WWTask> getDeadlineTask			(std::vector<WWTask>);
	std::vector<WWTask> getTimedTask			(std::vector<WWTask>);
	std::vector<WWTask> getTodayTask			(std::vector<WWTask>);
	std::vector<WWTask> getOverdueTask			(std::vector<WWTask>);
	std::vector<WWTask> getDoneTask				(std::vector<WWTask>);
	std::vector<WWTask> getUndoneTask			(std::vector<WWTask>);

	//set the page index for GUI to know which page to print
	void setPageIndex (WWUtilities::PageType);
};

#endif