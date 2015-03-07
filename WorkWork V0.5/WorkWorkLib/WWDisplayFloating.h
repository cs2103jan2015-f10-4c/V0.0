//@author A0105476E

//***************************************************************
//			      Class WWDisplayFloating
//					  Author: AI YUE
//
//			    File: WWDisplayFloating.h
//
// WWDisplayFloating class is used to set display of the random
// floating task
//***************************************************************

#ifndef WWDISPLAYFLOATING_H
#define WWDISPLAYFLOATING_H

#include <vector>
#include "WWTask.h"

using namespace std;

class WWDisplayFloating{
public:
	WWDisplayFloating();

	// this method will generate a random task from the vector passed in and
	// put the task name inside _randomFloatingTaskName
	void generateRandomTask(std::vector<WWTask>);

	std::string getFloatingTaskName();

private:
	std::string _randomFloatingTaskName;

};

#endif