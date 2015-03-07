//@author A0105476E

//*************************************************************
//			      Class WWSystemResponse
//					  Author: AI YUE
//
//			    File: WWSystemResponse.h
//
// WWSystemResponse class is used to set the system response of 
// different actions
//**************************************************************

#ifndef WWSYSTEMRESPONSE_H
#define WWSYSTEMRESPONSE_H

#include "WWUtilities.h"

class WWSystemResponse {
private:
	std::string _systemResponse;

	//for taskName that is longer than 50 characters, chop the part beyond 50 characters and add ... behind 
	std::string chopTaskName(std::string); 

public:
	WWSystemResponse();
	
	//set systemResponse for openFile
	void setSystemResponseOpenFile(bool);

	//set systemResponse for add, delete, edit, complete and incomplete
	//if CommandType is not one of the above, 
	//throw a exception showing wrong set system response function used
	void setSystemResponse(WWUtilities::CommandType, std::string, bool);

	//set systemResponse for deleteall
	void setSystemResponseDeleteAll();

	//set systemResponse for undo and redo
	//take in a CommandType and a bool marks the status of the operation
	//if CommandType is not one of the above
	//throw a exception showing wrong set system response function used
	void setSystemResponseUndoRedo(WWUtilities::CommandType, bool);

	//set the systemResponse for search
	//take in a integer telling the number of search results found
	void setSystemResponseSearch(int);

	//set the systemResponse for different view 
	//take in a CommandType telling the viewing type
	//and a integer telling the number of tasks of this type
	//if CommandType is not one of the above
	//throw a exception showing wrong set system response function used
	void setSystemResponseView(WWUtilities::CommandType, int);

	//set the systemResponse invalid
	void setSystemResponseInvalid();

	std::string getSystemResponse();
};
#endif