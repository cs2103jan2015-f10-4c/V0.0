
// @author A0116363L
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
	static const string FLOATING_RETRIVED_SORTED;
	static const string DEADLINE_RETRIVED_SORTED; 
	static const string TIMED_RETRIVED_SORTED; 
	static const string OVERDUE_RETRIVED_SORTED;
	static const string ONGOING_RETRIVED_SORTED;
	static const string DONE_RETRIVED_SORTED;

public:

	Display();
	~Display();
	Sorter sorter;
	void setDefaultDisplay(vector<Task>&);
	string setVariousDisplay(vector<Task>&, string);
    string getContent();

	vector<Task> getFloatingTask(vector<Task>);//sorting alphabetically
	vector<Task> getDeadlineTask(vector<Task>);//sorting according to endingtime
	vector<Task> getTimedTask(vector<Task>);//sorting according  to starting time
	vector<Task> getOverdueTask(vector<Task>);//soring alphabetically
	vector<Task> getDoneTask(vector<Task>);//sorting same as above
	vector<Task> getOngoingTask(vector<Task>);//sorting same as above
};
#endif
