#include<stack>
#include<string>
#include<vector>
#include"History.h"
#include"Task.h"

using namespace std;


History::History(){};
History::~History(){};



void History::saveOperation(vector<Task>& taskStorage){
	_undoStorageList.push(taskStorage);

};

vector<Task> History::undo(){
    
    vector<Task> updatedTaskList;
    
	if (checkUndoEmpty() == true){
        _redoStorageList.push(_undoStorageList.top());
		_undoStorageList.pop();
			if (checkUndoEmpty() == false){
				return updatedTaskList;
			}
			else{
				updatedTaskList = _undoStorageList.top();
			}
			
        return updatedTaskList;
    }
	else{
		return updatedTaskList;
	}
};


vector<Task> History::redo(){
	vector<Task> updatedTaskList;

	if (checkRedoEmpty() == true){
		
		updatedTaskList = _redoStorageList.top();
		

		_undoStorageList.push(_redoStorageList.top());
		_redoStorageList.pop();

		return updatedTaskList;
	}
	else{
		return updatedTaskList;
	}
};


stack <vector<Task>> History::getUndoStorageList(){
	return _undoStorageList;
}

stack <vector<Task>> History::getRedoStorageList(){
	return _redoStorageList;
}

bool History::checkUndoEmpty(){
	bool undoStatus = false;

	if(!_undoStorageList.empty()){
		undoStatus = true;
		return undoStatus;
	}
	else{
		return undoStatus;
	}
}

bool History::checkRedoEmpty(){
	bool redoStatus = false;

	if(!_redoStorageList.empty()){
		redoStatus = true;
		return redoStatus;
	}
	else{
		return redoStatus;
	}
}




