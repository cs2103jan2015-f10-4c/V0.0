#include<stack>
#include<string>
#include<vector>
#include"History.h"
#include"Task.h"

using namespace std;


History::History(){};
History::~History(){};



void History::saveOperation(vector<Task>& taskStorage){
	undoStorageList.push(taskStorage);

};

vector<Task> History::undo(){
    
    vector<Task> updatedTaskList;
    
	if (checkUndoEmpty() == true){
        redoStorageList.push(undoStorageList.top());
		undoStorageList.pop();
			if (checkUndoEmpty() == false){
				return updatedTaskList;
			}
			else{
				updatedTaskList = undoStorageList.top();
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
		
		updatedTaskList = redoStorageList.top();
		

		undoStorageList.push(redoStorageList.top());
		redoStorageList.pop();

		return updatedTaskList;
	}
	else{
		return updatedTaskList;
	}
};


stack <vector<Task>> History::getUndoStorageList(){
	return undoStorageList;
}

stack <vector<Task>> History::getRedoStorageList(){
	return redoStorageList;
}

bool History::checkUndoEmpty(){
	bool undoStatus = false;

	if(!undoStorageList.empty()){
		undoStatus = true;
		return undoStatus;
	}
	else{
		return undoStatus;
	}
}

bool History::checkRedoEmpty(){
	bool redoStatus = false;

	if(!redoStorageList.empty()){
		redoStatus = true;
		return redoStatus;
	}
	else{
		return redoStatus;
	}
}




