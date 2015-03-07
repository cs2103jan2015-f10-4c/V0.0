//@author A0099689W
#ifndef WWCOMMANDINTERPRETER_H
#define WWCOMMANDINTERPRETER_H

#include <vector>
#include "WWTask.h"
#include "WWCommand.h"
#include "WWLogger.h"

// This class is used by WWLogic to translate the parsed WWCommand
// into the format that can be processed by WWExecutor.
// Elements that are useful for WWExecutor are extracted from the WWCommand
// object and further processed for easy usage by the executor.
// Sample usage:
// WWCommandInterpreter commandInterpreter;
// commandInterpreter.interpretAdd(addCommand, taskToBeAdded);
// _executor.addTask(taskToBeAdded);
class WWCommandInterpreter {
public:
	WWCommandInterpreter();
	void interpretAdd   (WWCommand, WWTask&);
	void interpretEdit  (WWCommand, int&,WWTask&);
	void interpretSearch(WWCommand, std::vector<std::string>&);
	void interpretDelete(WWCommand, int&);
	void interpretDone  (WWCommand, int&);
	void interpretUndone(WWCommand, int&);

private:
	void separateIndexDetail (std::string, int&, std::string&); 
	int  convertStringToInt  (std::string);

	static const int         INVALID_INDEX;
	static const std::string EMPTY_CONTENT;
	static const std::string SPACE;
	static const std::string NO_INDEX_EXCEPTION;
	static const std::string INTERPRET_ADD_LOG;  
    static const std::string INTERPRET_EDIT_LOG;                     
    static const std::string INTERPRET_DELETE_LOG;                     
    static const std::string INTERPRET_DONE_LOG;                       
    static const std::string INTERPRET_UNDONE_LOG;                      
    static const std::string INTERPRET_SEARCH_LOG;
};
#endif