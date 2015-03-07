//@author A0101014L
// WWFileStorage.h

#ifndef WWFILESTORAGE_H
#define WWFILESTORAGE_H

#include <string>
#include <vector>
#include "WWTask.h"

//WWFileStorage is to save the progress of the program into a .txt file
//Everytime WWExecutor executes an operation, WWExecutor needs WWStorage to save the progress, this is to prevent progress lost when the user accidentally stops the program
//When the program first starts, the content saved from previous usage should be loaded
//The content of each task in the .txt file can also be verified if it is following the format that is stored in a WWTask object. If not, that means the file is corrupted
//WWFileStorage is basically creating a WWTask object with one line of string in the .txt file, and saving the information of a WWTask object to the .txt file with one line of string

class WWFileStorage {
public:

	WWFileStorage();

	bool openFile(std::vector<WWTask>&);
	void saveFile(std::vector<WWTask>&);

private: 

	bool   _isCorruptedFile;
	bool   _isCorruptedToken;

	void        tokenizeContent(std::string, std::vector<std::string>&);
	WWTask      createTaskWithTokens(std::vector<std::string>&);
	void        verifyTokenContent(const std::vector<std::string>&);
	void        adjustTokenContent(std::vector<std::string>&);
	void        adjustDateTime(std::string&, std::string&);
	bool        isNumber(const std::string&);
	bool        stringToBool(std::string);
	std::string boolToString(bool);
	std::string taskToString(WWTask);
};
#endif