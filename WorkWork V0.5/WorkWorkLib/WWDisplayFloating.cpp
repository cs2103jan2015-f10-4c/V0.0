//@author A0105476E

//***************************************************************
//			      Class WWDisplayFloating
//					  Author: AI YUE
//
//			    File: WWDisplayFloating.cpp
//
// WWDisplayFloating class is used to set display of the random
// floating task
//***************************************************************

#include <vector>
#include <stdlib.h>
#include "WWTask.h"
#include "WWDisplayFloating.h"

const string MSG_EMPTY_FLOATING_TASK = "All floating task done!";

WWDisplayFloating::WWDisplayFloating(){
}

void WWDisplayFloating::generateRandomTask(std::vector<WWTask> floatingTaskList){
	unsigned int size = floatingTaskList.size();

	if(size > 0){
		int randomIndex = rand()%size;
		_randomFloatingTaskName = floatingTaskList[randomIndex].getTaskName();
	} else {
		_randomFloatingTaskName = MSG_EMPTY_FLOATING_TASK;
	}
}

std::string WWDisplayFloating::getFloatingTaskName(){
	return _randomFloatingTaskName;
}