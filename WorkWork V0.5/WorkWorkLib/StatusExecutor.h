//@author A0105476E

//*********************************************************************
//			         Class StatusExecutor
//					  Author: AI YUE
//
//					File: StatusExecutor.cpp
//
// StatusExecutor class is used when executor want to change the status
// of a task.
// Two methods are available: 1: markDone: mark status to done
//							  2: markUndone: mark status to undone
//*********************************************************************

#ifndef STATUSEXECUTOR_H
#define STATUSEXECUTOR_H

#include <vector>
#include "WWDisplay.h"
#include "WWTask.h"
#include "WWUtilities.h"

class StatusExecutor{
public:
	StatusExecutor(void);

	void markDone(std::vector<WWTask>&, unsigned int, WWUtilities::PageType, WWDisplay&);
	void markUndone(std::vector<WWTask>&, unsigned int, WWUtilities::PageType, WWDisplay&);
};

#endif
