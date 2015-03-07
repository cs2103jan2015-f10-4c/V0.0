//@author A0105476E

//*******************************************************************
//					  Author: AI YUE
//
//					File: SearchExecutor.cpp
//*******************************************************************

#include <string>
#include <algorithm>
#include <ctype.h>
#include "WWTask.h"
#include "WWDisplay.h"
#include "WWUtilities.h"
#include "TaskSorter.h"
#include "SearchExecutor.h"

const int DATE_MULTIPLIER  = 10000;    //for create a long long int in this formate yyyymmddhhmm
const int LARGEST_TIME_INT = 2359;	   //the largest time integer

SearchExecutor::SearchExecutor(void){
}

//search keyword only
void SearchExecutor::searchTask(std::vector<WWTask> taskStorage, std::string keyword, WWDisplay& display){
	_taskList.clear();
	_searchResult.clear();

	//keep a copy of taskStorage into taskList
	_taskList = taskStorage;         
	TaskSorter taskSorter = TaskSorter::getInstance();

	//convert all the task name and search keyword to upper cases to do case insensitive search
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), toupper);

	std::string curTaskName;

	for(unsigned int i = 0; i < _taskList.size(); i++){
		curTaskName = _taskList[i].getTaskName();

		//convert task name to upper cases to do case insensitive search
		std::transform(curTaskName.begin(), curTaskName.end(), curTaskName.begin(), toupper);

		//if the task name contains the keyword, remove the task from the _taskList and put it into the _searchResult
		if(curTaskName.find(keyword) != std::string::npos){                
			_searchResult.push_back(_taskList[i]);
			_taskList.erase(_taskList.begin() + i);
			i--;
		}
	}

	taskSorter.sortTask(_searchResult);

	display.setMainDisplay(_searchResult, WWUtilities::PAGESEARCH);
	display.setSystemResponseSearch(_searchResult.size());
}

// search keyword and time period
void SearchExecutor::searchTask(std::vector<WWTask> taskStorage, std::string keyword, long long startTime, long long endTime, WWDisplay& display){
	_taskList.clear();
	_searchResult.clear();

	//keep a copy of taskStorage into taskList
	_taskList = taskStorage;          
	TaskSorter taskSorter = TaskSorter::getInstance();

	//convert all the task name and search keyword to upper cases to do case insensitive search
	std::transform(keyword.begin(), keyword.end(), keyword.begin(), toupper);

	std::string curTaskName;
	long long curStartTime;
	long long curEndTime;

	for(unsigned int i = 0; i < _taskList.size(); i++){
		curTaskName = _taskList[i].getTaskName();

		//convert the curTaskName to upper cases to do case insensitive search
		std::transform(curTaskName.begin(), curTaskName.end(), curTaskName.begin(), toupper);

		//we find the tasks whos names contain the keyword first
		//if find the keyword, check whether the task time is inside the time period
		if(curTaskName.find(keyword) != std::string::npos){  

			//for deadline task, task is considered within the period as long as the deadline is within the period
			if(_taskList[i].getTaskType() == WWUtilities::DEADLINE){
				
				//timp period of a deadline task with time and date will be considered as both start time and end time
				// are same at the due time
				//time period of a deadline task with only date will be considered as from that date 0000 - 2359
				if(_taskList[i].hasStartTime()){
					curStartTime = (long long)stoi(_taskList[i].getStartDate(), nullptr) * DATE_MULTIPLIER + stoi(_taskList[i].getStartTime());
					curEndTime = curStartTime;				
				} else {
					curStartTime = (long long)stoi(_taskList[i].getStartDate(), nullptr) * DATE_MULTIPLIER;
					curEndTime = (long long)stoi(_taskList[i].getStartDate(), nullptr) * DATE_MULTIPLIER + LARGEST_TIME_INT;
				}

				//if the task satisfies the search criterion, remove the task from the _taskList and put it into the _searchResult
				if(!((curStartTime > endTime)||(curEndTime < startTime))){
					_searchResult.push_back(_taskList[i]);
					_taskList.erase(_taskList.begin() + i);
					i--;
				}
			} else if(_taskList[i].getTaskType() == WWUtilities::TIMED){
				// for timed task, task is considered within the period as long as there is overlap

				// if the start time has only date, the time will be set as 0000
				if(_taskList[i].hasStartTime()){
					curStartTime = (long long)stoi(_taskList[i].getStartDate(), nullptr) * DATE_MULTIPLIER + stoi(_taskList[i].getStartTime());
				} else {
					curStartTime = (long long)stoi(_taskList[i].getStartDate(), nullptr) * DATE_MULTIPLIER;
				}

				// if the end time has only date, the time will be set as 2359
				if(_taskList[i].hasEndTime()){
					curEndTime = (long long)stoi(_taskList[i].getEndDate(), nullptr) * DATE_MULTIPLIER + stoi(_taskList[i].getEndTime());
				} else {
					curEndTime = (long long)stoi(_taskList[i].getEndDate(), nullptr) * DATE_MULTIPLIER + LARGEST_TIME_INT;
				}

				if(!((curStartTime > endTime)||(curEndTime < startTime))){
					_searchResult.push_back(_taskList[i]);
					_taskList.erase(_taskList.begin() + i);
					i--;
				}
			}
		}
	}

	taskSorter.sortTask(_searchResult);

	display.setMainDisplay(_searchResult, WWUtilities::PAGESEARCH);
	display.setSystemResponseSearch(_searchResult.size());
}

void SearchExecutor::getSearchResult(std::vector<WWTask>& searchResult){
	searchResult.clear();
	for(unsigned int i = 0; i < _searchResult.size(); i++){
		searchResult.push_back(_searchResult[i]);
	}
}

void SearchExecutor::getTaskStorage(std::vector<WWTask> resultList, std::vector<WWTask>& taskStorage){
	taskStorage.clear();

	for(unsigned int i = 0; i < _taskList.size(); i++){
		taskStorage.push_back(_taskList[i]);
	}

	for(unsigned int i = 0; i < resultList.size(); i++){
		taskStorage.push_back(resultList[i]);
	}

	//sort the taskStorage after merge
	TaskSorter taskSorter = TaskSorter::getInstance();
	taskSorter.sortTask(taskStorage);
}

