//@author A0105476E

//**********************************************************
//			         Class AddExecutor
//					  Author: AI YUE
//
//					File: AddExecutor.h
//
// AddExecutor class is used when executing "add" command.
// Sample usage:
//		AddExecutor addExecutor;
//		vector<WWTask> taskStorage;
//		WWTask newTask;
//		WWDisplay display;
//		addExecutor.addTask(taskStorage, newTask, display);
//		//newTask will be added into taskStorage if it has
//		//task name and display will be set up
//**********************************************************

#ifndef ADDEXECUTOR_H
#define ADDEXECUTOR_H

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"

class AddExecutor{
public:
	AddExecutor(void);

	// addTask method takes in references to a vector<WWTask>, a WWTask, and a WWDisplay object
	// It add the WWTask to the vector of WWTask and set up the WWDisplay
	// If the WWTask has task name: 
	//   addTask will add new WWTask into the vector,
	//   and set systemResponse in WWDisplay as add success response
	// If the WWTAsk doesn't have task name:
	//   the WWTask will not be added into the vector,
	//   addTask will set systemResponse in WWDisplay as add failed response
	// pageType in WWDisplay will be set to PAGEALL
	// mainDisplay in display will be set to the vector<WWTask>
	//
	// postConditions: the PageType will go to PAGEALL
	//				   the vector<WWTask> will be sorted
	void addTask(std::vector<WWTask>&, WWTask,  WWDisplay&);
};

#endif