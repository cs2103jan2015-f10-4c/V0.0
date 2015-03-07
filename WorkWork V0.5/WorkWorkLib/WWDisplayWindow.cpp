//@author A0099689W
#include <string>
#include <vector>
#include "WWTask.h"
#include "WWDisplayWindow.h"
#include "WWLogger.h"

using namespace std;

const string WWDisplayWindow::EMPTY_CONTENT             = "";
const string WWDisplayWindow::LABEL_NEWLINE             = "\n";
const string WWDisplayWindow::LABEL_FROM                = "From: ";
const string WWDisplayWindow::LABEL_TO                  = "To     : ";
const string WWDisplayWindow::LABEL_SEPARATE_DATETIME   = ", ";
const string WWDisplayWindow::LABEL_DUE                 = "Due  : ";
const string WWDisplayWindow::STATUS_TODAY              = "today";
const string WWDisplayWindow::STATUS_OVERDUE            = "overdue";
const string WWDisplayWindow::STATUS_DONE               = "complete";
const string WWDisplayWindow::STATUS_UNDONE             = "incomplete";
const string WWDisplayWindow::WRONG_TASK_TYPE_EXCEPTION = "Wrong Task Type!";
const string WWDisplayWindow::MAIN_WINDOW_DISPLAY_LOG   = "Main window display generated.";



WWDisplayWindow::WWDisplayWindow() {
}


// This function serves to set the details in the vector<vector<string>> 
// according to the attributes of the tasks stored in taskList
// Display contents of every task are stored in a vector of string
// in a sequence of name, date&time follow by display status;
void WWDisplayWindow::setContent(vector<WWTask> taskList) {
	_displayDetails.clear();
	
	vector<string> taskDetails;	
	
	for(unsigned int i = 0; i < taskList.size(); i++) {
		taskDetails.push_back(taskList[i].getTaskName());

		WWUtilities::TaskType tasktype = taskList[i].getTaskType();
		WWLogger& logger = WWLogger::getInstance();

		switch (tasktype) {
		    case WWUtilities::TaskType::FLOATING: {
				taskDetails.push_back(EMPTY_CONTENT);
				break;
			}
			case WWUtilities::TaskType::TIMED: {
				string formatedOutput;
				try{
					formatedOutput = getOutputForTimedtask(taskList[i].getStartDate(), taskList[i].getStartTime(), taskList[i].getEndDate(), taskList[i].getEndTime());
				} catch (string&) {
					formatedOutput = EMPTY_CONTENT;
				}
				taskDetails.push_back(formatedOutput);
				break;
			}
			case WWUtilities::TaskType::DEADLINE: {
				string formatedOutput;
				string deadlineDate = taskList[i].getStartDate();
				string deadlineTime = taskList[i].getStartTime();
				if(!deadlineTime.empty()) {
					_displayConverter.formatTimeForDisplay(deadlineTime);
					_displayConverter.formatDateForDisplay(deadlineDate);
					formatedOutput = LABEL_DUE + deadlineDate + LABEL_SEPARATE_DATETIME + deadlineTime;
				}
				else {
					_displayConverter.formatDateForDisplay(deadlineDate);
					formatedOutput = LABEL_DUE + deadlineDate;
				}
				taskDetails.push_back(formatedOutput);
				break;
			}
			
			default: {
				taskDetails.push_back(EMPTY_CONTENT);
			}

		}

		string displayStatus = getDisplayStatus(taskList[i]);

		taskDetails.push_back(displayStatus);
		
		_displayDetails.push_back(taskDetails);
		taskDetails.clear();
	}
	WWLogger displayWindowLogger = WWLogger::getInstance();
	displayWindowLogger.addLog(MAIN_WINDOW_DISPLAY_LOG);

}

// Accessor for private distribute _displayDetails
vector<vector<string>>& WWDisplayWindow::getContent() {
	return _displayDetails;
}

// This method combines date& time strings stored in WWTask object
// and return a single string that can be used for display
// It is the client' responsibility to ensure that the 
// date and time information come from a timed task
string WWDisplayWindow::getOutputForTimedtask(string startDate, string startTime, string endDate, string endTime){
	string beginMessage, endMessage;
	if(!startTime.empty()) {
		_displayConverter.formatTimeForDisplay(startTime);
		_displayConverter.formatDateForDisplay(startDate);
		beginMessage = LABEL_FROM + startDate + LABEL_SEPARATE_DATETIME + startTime;
	} else if(!startDate.empty()){
		_displayConverter.formatDateForDisplay(startDate);
		beginMessage = LABEL_FROM + startDate;
	} else {
		throw WRONG_TASK_TYPE_EXCEPTION;
	}

	if(!endTime.empty()) {
		_displayConverter.formatTimeForDisplay(endTime);
		_displayConverter.formatDateForDisplay(endDate);
		endMessage = LABEL_TO + endDate + LABEL_SEPARATE_DATETIME + endTime;
	} else {
		_displayConverter.formatDateForDisplay(endDate);

		endMessage = LABEL_TO + endDate;
	}
	
	return beginMessage + LABEL_NEWLINE + endMessage;
}



// This method determine the display status for color display in GUI
// The output is a string that represents the display status
string WWDisplayWindow::getDisplayStatus(WWTask task){
	string displayStatus;
	if(task.getStatus()) {
		displayStatus = STATUS_DONE;
	} else if(task.checkOverdue()) {
		displayStatus = STATUS_OVERDUE;
	} else if(task.checkToday()) {
		displayStatus = STATUS_TODAY;
	} else {
		displayStatus = STATUS_UNDONE;
	}
	return displayStatus;
}

