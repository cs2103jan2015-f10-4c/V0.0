//@author A0097547M

#include <ctime>
#include <string>
#include <sstream>
#include <vector>
#include <cassert>
#include "WWDateTimeProcessor.h"
#include "WWUtilities.h"
#include "WWLogger.h";

using namespace std;

//The number of dates/time required for the different types of tasks
const int SIZE_REQUIRED_FOR_TIMED_TASK = 2;
const int SIZE_REQUIRED_FOR_DEADLINE_TASK = 1;
const int SIZE_REQUIRED_FOR_FLOATING_TASK = 0;

const int FIRST_DATE_TIME_INDEX = 0;
const int SECOND_DATE_TIME_INDEX = 1;

//the format for dates is YYYYMMDD, thus the size for MM is 2
const unsigned int STANDARD_MONTH_SIZE = 2;
const string STANDARD_MONTH_SIZE_ADJUSTMENT = "0";

//the format for dates is YYYYMMDD, thus the size for DD is 2
const unsigned int STANDARD_DAY_SIZE = 2;
const string STANDARD_DAY_SIZE_ADJUSTMENT = "0";

//the format for time is HHMM, thus the size for MM is 2
const unsigned int STANDARD_MINUTE_SIZE = 2;
const string STANDARD_MINUTE_SIZE_ADJUSTMENT = "0";

const int SYSTEM_MONTH_ADJUSTMENT = 1;
const int SYSTEM_YEAR_ADJUSTMENT = 1900;

const int SIZE_REQUIRED_TO_SORT = 2;

const string LOG_PROCESSTIMED = "date and time processed for timed task";
const string LOG_PROCESSDEADLINE = "date and time processed for deadline task";
const string LOG_PROCESSFLOATING = "date and time processed for floating task";

WWDateTimeProcessor::WWDateTimeProcessor() {
}

//processDateTime will determine the type of tasks based on the number of the dates and time parsed.
void WWDateTimeProcessor::processDateTime(vector<string>& dateStorage, vector<string>& timeStorage) {
	WWLogger& logger = WWLogger::getInstance();

	if((dateStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK)) {
		processTimed(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSTIMED);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK)) {
		processTimed(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSTIMED);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK)) {
		processTimed(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSTIMED);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK)) {
		processTimed(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSTIMED);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK)) {
		processDeadline(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSDEADLINE);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK)) {
		processDeadline(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSDEADLINE);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK)) {
		processTimed(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSTIMED);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK)) {
		processDeadline(dateStorage, timeStorage);
		logger.addLog(LOG_PROCESSDEADLINE);
		logger.saveLog();
	}

	if((dateStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) && (timeStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK)) {
		logger.addLog(LOG_PROCESSFLOATING);
		logger.saveLog();
	}
}

void WWDateTimeProcessor::processTimed(vector<string>& dateStorage, vector<string>& timeStorage) {
	if(dateStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) {
		if(timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) {
			rearrangeDateTime(dateStorage, timeStorage);
		}

		if(timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) {
			rearrangeDate(dateStorage);
		}

		if(timeStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) {
			rearrangeDate(dateStorage);
		}
	}

	if(dateStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) {
		if(timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) {
			rearrangeTime(timeStorage);

			string sameDate = dateStorage[FIRST_DATE_TIME_INDEX];
			dateStorage.push_back(sameDate);
		}
	}

	if(dateStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) {
		if(timeStorage.size() == SIZE_REQUIRED_FOR_TIMED_TASK) {
			rearrangeTime(timeStorage);

			string currentTime = getCurrentTimeString();

			if(stringToInt(timeStorage[FIRST_DATE_TIME_INDEX]) < stringToInt(currentTime)) {
				dateStorage.push_back(getNextDayDateString());
				dateStorage.push_back(getNextDayDateString());
			} else {
				dateStorage.push_back(getCurrentDateString());
				dateStorage.push_back(getCurrentDateString());
			}
		}
	}
}

void WWDateTimeProcessor::processDeadline(vector<string>& dateStorage, vector<string>& timeStorage) {
	if(dateStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) {
		if(timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) {
		}

		if(timeStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) {
		}
	}

	if(dateStorage.size() == SIZE_REQUIRED_FOR_FLOATING_TASK) {
		if(timeStorage.size() == SIZE_REQUIRED_FOR_DEADLINE_TASK) {
			string currentTime = getCurrentTimeString();

			if(stringToInt(timeStorage[FIRST_DATE_TIME_INDEX]) < stringToInt(currentTime)) {
				dateStorage.push_back(getNextDayDateString());
			} else {
				dateStorage.push_back(getCurrentDateString());
			}
		}
	}
}

