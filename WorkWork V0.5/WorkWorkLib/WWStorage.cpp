//@author A0101014L
// WWstorage.cpp

#include "WWStorage.h"
#include "WWTask.h"
#include "WWFileStorage.h"
#include "WWHistoryStorage.h"
#include "WWUtilities.h"
#include "WWLogger.h"
#include <vector>

using namespace std;

const string SAVEOPER_LOG    = "user operation saved";
const string SAVEFILE_LOG    = "text file saved";
const string OPENSUCCESS_LOG = "text file opened successfully";
const string CORRUPTFILE_LOG = "text file corrupted";
const string UNDOSUCCESS_LOG = "undo successful";
const string UNDOFAIL_LOG    = "undo not available";
const string REDOSUCCESS_LOG = "redo successful";
const string REDOFAIL_LOG    = "redo not available";

WWStorage::WWStorage() {
}

void WWStorage::saveOper(const vector<WWTask>& taskStorage, const vector<WWTask>& searchResult, WWUtilities::PageType pageType) {
	_hisStore.saveOper(taskStorage, searchResult, pageType);

	//logging user operation
	WWLogger &log = WWLogger::getInstance();
	log.addLog(SAVEOPER_LOG);
	log.saveLog();
}

void WWStorage::saveFile(vector<WWTask>& fileContent) {
    _fileStore.saveFile(fileContent);

	//logging text file saving
	WWLogger &log = WWLogger::getInstance();
	log.addLog(SAVEFILE_LOG);
	log.saveLog();
}

bool WWStorage::openFile(vector<WWTask>& fileContent, vector<WWTask>& searchResult) {

	bool isOpenFileSuccess = _fileStore.openFile(fileContent);

	if(isOpenFileSuccess) {
		_hisStore.saveOper(fileContent, searchResult, WWUtilities::PAGEALL);

		//logging successful text file opening
		WWLogger &log = WWLogger::getInstance();
		log.addLog(OPENSUCCESS_LOG);
		log.saveLog();
	} else {
		//logging corrupted text file
		WWLogger &log = WWLogger::getInstance();
		log.addLog(CORRUPTFILE_LOG);
		log.saveLog();
	}

	return isOpenFileSuccess;
}

bool WWStorage::undo(vector<WWTask>& taskStorage, vector<WWTask>& searchResult, WWUtilities::PageType& pageType) {

	return _hisStore.Undo(taskStorage, searchResult, pageType);
}

bool WWStorage::redo(vector<WWTask>& taskStorage, vector<WWTask>& searchResult, WWUtilities::PageType& pageType) {

	return _hisStore.Redo(taskStorage, searchResult, pageType);
}