#include<stack>
#include<string>
#include<vector>
#include"History.h"
#include"Task.h"

using namespace std;

void History::saveOperation(vector<Task> taskStorage){
	undoTaskStorage.push(taskStorage);

};
void History::undo(vector<Task> taskStorage){
	if (undoTaskStorage.size() > 2){
		undoTaskStorage.pop();
	}

	for (int i=0; i<undoTaskStorage.top().size(); i++){
		taskStorage.push_back(undoTaskStorage.top()[i]);
	}
};