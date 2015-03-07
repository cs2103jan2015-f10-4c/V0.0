//@author A0101014L
// WWHistoryStorage.h

#ifndef WWHISTORYSTORAGE_H
#define WWHISTORYSTORAGE_H

#include <string>
#include <vector>
#include <stack>
#include "WWTask.h"
#include "WWUtilities.h"

//WWHistoryStorage is used to track all important operations that have been done by the user
//Every important operations made by the user will be saved as a vector fo WWTask
//The user is then able to undo or redo operations whenever needed

class WWHistoryStorage {
public:

	WWHistoryStorage();

	void saveOper(const std::vector<WWTask>&, const std::vector<WWTask>&, WWUtilities::PageType);
	bool Undo(std::vector<WWTask>&, std::vector<WWTask>&, WWUtilities::PageType&);
	bool Redo(std::vector<WWTask>&, std::vector<WWTask>&, WWUtilities::PageType&);
	
private:

	std::stack<std::vector<WWTask>>   _undoTaskStorage;
	std::stack<std::vector<WWTask>>   _undoSearchResult;
	std::stack<std::vector<WWTask>>   _redoTaskStorage;
	std::stack<std::vector<WWTask>>   _redoSearchResult;
	std::stack<WWUtilities::PageType> _undoPageType;
	std::stack<WWUtilities::PageType> _redoPageType;

	void WWHistoryStorage::clearRedoStacks();
};
#endif