//@author A0114946B

#ifndef Storage_H_
#define Storage_H_

#include <iostream>
#include <string>
#include <vector>
#include "Task.h"

//Storage class is to retrieve tasklist from .txt file in local computer if .txt file exists
//Storage creates a .txt file if there is no existing one
//Storage save any progross made to the .txt file after each operation
class Storage{
private:

	string _outFilePath;
	string _userInputPath;
	
public:
	Storage();
	~Storage();

	bool hasDirectory();
	void saveFile(vector<Task>&);
	void readFile(vector<Task>&);
	void loadTask(vector<string>,  vector<Task>&);
	void setUserInputPath(string);
	void retrieveTimedTask(string, vector<Task>&);
	void retrieveDeadlineTask(string, vector<Task>&);
	void retrieveFloatingTask(string, vector<Task>&);
	string removeIndex(string);
	string getTaskName(string);
	string getStartingTime(string);
	string getEndingTime(string);
	string getStatus(string);
	string getDueTime(string);
	string getOutfilePath();
	string getUserInputPath();
	string createFilePath();
};

#endif