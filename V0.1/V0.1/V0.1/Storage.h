#ifndef Storage_H_
#define Storage_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Task.h"

using namespace std; 

class Storage{
private:
	vector<Task> taskList;

public:
	Storage();
<<<<<<< HEAD
	~Storage();
	void storeTask(string task, string startingTime, string endingTime, string date);
=======

	void storeTask(string task, string startingTime, string endingTime);
>>>>>>> aadd4e3110a98adfe2195bde96f717c7fb5bdbcb
	void saveFile(vector<Task> fileStorage);
	vector<Task> getTaskList();
	void updateTaskList(vector<Task> taskStorage);

};

#endif