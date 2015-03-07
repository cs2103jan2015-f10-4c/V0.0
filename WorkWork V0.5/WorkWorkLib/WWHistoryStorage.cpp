//@author A0101014L
// WWHistoryStorage.cpp

#include "WWHistoryStorage.h"
#include "WWTask.h"
#include "WWUtilities.h"
#include <stack>
#include <string>
#include <vector>

using namespace std;

const int UNDO_MINSIZE = 2;

const string UNDO_EXCEPTION = "undo not available";
const string REDO_EXCEPTION = "redo not available";

WWHistoryStorage::WWHistoryStorage() {
}

//save every important operation by the user to a stack
//meanwhile search result and page type used for the display on GUI are also saved
//this helps the user get back to the corresponding display page where he made an operation
void WWHistoryStorage::saveOper(const vector<WWTask>& taskStorage, const vector<WWTask>& searchResult, WWUtilities::PageType pageType) {
	clearRedoStacks();   //once a new operation is saved, redo will no longer be available unless the user makes further undo cammand

	_undoTaskStorage.push(taskStorage);
	_undoSearchResult.push(searchResult);
	_undoPageType.push(pageType);
}

//user can undo an operation
//taskStorage is modified into the previous state of taskStorage, so are searchResult and pageType
bool WWHistoryStorage::Undo(vector<WWTask>& taskStorage, vector<WWTask>& searchResult, WWUtilities::PageType& pageType) {
	bool undoStatus = false;

	if(!_undoTaskStorage.empty()) {  

		//top of undo stacks is are pushed into redo stacks for use of future redo cammand
		_redoTaskStorage.push(_undoTaskStorage.top());
		_redoSearchResult.push(_undoSearchResult.top());
		_redoPageType.push(_undoPageType.top());

		//once the program starts initially, size of undo stacks is 2
		//only if size of undo stacks is >= 2, undo is available. otherwise, the initial state when program first starts is reached
		if(_undoTaskStorage.size() > UNDO_MINSIZE) {
			_undoTaskStorage.pop();
			_undoSearchResult.pop();
			_undoPageType.pop();

			undoStatus = true;
		}

		taskStorage.clear();
		searchResult.clear();

		//taskStorage is modified into its previous state, which is the top of undo stack. if initial state is reached and undo is not available, taskStorage will stay at initial state
		//similar for searchResult and pageType
		for(unsigned int i=0; i<_undoTaskStorage.top().size(); i++) {
			taskStorage.push_back(_undoTaskStorage.top()[i]);
		}
		for(unsigned int i=0; i<_undoSearchResult.top().size(); i++) {
			searchResult.push_back(_undoSearchResult.top()[i]);
		}
		pageType = _undoPageType.top();
	}

	//if undo not available, redo stacks will pop to get rid of that extra copy of the top of undo stacks
	if(undoStatus == false) {
		_redoTaskStorage.pop();
		_redoSearchResult.pop();
		_redoPageType.pop();
	}

	return undoStatus;
}

//user can undo an operation
//taskStorage is modified into the state of before the last undo, so are searchResult and pageType
bool WWHistoryStorage::Redo(vector<WWTask>& taskStorage, vector<WWTask>& searchResult, WWUtilities::PageType& pageType) {
	bool redoStatus = false;

	//redo is available when redo stacks are not empty
	if(!_redoTaskStorage.empty()) {
		taskStorage.clear();
		searchResult.clear();

		//taskStorage is modified into the state before the last undo, which is the top of redo stack. 
		//similar for searchResult and pageType
		for(unsigned int i=0; i<_redoTaskStorage.top().size(); i++) {
			taskStorage.push_back(_redoTaskStorage.top()[i]);
		}	
		for(unsigned int i=0; i < _redoSearchResult.top().size(); i++) {
			searchResult.push_back(_redoSearchResult.top()[i]);
		}
		pageType = _redoPageType.top();

		//top of redo stacks is pushed into undo stacks for further undo command
		_undoTaskStorage.push(_redoTaskStorage.top());
		_undoSearchResult.push(_redoSearchResult.top());
		_undoPageType.push(_redoPageType.top());

		_redoTaskStorage.pop();
		_redoSearchResult.pop();
		_redoPageType.pop();

		redoStatus = true;
	}

	//if redo not available, taskStorage, searchResult and pageType are not modified

	return redoStatus;
}

//clear all redo stacks
void WWHistoryStorage::clearRedoStacks() {
	while(!_redoTaskStorage.empty()) {
		_redoTaskStorage.pop();
		_redoSearchResult.pop();
		_redoPageType.pop();
	}
}