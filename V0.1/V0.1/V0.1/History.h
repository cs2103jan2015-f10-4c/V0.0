


#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Task.h"
#include <stack>

class History{
private:
	stack <vector<Task>> undoStorageList;
	stack <vector<Task>> redoStorageList;
	/*vector<Task> historyTaskList;*/

public:
	History();
	~History();

	void saveOperation(vector<Task> taskStorage);
	bool undo(vector<Task> updatedTaskList);
	bool redo(vector<Task> updatedTaskList);
	
	/*void updateHistoryTaskList(vector<Task> taskStorage);*/
};

#endif

