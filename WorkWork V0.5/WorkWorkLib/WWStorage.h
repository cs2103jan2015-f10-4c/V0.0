//@author A0101014L
// WWStorage.h

#ifndef WWSTORAGE_H
#define WWSTORAGE_H

#include "WWTask.h"
#include "WWFileStorage.h"
#include "WWHistoryStorage.h"
#include <vector>

//WWStorage basically groups all public methods in WWFileStorage and WWHistoryStorage
//WWExecutor will then only interact with WWStorage instead of using methods of the other two

class WWStorage {
public:

	WWStorage();

	void saveOper(const std::vector<WWTask>&, const std::vector<WWTask>&, WWUtilities::PageType);
	void saveFile(std::vector<WWTask>&);
	bool openFile(std::vector<WWTask>&, std::vector<WWTask>&);
	bool undo(std::vector<WWTask>&, std::vector<WWTask>&, WWUtilities::PageType&);
	bool redo(std::vector<WWTask>&, std::vector<WWTask>&, WWUtilities::PageType&);

private:

	WWFileStorage    _fileStore;
	WWHistoryStorage _hisStore;
};
#endif
