#ifndef Storage_H_
#define Storage_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Task.h"
#include "History.h"

using namespace std; 

class Storage{
private:
	vector<Task> timedTaskList;
	vector<Task> taskList;
	vector<Task> deadlineTaskList;
	vector<Task> floatingTaskList;
	
	History historyStorage;
	
	vector<string> tempTask;
	
	/*vector<string> tempDeadlineTask;
	vector<string> tempFloatingTask;*/

public:
	Storage();
	~Storage();

	//void storeTask(string task, string startingTime, string endingTime);
	void saveFile();
	vector<Task> getTimedTaskList();
	vector<Task> getTaskList();
	vector<Task> getDeadlineTaskList();
	vector<Task> getFloatingTaskList();
	void updateTaskList(vector<Task> taskStorage);
	void updateDeadlineTaskList(vector<Task> deadlineTaskStorage);
	void updateFloatingTaskList(vector<Task> floatingTaskStorage);
	void saveOperation();
	void undo();
	void redo();
	void readFile();
	void loadTask(vector<string> taskLine);
	string removeIndex(string input);
	string getTaskName(string input);
	string getStartingTime(string input);
	string getEndingTime(string input);
	string getStatus(string input);
	string getDueTime(string input);

};

#endif