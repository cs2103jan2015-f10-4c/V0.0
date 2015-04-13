#ifndef SYSTEMRESPONSE_H_
#define SYSTEMRESPONSE_H_

#define MAX_CHAR 255

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Logger.h"

using namespace std;

class SystemResponse{
private:
	static const string MESSAGE_WELCOME;
    static const string MESSAGE_WELCOME_EXISTING_USER;
	static const string MESSAGE_ADD;
	static const string MESSAGE_ADD_FAIL_INVALID_TIME;
	static const string MESSAGE_ADD_FAIL_INCORRECT_FORMAT;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_DELETE_FAIL;
	static const string MESSAGE_EDIT;
	static const string MESSAGE_EDIT_FAIL;
	static const string MESSAGE_MARK_DONE;
	static const string MESSAGE_MARK_DONE_FAIL;
	static const string MESSAGE_MARK_DONE_FAIL_ALREADY_DONE;
	static const string MESSAGE_SEARCH_FAIL;
	static const string MESSAGE_SEARCH_SUCCESSFUL;
	static const string MESSAGE_UNDO;
	static const string MESSAGE_UNDO_FAIL;
	static const string MESSAGE_REDO;
	static const string MESSAGE_REDO_FAIL;
	static const string MESSAGE_FAIL_TO_DISPLAY_VARIOUS;
	static const string MESSAGE_NO_DIRECTORY;
	static const string MESSAGE_INVALID_DIRECTORY;
	static const string MESSAGE_VALID_DIRECTORY;
	static const string MESSAGE_INVALID_COMMAND;
	static const string MESSAGE_CLEAR_SUCCESSFUL;
	//static char outputBuffer[MAX_CHAR];

public:

	char outputBuffer[MAX_CHAR];

	SystemResponse();
	~SystemResponse();
	string welcomeExistingMessage();
	string addResponse(bool,bool);
	string deleteResponse(bool, int);
	string editResponse(bool, int);
	string searchResponse(bool);
	string markDoneResponse(bool,bool, int);
	string undoResponse(bool);
	string redoResponse(bool);
	string dispVariousResponse(string);
	string tellResponse();
	string noDirectoryResponse();
	string DirectoryResponse(bool);
	string invalidResponse();
	string clearAllResponse();
};
#endif
