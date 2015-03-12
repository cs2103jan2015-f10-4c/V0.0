

#ifndef Logic_H
#define Logic_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include "Storage.h"
#include "History.h"
#include "Task.h"

using namespace std;

class Logic{
private:

	Storage storage;
	History history;
	Task task;
	

public:
    vector<Task> taskList;
    vector<Task> deadlineList;
    vector<Task> floatingList;
	Logic();
	~Logic();
	/*void addExecutor(string, string, string);
	void deleteExecutor(int);
	void searchExecutor(string);
	void editExecutor(int, string, string, string);
	void displayResult(vector<Task>);
    */
    void addTask(string, string, string);
	void addDeadlineTask(string, string);
	void addFloatingTask(string);
    void updateStorage();
	void updateDeadlineStorage();
	void updateFloatingStorage();
    void deleteTask(int);
    //void editTaskTitle(int, string);
    //void editTaskDate(int, string);
    //void editTaskStartTime(int, string);
    //void editTaskEndTime(int, string);
	void editTask(int, string, string, string);
    void searchTask(string);
	void displayAll();
	void displaySpecified(vector<Task>);
};



#endif
