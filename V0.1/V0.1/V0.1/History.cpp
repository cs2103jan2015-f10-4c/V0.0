//@author A0114946B

#include <assert.h>
#include "History.h"

using namespace std;

//constructor
History::History(){
}

//destructor
History::~History(){
}

stack <vector<Task>> History::getUndoStorageList(){
	return _undoStorageList;
}

stack <vector<Task>> History::getRedoStorageList(){
	return _redoStorageList;
}

//save operation in term of every tasklist after each operation to the undo stack
//one vector of Task is one unit in the stack
//the newest tasklist after most recent operation will be at top of stack
void History::saveOperation(vector<Task>& taskStorage){
	_undoStorageList.push(taskStorage);

};

//undo an operation by users
//if undo is available, return the tasklist at previous command entered by users
//if undo is not available, retuen empty tasklist
vector<Task> History::undo(){
    
    vector<Task> updatedTaskList;
    
	//whether the undo stack is empty, undo is only available when it is not empty
	if (checkUndoEmpty() == true){

		//transfer the latest tasklist from undo stack to redo stack
        _redoStorageList.push(_undoStorageList.top());
		_undoStorageList.pop();
			
			//if only one operation made, undo returns empty
			//if not only one operation made, undo return tasklist of previous state
			if (checkUndoEmpty() == false){
				return updatedTaskList;
			}
			else{
				updatedTaskList = _undoStorageList.top();
			}
			
        return updatedTaskList;
    }
	else{
		assert(checkUndoEmpty() == false);
		return updatedTaskList;
	}
}

//redo an operation after undo by users
//if redo is available, returns tasklist of state before last undo
//if redo is not availble, returns empty tasklist
vector<Task> History::redo(){
	vector<Task> updatedTaskList;

	//redo is available only when redo stack is not empty
	if (checkRedoEmpty() == true){
		
		updatedTaskList = _redoStorageList.top();
		
		//transfer tasklist back from redo stack to undo stack
		_undoStorageList.push(_redoStorageList.top());
		_redoStorageList.pop();

		return updatedTaskList;
	}
	else{
		assert(checkRedoEmpty() == false);
		return updatedTaskList;
	}
}

//to determine whether undo stack is empty
//return true when it is not empty
//return false when it is empty
bool History::checkUndoEmpty(){
	bool undoStatus = false;

	if(!_undoStorageList.empty()){
		undoStatus = true;
		assert(undoStatus == true);
		return undoStatus;
	}
	else{
		assert(undoStatus == false);
		return undoStatus;
	}
}

//to determine whether redo stack is empty
//return true when it is not empty
//return false when it is empty
bool History::checkRedoEmpty(){
	bool redoStatus = false;

	if(!_redoStorageList.empty()){
		redoStatus = true;
		assert(redoStatus == true);
		return redoStatus;
	}
	else{
		assert(redoStatus == false);
		return redoStatus;
	}
}




