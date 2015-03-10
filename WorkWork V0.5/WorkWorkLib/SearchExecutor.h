//@author A0105476E

//*******************************************************************
//			         Class SearchExecutor
//					  Author: AI YUE
//
//					File: SearchExecutor.h
//
// SearchExecutor class is used when executing "search" command.
// Two searchTask methods are available: 1: search keyword only
//										 2: search within time period
//*******************************************************************

#ifndef SEARCHEXECUTOR_H
#define SEARCHEXECUTOR_H

#include <vector>
#include "WWTask.h"
#include "WWDisplay.h"

class SearchExecutor{
public:
	SearchExecutor(void);

	// this method takes in a reference of vector<WWTask> a keyword as string and a reference of WWDisplay
	// the keyword will be searched through the task names of the vector<WWTask>
	// 
	// PostCondition: pageType in display will be set to PAGESEARCH
	//				  _searchResult will contain all the WWTasks matching the keyword
	//				  _taskList will contain all the WWTasks that is in _searchResult
	// Caution: the search is case insensitive
	void searchTask(std::vector<WWTask>, std::string, WWDisplay&);

	// this method takes in a reference of vector<WWTask>, a keyword as string,
	// a start time and a end time as long long integer and a reference of WWDisplay
	// the keyword will be searched through the task names of the vector<WWTask> and the time
	// of the WWTask will be checked, only tasks containing the keyword in its task name and has a task time
	// overlaping with the searching period will be put into the _searchResult
	// 
	// PostCondition: pageType in display will be set to PAGESEARCH
	//				  _searchResult will contain all the WWTasks in the vector that match the search
	//				  _taskList will contain all the WWTasks in the vector that do not match 
	//
	// Caution: 1. the search is case insensitive
	//			2. timed task will be considered as matching the search as long as its time period got overlap 
	//			with the searching period 
	//			3. deadline task will be considered as matching if its deadline is within the searching period
	void searchTask(std::vector<WWTask>, std::string, long long, long long, WWDisplay&);

	// copy the contents in _searchResult into the vector<WWTask>& passed in 
	void getSearchResult(std::vector<WWTask>&);

	// this method takes in a vector<WWTask> and a referece to a vector<WWTask>
	// it merges the contents in the vector<WWTask> passed in with _taskList, and put them into the vector<WWTask>&
	// PostConditions: the vector<WWTask> will be sorted after merge
	void getTaskStorage(std::vector<WWTask>, std::vector<WWTask>&);

private:
	std::vector<WWTask> _searchResult;		//for storage search result list
	std::vector<WWTask> _taskList;			//for storage all other tasks
};

#endif
