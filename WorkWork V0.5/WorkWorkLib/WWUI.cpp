//@author A0097195N
#include "WWUI.h"
//magic strings used for logging
const std::string WWUI::LOG_USER_INPUT = "User Input: ";	
const std::string WWUI::LOG_DISPLAY = "WWUI display function called";
const std::string WWUI::LOG_DISPLAY_SYSTEM_RESPONSE = "WWUI displaySystemResponse function called";
const std::string WWUI::LOG_GET_FLOATING_TASK = "WWUI getFloatingTask function called";
const std::string WWUI::LOG_GET_PAGE_INDEX = "WWUI getPageIndex function called";

WWUI::WWUI() {
}

//This method passes the user input and the current PageIndex to WWLogic
void WWUI::runProgram(std::string userInput, int PageIndex) {
	WWLogger& logUI = WWLogger::getInstance();
	logUI.addLog(LOG_USER_INPUT + userInput);

	WWUtilities::PageType pageType = _convert.changeFromIntToPageType(PageIndex);
	_logic.runInput(userInput, pageType);
	_display = _logic.getDisplay();
	logUI.saveLog();
}

//This method gets the main display from WWdisplay and return it as a vector of vector of string
std::vector<std::vector<std::string>> WWUI::display() {
	WWLogger& logUI = WWLogger::getInstance();
	logUI.addLog(LOG_DISPLAY);
	logUI.saveLog();
	_taskContent = _display.getMainDisplay();
	return _taskContent;
}

//This method gets the system response from WWdisplay and return it as a string
std::string WWUI::displaySystemResponse() {
	WWLogger& logUI = WWLogger::getInstance();
	logUI.addLog(LOG_DISPLAY_SYSTEM_RESPONSE);
	logUI.saveLog();
	_systemResponse = _display.getSystemResponse();
	return _systemResponse;
}

//This method gets a random floating task from WWdisplay and return it as a string
std::string WWUI::getFloatingTask() {
	WWLogger& logUI = WWLogger::getInstance();
	logUI.addLog(LOG_GET_FLOATING_TASK);
	logUI.saveLog();
	_currentFloatingTask = _display.getFloatingTask();
	return _currentFloatingTask;
}

//This method gets the appropriate PageIndex from WWdisplay to display the tasks
int WWUI::getPageIndex() {
	WWLogger& logUI = WWLogger::getInstance();
	logUI.addLog(LOG_GET_PAGE_INDEX);
	logUI.saveLog();
	_currentPageIndex = _display.getPageIndex();
	return _currentPageIndex;
}