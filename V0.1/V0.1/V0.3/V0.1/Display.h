

#ifndef DISPLAY_H
#define DISPLAY_H

#include <vector>
#include <string>
#include <sstream>
#include "Task.h"
#include "DisplayWindow.h"
#include "Sorter.h"

class Display{
private:
	
	DisplayWindow _mainDisplay;

	vector<Task> getFloatingTask(vector<Task>);//sorting alphabetical
	vector<Task> getDeadlineTask(vector<Task>);//sorting according to time
	vector<Task> getTimedTask(vector<Task>);//sorting according  to starting time
	vector<Task> getOverdueTask(vector<Task>);//soring Floating +deadline +timed 
	vector<Task> getDoneTask(vector<Task>);//sorting same as above
	vector<Task> getOngoingTask(vector<Task>);//sorting same as above


	static const string FLOATING_TASK;
	static const string DEADLINE_TASK;
	static const string TIMED_TASK;
	static const string OVERDUE_TASK;
	static const string DONE_TASK;
	static const string ONGOING_TASK;
	static const string ALL_TASK;
	static const string INVALID_DISPLAYTYPE;
	static const string NO_FLOATING;
	static const string NO_DEADLINE;
	static const string NO_TIMED;
	static const string NO_OVERDUE;
	static const string NO_DONE;
	static const string NO_ONGOING;
	static const string DISPLAYED;

public:

	Display();
	~Display();
	Sorter sorter;
	void setDefaultDisplay(vector<Task>&);
	string setVariousDisplay(vector<Task>&, string);
    string getContent();

};
#endif
