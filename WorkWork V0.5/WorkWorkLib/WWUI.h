//@author A0097195N
//Description: This class sends the user input and the current page index to WWLogic
//             This class is used by WWGUI class to retrieve the display information for display

#ifndef WWUI_H_
#define WWUI_H_

#include <string>
#include <iostream>
#include "WWLogic.h"
#include "WWDisplay.h"
#include "WWUIConverter.h"
#include "WWLogger.h"

class WWUI {
private:
	static const std::string LOG_USER_INPUT;
	static const std::string LOG_DISPLAY;
	static const std::string LOG_DISPLAY_SYSTEM_RESPONSE;
	static const std::string LOG_GET_FLOATING_TASK;
	static const std::string LOG_GET_PAGE_INDEX;

	std::string _systemResponse;
	WWLogic _logic;
	WWDisplay _display;
	std::vector<std::vector<std::string>> _taskContent;
	std::string _currentFloatingTask;
	int _currentPageIndex;
	WWUIConverter _convert;
	
public:
	WWUI();
	void runProgram(std::string userInput, int PageIndex);
	std::vector<std::vector<std::string>> display();
	std::string displaySystemResponse();
	std::string getFloatingTask();
	int getPageIndex();
};
#endif //WWUI_H

