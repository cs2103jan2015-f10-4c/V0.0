//@author A0105476E

//*************************************************************************
//			               Class DeleteExecutor
//					          Author: AI YUE
//
//					      File: DeleteExecutor.h
//
// DeleteExecutor class is used when executing "delete" command.
// Sample use: 
//		DeleteExecutor deleteExecutor;
//      deleteExecutor.deleteTask(taskStorage, index, pageType, display);
//      //task at taskStorage[index] will be deleted from taskStorage if
//		//index is valid, a WWDisplay will be set for gui to print display
//*************************************************************************

#ifndef DELETEEXECUTOR_H
#define DELETEEXECUTOR_H

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"
#include "WWUtilities.h"

class DeleteExecutor
{
public:
	DeleteExecutor(void);

	// deleteTask method takes in a reference of a vector<WWTask>, a int index,
	// a PageType and a reference of WWDisplay
	// it will delete a task from the vector of WWTask and set up the WWDisplay
	// If index is valid: 
	//   task at index position of the vector will be deleted
	//   systemResponse in WWDisplay will be set as delete success response
	// If index is invalid
	//   systemResponse in WWDisplay will be set as delete failed response
	// pageType in WWDisplay will remain the same as the PageType takes in
	// mainDisplay in WWDisplay will be set to the vector<WWTask>
	//
	// PreCondition: the index passed in should be vector index start from 0
	// PostCondition: the pageType of WWDisplay will stay at the original page
	void deleteTask(std::vector<WWTask>&, unsigned int, WWUtilities::PageType, WWDisplay&);
};

#endif
