

#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <sstream>
#include "Task.h"
#include "Storage.h"
#include "DisplayWindow.h"
#include "Sorter.h"

class Display{
private:
	
	DisplayWindow _mainDisplay;

	vector<Task> getFloatingTask();//sorting alphabetical
	vector<Task> getDeadlineTask();//sorting according to time
	vector<Task> getTimedTask();//sorting according  to starting time
	vector<Task> getOverdueTask(vector<Task>);//soring Floating +deadline +timed 
	vector<Task> getDoneTask(vector<Task>);//sorting same as above
	vector<Task> getOngoingTask(vector<Task>);//sorting same as above


	//static const string FLOATING_TASK;
	//static const string DEADLINE_TASK;
	//static const string TIMED_TASK;
	//static const string OVERDUE_TASK;
	//static const string DONE_TASK;
	//static const string ONGOING_TASK;
	//static const string FLOATING_TASK;

public:

	Display();
	~Display();
    Storage storage;
	Sorter sorter;
	void setDefaultDisplay();
	void setVariousDisplay(string);


};
#endif
