//@author A0099689W
#ifndef WWLOGIC_H
#define WWLOGIC_H

#include "WWParser.h"
#include "WWCommand.h"
#include "WWTask.h"
#include "WWExecutor.h"
#include "WWDisplay.h"
#include "WWUtilities.h"
#include "WWCommandInterpreter.h"
#include "WWLogger.h"


// This class serves to retrieve userinput from UI and analyse
// the input by using WWParser and WWCommandInterpreter in order 
// to facilitate the execution by WWExecutor to fullfill the user command.
// Upon declaration, WWLogic will retrieve previous tasks 
// saved through openFile method provided by WWExecutor. 
class WWLogic {
public:

	WWLogic();

	void      runInput  (std::string, WWUtilities::PageType);
	WWDisplay getDisplay();

private:
     
	WWParser             _parser;
	WWExecutor           _executor;
	WWDisplay            _display;
	WWCommandInterpreter _commandInterpreter;
	
	void executeCommand(WWCommand, WWUtilities::PageType);
	
	static const int         ERROR_INDEX;
	static const std::string ADD_LOG;         
    static const std::string EDIT_LOG;          
    static const std::string DELETE_LOG;        
    static const std::string DELETEALL_LOG;      
    static const std::string SEARCH_LOG;         
    static const std::string DONE_LOG;           
    static const std::string UNDONE_LOG;         
    static const std::string VIEWALL_LOG;        
    static const std::string VIEWTIMED_LOG;      
    static const std::string VIEWFLOATING_LOG;   
    static const std::string VIEWDONE_LOG;       
    static const std::string VIEWUNDONE_LOG;     
    static const std::string VIEWDEADLINE_LOG;  
    static const std::string VIEWOVERDUE_LOG ;  
    static const std::string VIEWTODAY_LOG; 
    static const std::string UNDO_LOG;      
    static const std::string REDO_LOG;       
    static const std::string REFRESH_LOG;      
    static const std::string EXIT_LOG;

};
#endif