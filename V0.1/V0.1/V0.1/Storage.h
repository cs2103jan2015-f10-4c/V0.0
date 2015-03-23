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
	vector<Task> taskList;
	vector<Task> deadlineTaskList;
	vector<Task> floatingTaskList;
	History historyStorage;

public:
	Storage();
	~Storage();

	//void storeTask(string task, string startingTime, string endingTime);
	void saveFile();
	vector<Task> getTaskList();
	vector<Task> getDeadlineTaskList();
	vector<Task> getFloatingTaskList();
	void updateTaskList(vector<Task> taskStorage);
	void updateDeadlineTaskList(vector<Task> deadlineTaskStorage);
	void updateFloatingTaskList(vector<Task> floatingTaskStorage);
	void saveOperation(vector<Task> taskStorage);

};

#endif