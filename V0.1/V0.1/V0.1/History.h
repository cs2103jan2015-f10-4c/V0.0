


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
	stack <vector<Task>> _undoStorageList;
	stack <vector<Task>> _redoStorageList;
	

public:
	History();
	~History();

	void saveOperation(vector<Task>& taskStorage);
	vector<Task> undo();
	vector<Task> redo();
	stack <vector<Task>> getUndoStorageList();
	stack <vector<Task>> getRedoStorageList();
	bool checkUndoEmpty();
	bool checkRedoEmpty();
};

#endif

