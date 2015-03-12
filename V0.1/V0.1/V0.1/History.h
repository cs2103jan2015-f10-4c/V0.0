


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
	stack <vector<Task>> undoTaskStorage;




public:
	History();
	~History();

	void saveOperation(vector<Task> taskStorage);
	void undo(vector<Task> taskStorage);

};

#endif

