//@author A0114946B

#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "Task.h"

//History class is to save all operations done by the programme
//Every taskList generated after every operation will be saved in a vector of Task
//History performs undo and redo command for users
class History{
private:
	stack <vector<Task>> _undoStorageList;
	stack <vector<Task>> _redoStorageList;
	
public:
	History();
	~History();

	stack <vector<Task>> getUndoStorageList();
	stack <vector<Task>> getRedoStorageList();
	void saveOperation(vector<Task>&);
	vector<Task> undo();
	vector<Task> redo();
	bool checkUndoEmpty();
	bool checkRedoEmpty();
};

#endif

