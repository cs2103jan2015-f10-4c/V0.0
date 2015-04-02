#ifndef SYSTEMRESPONSE_H_
#define SYSTEMRESPONSE_H_

#define MAX_CHAR 255

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class SystemResponse{
private:
	static const string MESSAGE_WELCOME;
    static const string MESSAGE_WELCOME_EXISTING_USER;
	static const string MESSAGE_ADD;
	static const string MESSAGE_ADD_FAIL;
	static const string MESSAGE_DELETE;
	static const string MESSAGE_DELETE_FAIL;
	static const string MESSAGE_EDIT;
	static const string MESSAGE_EDIT_FAIL;
	static const string MESSAGE_MARK_DONE;
	static const string MESSAGE_MARK_DONE_FAIL;
	static const string MESSAGE_MARK_DONE_FAIL_ALREADY_DONE;
	static const string MESSAGE_SEARCH_FAIL;
	static const string MESSAGE_UNDO;
	static const string MESSAGE_UNDO_FAIL;
	static const string MESSAGE_REDO;
	static const string MESSAGE_REDO_FAIL;
	static const string MESSAGE_FAIL_TO_DISPLAY_VARIOUS;
	static const string MESSAGE_NO_DIRECTORY;

	//static char outputBuffer[MAX_CHAR];

public:

	char outputBuffer[MAX_CHAR];

	SystemResponse();
	~SystemResponse();
	string welcomeExistingMessage();
	string addResponse(bool);
	string deleteResponse(bool, int);
	string editResponse(bool, int);
	string searchResponse(bool);
	string markDoneResponse(bool, int);
	string undoResponse(bool);
	string redoResponse(bool);
	string dispVariousResponse(string);
	string tellResponse();
	string noDirectoryResponse();
};
#endif
