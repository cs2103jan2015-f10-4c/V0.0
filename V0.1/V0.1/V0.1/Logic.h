

#ifndef Logic_H
#define Logic_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
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
	Logic();
	~Logic();
	void addExecutor(string, string, string);
	void deleteExecutor(int);
	void searchExecutor(string);
	void editExecutor(int, string, string, string);
	void displayResult(vector<Task>);

};



#endift