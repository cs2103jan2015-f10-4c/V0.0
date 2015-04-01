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
	/*vector<Task> timedTaskList;
	vector<Task> _taskList;
	vector<Task> deadlineTaskList;
	vector<Task> floatingTaskList;
	*/
	/*History historyStorage;*/
	
	vector<string> tempTask;
	string outFilePath;
	string _userInputPath;
	

public:
	Storage();
	~Storage();

	//void storeTask(string task, string startingTime, string endingTime);
	
	/*vector<Task> getTimedTaskList();
	vector<Task> getTaskList();
	vector<Task> getDeadlineTaskList();
	vector<Task> getFloatingTaskList();*/

	/*void updateTaskList(vector<Task> taskStorage);
	void updateDeadlineTaskList(vector<Task> deadlineTaskStorage);
	void updateFloatingTaskList(vector<Task> floatingTaskStorage);
	void saveOperation();
	void undo();
	void redo();*/

	string createFile();
	void saveFile(vector<Task>& taskList);
	void readFile(vector<Task>& taskList);
	void loadTask(vector<string> taskLine,  vector<Task>& taskList);
	string removeIndex(string input);
	string getTaskName(string input);
	string getStartingTime(string input);
	string getEndingTime(string input);
	string getStatus(string input);
	string getDueTime(string input);
	void test();
	string getOutfilePath();
	bool hasDirectory();
	string getUserInputPath();
	void setUserInputPath(string userInputPath);
	string createFilePath();
};

#endif