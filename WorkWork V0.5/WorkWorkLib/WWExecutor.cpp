//@author A0105476E

//***************************************************************
//			         Class WWExecutor
//					  Author: AI YUE
//
//			       File: WWExecutor.cpp
//
// WWExecutor class is used to execute different commands and get
// proper display for GUI
//***************************************************************

#include <string>
#include <vector>
#include <assert.h>
#include "WWUtilities.h"
#include "WWTask.h"
#include "WWStorage.h"
#include "WWDisplay.h"
#include "WWLogger.h"
#include "AddExecutor.h"
#include "DeleteExecutor.h"
#include "EditExecutor.h"
#include "SearchExecutor.h"
#include "StatusExecutor.h"
#include "TaskSorter.h"
#include "WWExecutor.h"

using namespace std;

const int USER_INDEX_ADJUSTMENT  = 1;
const int INVALID_INDEX			 = -1;
const int DATE_LENGTH			 = 8;
const int TIME_LENGTH			 = 4;
const int DATE_MULTIPLIER        = 10000;
const int LARGEST_TIME_INT       = 2359;

WWExecutor::WWExecutor() {
	_isOpeningDisplay = true;
}

WWDisplay WWExecutor::openFile() {
	bool isNotCorrupted;
	WWLogger logger = WWLogger::getInstance();

	isNotCorrupted = _storage.openFile(_taskStorage, _searchResult);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEALL);
	_display.setSystemResponseOpenFile(isNotCorrupted);

	//keep a log of the action
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::addTask(WWTask newTask) {
	WWLogger logger = WWLogger::getInstance();

	_addExecutor.addTask(_taskStorage, newTask, _display);

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEALL);
	_storage.saveFile(_taskStorage);

	//keep a log of the action
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::deleteTask(int taskIndex, WWUtilities::PageType pageType) {
	WWLogger logger = WWLogger::getInstance();

	// for delete on search page, we delete the task from the _searchResult and then get the 
	// _taskStorage from the _searchExecutor
	if(pageType == WWUtilities::PAGESEARCH){
		_deleteExecutor.deleteTask(_searchResult, taskIndex - USER_INDEX_ADJUSTMENT, pageType, _display);
		_searchExecutor.getTaskStorage(_searchResult, _taskStorage);
	} else {
		int actualIndex = determineIndexReference(taskIndex, pageType);
		unsigned int vectorIndex = actualIndex - USER_INDEX_ADJUSTMENT;
		_deleteExecutor.deleteTask(_taskStorage, vectorIndex, pageType,  _display);
	}

	_storage.saveOper(_taskStorage, _searchResult, pageType);
	_storage.saveFile(_taskStorage);

	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::editTask(int taskIndex, WWTask newTask, WWUtilities::PageType pageType) {
	WWLogger logger = WWLogger::getInstance();

	if(pageType == WWUtilities::PAGESEARCH){
		_editExecutor.editTask(_searchResult, taskIndex - USER_INDEX_ADJUSTMENT, newTask, pageType, _display);
		_searchExecutor.getTaskStorage(_searchResult, _taskStorage);
	} else {
		int actualIndex = determineIndexReference(taskIndex, pageType);
		unsigned int vectorIndex = actualIndex - USER_INDEX_ADJUSTMENT;
		_editExecutor.editTask(_taskStorage, vectorIndex, newTask, pageType,  _display);
	}

	_storage.saveOper(_taskStorage, _searchResult, pageType);
	_storage.saveFile(_taskStorage);

	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::markDone(int taskIndex, WWUtilities::PageType pageType) {
	WWLogger logger = WWLogger::getInstance();

	if(pageType == WWUtilities::PAGESEARCH){
		_statusExecutor.markDone(_searchResult, taskIndex- USER_INDEX_ADJUSTMENT, pageType, _display);
		_searchExecutor.getTaskStorage(_searchResult, _taskStorage);
	} else {
		int actualIndex = determineIndexReference(taskIndex, pageType);
		unsigned int vectorIndex = actualIndex - USER_INDEX_ADJUSTMENT;
		_statusExecutor.markDone(_taskStorage, vectorIndex, pageType,  _display);
	}

	_storage.saveOper(_taskStorage, _searchResult, pageType);
	_storage.saveFile(_taskStorage);

	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::markUndone(int taskIndex, WWUtilities::PageType pageType) {
	WWLogger logger = WWLogger::getInstance();

	if(pageType == WWUtilities::PAGESEARCH){
		_statusExecutor.markUndone(_searchResult, taskIndex - USER_INDEX_ADJUSTMENT, pageType, _display);
		_searchExecutor.getTaskStorage(_searchResult, _taskStorage);

	} else {
		int actualIndex = determineIndexReference(taskIndex, pageType);
		unsigned int vectorIndex = actualIndex - USER_INDEX_ADJUSTMENT;
		_statusExecutor.markUndone(_taskStorage, vectorIndex, pageType,  _display);
	}

	_storage.saveOper(_taskStorage, _searchResult, pageType);
	_storage.saveFile(_taskStorage);

	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::searchTask(std::vector<std::string> searchAttribute)  {
	WWLogger logger = WWLogger::getInstance();

	//searching attributes passed in should have 5 items
	assert(searchAttribute.size() == 5);

	std::string keyword = searchAttribute[0];
	std::string startDate = searchAttribute[1];
	std::string startTime = searchAttribute[2];
	std::string endDate = searchAttribute[3];
	std::string endTime = searchAttribute[4];

	long long start, end;

	assert((startDate.length() == DATE_LENGTH) || (startDate.length() == 0));
	assert((startTime.length() == TIME_LENGTH) || (startTime.length() == 0));

	assert((endDate.length() == DATE_LENGTH) || (endDate.length() == 0));
	assert((endTime.length() == TIME_LENGTH) || (endTime.length() == 0));

	if(startDate.empty() && endDate.empty()){
		logger.addLog("search keyword only: " + keyword);
		//search keyword only
		_searchExecutor.searchTask(_taskStorage, keyword, _display);
	} else if(endDate.empty()){
		logger.addLog("search keyword with one time");

		//for search keyword with one time
		//if there is only startDate, it will be considered as search from 0000 - 2359 on that date
		//if there is startDate and startTime, the start and end time will be the same time point
		if(startTime.empty()){
			start = (long long) stoi(startDate, nullptr) * DATE_MULTIPLIER;
			end   = (long long) stoi(startDate, nullptr) * DATE_MULTIPLIER + LARGEST_TIME_INT;
		} else {
			start = (long long) stoi(startDate, nullptr) * DATE_MULTIPLIER + stoi(startTime, nullptr);
			end   = start;
		}

		_searchExecutor.searchTask(_taskStorage, keyword, start, end, _display);
	} else {

		logger.addLog("search keyword within a time period");

		//for search keyword within a time period
		//if start time is empty, set the start time to 0000
		if(startTime.empty()){
			start = (long long) stoi(startDate, nullptr) * DATE_MULTIPLIER;
		} else{
			start = (long long) stoi(startDate, nullptr) * DATE_MULTIPLIER + stoi(startTime, nullptr);
		}

		//if end time is empty, set the end time to 2359
		if(endTime.empty()){
			end = (long long) stoi(endDate, nullptr) * DATE_MULTIPLIER + LARGEST_TIME_INT;
		} else {
			end = (long long) stoi(endDate, nullptr) * DATE_MULTIPLIER + stoi(endTime, nullptr);
		}

		_searchExecutor.searchTask(_taskStorage, keyword, start, end, _display);
	}

	_searchExecutor.getSearchResult(_searchResult);
	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGESEARCH);

	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::redo(WWUtilities::PageType pageType){
	WWLogger logger = WWLogger::getInstance();

	bool status;

	status = _storage.redo(_taskStorage, _searchResult, pageType);
	if(pageType == WWUtilities::PAGESEARCH){
		_display.setMainDisplay(_searchResult, pageType);
	} else {
		_display.setMainDisplay(_taskStorage, pageType);
	}

	_storage.saveFile(_taskStorage);
	_display.setSystemResponseUndoRedo(WWUtilities::REDO, status);

	logger.addLog("redo is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::undo(WWUtilities::PageType pageType){
	WWLogger logger = WWLogger::getInstance();
	bool status;

	status = _storage.undo(_taskStorage, _searchResult, pageType);

	if(pageType == WWUtilities::PAGESEARCH){
		_display.setMainDisplay(_searchResult, pageType);
	} else {
		_display.setMainDisplay(_taskStorage, pageType);
	}

	_storage.saveFile(_taskStorage);
	_display.setSystemResponseUndoRedo(WWUtilities::UNDO, status);

	logger.addLog("undo is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::deleteAll(){
	WWLogger logger = WWLogger::getInstance();

	_taskStorage.clear();
	_searchResult.clear();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEALL);
	_storage.saveFile(_taskStorage);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEALL);
	_display.setSystemResponseDeleteAll();

	logger.addLog("delete all is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::refresh(WWUtilities::PageType currentPage){
	if(currentPage == WWUtilities::PAGESEARCH){
		_display.setMainDisplay(_searchResult, currentPage);
	}else{
		_display.setMainDisplay(_taskStorage, currentPage);
	}

	return _display;
}

WWDisplay WWExecutor::viewAll() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEALL);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEALL);
	if(!_isOpeningDisplay) {
		_display.setSystemResponseView(WWUtilities::VIEWALL);
	} else {
		_isOpeningDisplay = false;
	}

	logger.addLog("viewAll is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewToday(){
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGETODAY);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGETODAY);
	_display.setSystemResponseView(WWUtilities::VIEWTODAY);

	logger.addLog("viewToday is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewOverdue(){
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEOVERDUE);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEOVERDUE);
	_display.setSystemResponseView(WWUtilities::VIEWOVERDUE);

	logger.addLog("viewOverdue is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewDone() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEDONE);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEDONE);
	_display.setSystemResponseView(WWUtilities::VIEWDONE);

	logger.addLog("viewDone is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewUndone() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEUNDONE);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEUNDONE);
	_display.setSystemResponseView(WWUtilities::VIEWUNDONE);

	logger.addLog("viewUndone is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewDeadlineTask() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEDEADLINE);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEDEADLINE);
	_display.setSystemResponseView(WWUtilities::VIEWDEADLINE);

	logger.addLog("viewDeadline is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewTimedTask() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGETIMED);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGETIMED);
	_display.setSystemResponseView(WWUtilities::VIEWTIMED);

	logger.addLog("viewTimed is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewFloatingTask() {
	WWLogger logger = WWLogger::getInstance();

	_storage.saveOper(_taskStorage, _searchResult, WWUtilities::PAGEFLOATING);

	_display.setMainDisplay(_taskStorage, WWUtilities::PAGEFLOATING);
	_display.setSystemResponseView(WWUtilities::VIEWFLOATING);

	logger.addLog("viewAll is executed");
	logger.addLog(_display.getSystemResponse());
	logger.saveLog();

	return _display;
}

WWDisplay WWExecutor::viewSearch(){
	WWLogger logger = WWLogger::getInstance();

	_display.setMainDisplay(_searchResult, WWUtilities::PAGESEARCH);

	return _display;
}

WWDisplay WWExecutor::invalidCommand(WWUtilities::PageType pageType) {
	WWLogger logger = WWLogger::getInstance();

	_display.setMainDisplay(_taskStorage, pageType);
	_display.setSystemResponseInvalid();

	return _display;
}

int WWExecutor::determineIndexReference(int index, WWUtilities::PageType pageType){
	WWLogger logger = WWLogger::getInstance();
	int actualIndex = INVALID_INDEX;
	int count = 0;
	unsigned int i = 0;

	logger.addLog("determineIndexReference is executed");

	switch(pageType){
	case WWUtilities::PAGEALL: 
		actualIndex = index;
		break;

	case WWUtilities::PAGEOVERDUE: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].checkOverdue()){
				count++;
			}
			i++;
		}
		//check whether the index is in range
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	case WWUtilities::PAGETODAY: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].checkToday()){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX; 
		}

		break;

	case WWUtilities::PAGEDONE: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].getStatus()){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	case WWUtilities::PAGEUNDONE: 
		while(count < index && i < _taskStorage.size()){
			if(!_taskStorage[i].getStatus()){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	case WWUtilities::PAGEFLOATING: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].getTaskType() == WWUtilities::FLOATING){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	case WWUtilities::PAGETIMED: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].getTaskType() == WWUtilities::TIMED){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	case WWUtilities::PAGEDEADLINE: 
		while(count < index && i < _taskStorage.size()){
			if(_taskStorage[i].getTaskType() == WWUtilities::DEADLINE){
				count++;
			}
			i++;
		}
		if(i <= _taskStorage.size() && (count == index)){
			actualIndex = i;
		} else {
			actualIndex = INVALID_INDEX;
		}
		break;

	default:
		actualIndex = INVALID_INDEX;
	}

	return actualIndex;
} 
