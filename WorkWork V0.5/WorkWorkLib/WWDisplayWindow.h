//@author A0099689W
#ifndef WWDISPLAYWINDOW_H
#define WWDISPLAYWINDOW_H

#include <string>
#include <vector>
#include "WWTask.h"
#include "WWConverter.h"

// This class is used to generate the display information on
// the main window for the GUI.
// After passing a vector of task to the setContent method,
// the desired main display will be stored in a vector of vector of string.
// The client can retrieve the main display through the getContent method.
class WWDisplayWindow{
public: 
	WWDisplayWindow();
	void setContent(std::vector<WWTask>);
	std::vector<std::vector<std::string>>& getContent();   

private:
	std::string getDisplayStatus(WWTask);
	std::string getOutputForTimedtask(std::string, std::string, std::string, std::string);
	
	std::vector<std::vector<std::string>> _displayDetails;
	WWConverter _displayConverter;

	static const std::string EMPTY_CONTENT;
    static const std::string LABEL_NEWLINE;
    static const std::string LABEL_FROM;   
    static const std::string LABEL_TO;              
    static const std::string LABEL_SEPARATE_DATETIME; 
    static const std::string LABEL_DUE;               
    static const std::string STATUS_TODAY;            
    static const std::string STATUS_OVERDUE;       
    static const std::string STATUS_DONE;            
    static const std::string STATUS_UNDONE; 
	static const std::string WRONG_TASK_TYPE_EXCEPTION;
	static const std::string MAIN_WINDOW_DISPLAY_LOG;
};

#endif