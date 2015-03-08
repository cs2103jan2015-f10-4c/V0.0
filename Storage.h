#ifndef Storage_H_
#define Storage_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std; 

struct Task{
	string taskDescription;
	string startingTime;
	string endingTIme;
	string date;
};

class Storage{
private:
	vector<Task> taskList;

public:
	Storage();

	void storeTask(string task, string startingTime, string endingTime, string date);
	void saveFile(vector<Task> fileStorage);

};

#endif