void WWDateTimeProcessor::rearrangeDateTime(vector<string>& dateStorage, vector<string>& timeStorage) {
	assert(dateStorage.size() == SIZE_REQUIRED_TO_SORT);
	assert(timeStorage.size() == SIZE_REQUIRED_TO_SORT);

	int firstDate = stringToInt(dateStorage[FIRST_DATE_TIME_INDEX]);
	int secondDate = stringToInt(dateStorage[SECOND_DATE_TIME_INDEX]);

	if(firstDate > secondDate) {
		string temp;
		
		temp = dateStorage[FIRST_DATE_TIME_INDEX];
		dateStorage[FIRST_DATE_TIME_INDEX] = dateStorage[SECOND_DATE_TIME_INDEX];
		dateStorage[SECOND_DATE_TIME_INDEX] = temp;

		temp = timeStorage[FIRST_DATE_TIME_INDEX];
		timeStorage[FIRST_DATE_TIME_INDEX] = timeStorage[SECOND_DATE_TIME_INDEX];
		timeStorage[SECOND_DATE_TIME_INDEX] = temp;
	} 

	if(firstDate == secondDate) {
		rearrangeTime(timeStorage);
	}
}

void WWDateTimeProcessor::rearrangeDate(vector<string>& dateStorage) {
	assert(dateStorage.size() == SIZE_REQUIRED_TO_SORT);

	int firstDate = stringToInt(dateStorage[FIRST_DATE_TIME_INDEX]);
	int secondDate = stringToInt(dateStorage[SECOND_DATE_TIME_INDEX]);

	if(firstDate > secondDate) {
		string temp;

		temp = dateStorage[FIRST_DATE_TIME_INDEX];
		dateStorage[FIRST_DATE_TIME_INDEX] = dateStorage[SECOND_DATE_TIME_INDEX];
		dateStorage[SECOND_DATE_TIME_INDEX] = temp;
	}
}

void WWDateTimeProcessor::rearrangeTime(vector<string>& timeStorage) {
	assert(timeStorage.size() == SIZE_REQUIRED_TO_SORT);

	int firstTime = stringToInt(timeStorage[FIRST_DATE_TIME_INDEX]);
	int secondTime = stringToInt(timeStorage[SECOND_DATE_TIME_INDEX]);

	if(firstTime > secondTime) {
		string temp;

		temp = timeStorage[FIRST_DATE_TIME_INDEX];
		timeStorage[FIRST_DATE_TIME_INDEX] = timeStorage[SECOND_DATE_TIME_INDEX];
		timeStorage[SECOND_DATE_TIME_INDEX] = temp;
	}
}

string WWDateTimeProcessor::getCurrentDateString() {
	WWUtilities& utilities = WWUtilities::getInstance();

	string yearString = to_string(utilities.getCurrentYear());
	string monthString = to_string(utilities.getCurrentMonth());
	string dayString = to_string(utilities.getCurrentDay());

	if(monthString.size() != STANDARD_MONTH_SIZE) {
			monthString = STANDARD_MONTH_SIZE_ADJUSTMENT + monthString;
		}

	if(dayString.size() != STANDARD_DAY_SIZE) {
		dayString = STANDARD_DAY_SIZE_ADJUSTMENT + dayString;
	}

	return yearString + monthString + dayString;
}

string WWDateTimeProcessor::getNextDayDateString() {
	time_t rawTime = time(NULL);
	time_t result;
	struct tm timeInfo;
	localtime_s(&timeInfo, &rawTime);

	timeInfo.tm_mday += 1;

	result = mktime(&timeInfo);

	localtime_s(&timeInfo, &result);
	int resultYear = timeInfo.tm_year + SYSTEM_YEAR_ADJUSTMENT;
	int resultMonth = timeInfo.tm_mon + SYSTEM_MONTH_ADJUSTMENT;
	int resultDay = timeInfo.tm_mday;

	string yearString = to_string(resultYear);
	string monthString = to_string(resultMonth);
	string dayString = to_string(resultDay);

	if(monthString.size() != STANDARD_MONTH_SIZE) {
			monthString = STANDARD_MONTH_SIZE_ADJUSTMENT + monthString;
	}

	if(dayString.size() != STANDARD_DAY_SIZE) {
			dayString = STANDARD_DAY_SIZE_ADJUSTMENT + dayString;
	}

	return yearString + monthString + dayString;
}

string WWDateTimeProcessor::getCurrentTimeString() {
	WWUtilities& utilities = WWUtilities::getInstance();

	string hourString = to_string(utilities.getCurrentHour());
	string minuteString = to_string(utilities.getCurrentMinute());

	if(minuteString.size() != STANDARD_MINUTE_SIZE) {
		minuteString = STANDARD_MINUTE_SIZE_ADJUSTMENT + minuteString;
	}

	return hourString + minuteString;
}

int WWDateTimeProcessor::stringToInt(string inputString) {
	return atoi(inputString.c_str());
}