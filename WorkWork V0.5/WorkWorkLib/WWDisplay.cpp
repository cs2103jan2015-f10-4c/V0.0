//@author A0105476E

//***************************************************************
//					  Author: AI YUE
//
//					File: WWDisplay.cpp
//***************************************************************

#include <string>
#include <vector>
#include "WWTask.h"
#include "WWUtilities.h"
#include "WWDisplayWindow.h"
#include "WWSystemResponse.h"
#include "WWDisplayFloating.h"
#include "WWDisplay.h"

using namespace std;

WWDisplay::WWDisplay() {
	_pageIndex = WWUtilities::PAGEALL;
}

void WWDisplay::setMainDisplay(vector<WWTask> taskStorage, WWUtilities::PageType pageType) {
	switch(pageType){
	case WWUtilities::PAGEALL:
		_mainDisplay.setContent(taskStorage);
		setPageIndex(WWUtilities::PAGEALL);
		_numOfItems = taskStorage.size();
		break;
	case WWUtilities::PAGETODAY:
		_mainDisplay.setContent(getTodayTask(taskStorage));
		_numOfItems = getTodayTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGETODAY);
		break;
	case WWUtilities::PAGEOVERDUE:
		_mainDisplay.setContent(getOverdueTask(taskStorage));
		_numOfItems = getOverdueTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGEOVERDUE);
		break;
	case WWUtilities::PAGEDONE:
		_mainDisplay.setContent(getDoneTask(taskStorage));
		_numOfItems = getDoneTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGEDONE);
		break;
	case WWUtilities::PAGEUNDONE:
		_mainDisplay.setContent(getUndoneTask(taskStorage));
		_numOfItems = getUndoneTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGEUNDONE);
		break;
	case WWUtilities::PAGETIMED:
		_mainDisplay.setContent(getTimedTask(taskStorage));
		_numOfItems = getTimedTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGETIMED);
		break;
	case WWUtilities::PAGEDEADLINE:
		_mainDisplay.setContent(getDeadlineTask(taskStorage));
		_numOfItems = getDeadlineTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGEDEADLINE);
		break;
	case WWUtilities::PAGEFLOATING:
		_mainDisplay.setContent(getFloatingTask(taskStorage));
		_numOfItems = getFloatingTask(taskStorage).size();
		setPageIndex(WWUtilities::PAGEFLOATING);
		break;
	case WWUtilities::PAGESEARCH:
		_mainDisplay.setContent(taskStorage);
		_numOfItems = taskStorage.size();
		setPageIndex(WWUtilities::PAGESEARCH);
		break;
	}
	_floatingTask.generateRandomTask(getUndoneFloatingTask(taskStorage));
}

void WWDisplay::setSystemResponseOpenFile(bool openFileStatus) {
	_systemResponse.setSystemResponseOpenFile(openFileStatus);
}

void WWDisplay::setSystemResponse(WWUtilities::CommandType command, string taskName, bool status) {
	_systemResponse.setSystemResponse(command, taskName, status);
}

void WWDisplay::setSystemResponseDeleteAll() {
	_systemResponse.setSystemResponseDeleteAll();
}

void WWDisplay::setSystemResponseUndoRedo(WWUtilities::CommandType command, bool status){
	_systemResponse.setSystemResponseUndoRedo(command, status);
}

void WWDisplay::setSystemResponseSearch(int numResult) {
	_systemResponse.setSystemResponseSearch(numResult);
}

void WWDisplay::setSystemResponseView(WWUtilities::CommandType command) {
	_systemResponse.setSystemResponseView(command, _numOfItems);
}

void WWDisplay::setSystemResponseInvalid() {
	_systemResponse.setSystemResponseInvalid();
}

std::vector<vector<string>>& WWDisplay::getMainDisplay() {
	return _mainDisplay.getContent();
}

std::string WWDisplay::getSystemResponse() {
	return _systemResponse.getSystemResponse();
}

int WWDisplay::getPageIndex(){
	return _pageIndex;
}

std::string WWDisplay::getFloatingTask() {
	return _floatingTask.getFloatingTaskName();
}

void WWDisplay::setPageIndex(WWUtilities::PageType pageType){
	_pageIndex = pageType;
}

std::vector<WWTask> WWDisplay::getFloatingTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> floatingTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++){
		if(taskStorage[i].getTaskType() == WWUtilities::FLOATING){
			floatingTaskList.push_back(taskStorage[i]);
		}
	}

	return floatingTaskList;
}

std::vector<WWTask> WWDisplay::getUndoneFloatingTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> undoneFloatingTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++){
		if(taskStorage[i].getTaskType() == WWUtilities::FLOATING && (!taskStorage[i].getStatus())){
			undoneFloatingTaskList.push_back(taskStorage[i]);
		}
	}

	return undoneFloatingTaskList;
}

std::vector<WWTask> WWDisplay::getTimedTask(std::vector<WWTask> taskStorage){
	vector<WWTask> timedTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(taskStorage[i].getTaskType() == WWUtilities::TIMED) {
			timedTaskList.push_back(taskStorage[i]);
		}
	}

	return timedTaskList;
}

std::vector<WWTask> WWDisplay::getDeadlineTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> deadlineTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(taskStorage[i].getTaskType() == WWUtilities::DEADLINE) {
			deadlineTaskList.push_back(taskStorage[i]);
		}
	}

	return deadlineTaskList;
}

std::vector<WWTask> WWDisplay::getTodayTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> todayTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(taskStorage[i].checkToday()){
			todayTaskList.push_back(taskStorage[i]);
		}
	}

	return todayTaskList;
}

std::vector<WWTask> WWDisplay::getOverdueTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> overdueTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(taskStorage[i].checkOverdue()){
			overdueTaskList.push_back(taskStorage[i]);		
		}
	}

	return overdueTaskList;
}

std::vector<WWTask> WWDisplay::getDoneTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> doneTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(taskStorage[i].getStatus()){
			doneTaskList.push_back(taskStorage[i]);
		}
	}

	return doneTaskList;
}

std::vector<WWTask> WWDisplay::getUndoneTask(std::vector<WWTask> taskStorage){
	std::vector<WWTask> undoneTaskList;

	for(unsigned int i = 0; i < taskStorage.size(); i++) {
		if(!taskStorage[i].getStatus()){
			undoneTaskList.push_back(taskStorage[i]);
		}
	}

	return undoneTaskList;
}