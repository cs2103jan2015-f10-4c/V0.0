//@author A0105476E

//**************************************************************
//			         Class EditExecutor
//					  Author: AI YUE
//
//					File: EditExecutor.h
//
// EditExecutor class is used when executing "edit" command.
//**************************************************************

#ifndef EDITEXECUTOR_H
#define EDITEXECUTOR_H

#include <vector>
#include "WWDisplay.h"
#include "WWTask.h"
#include "WWUtilities.h"

class EditExecutor{
public:
	EditExecutor(void);

	// editTask method takes in a reference of a vector<WWTask>, a int index,
	// , a WWTask, a PageType and a reference of WWDisplay
	// it edits a WWTask in the vector<WWTask> and set up the WWDisplay
	// If index is valid: 
	//   the attributes of the WWTask at the index position will be overwrited 
	//   by the attributes of the new WWTask if it's not empty
	//   systemResponse in WWDisplay will be set as edit success response
	// If index is invalid
	//   systemResponse in WWDisplay will be set as edit failed response
	// pageType in WWDisplay will remain same as the pageType takes in
	// mainDisplay in WWDisplay will be set to the vector<WWTask>
	//
	// Precondition: the index passed in is already vector index start from 0
	void editTask(std::vector<WWTask>& taskStorage, unsigned int, WWTask, WWUtilities::PageType, WWDisplay& display);
};

#endif

