//@author A0101014L
// WWFileStorage.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cassert>
#include "WWTask.h"
#include "WWFileStorage.h"
#include "WWConverter.h"

using namespace std;

const string FILENAME = "WorkWork.txt";

const char PARAMETER_SEPARATOR = ';';

const string EMPTY_PARAMETER = "";

const string DONE_INDICATOR = "true";
const string UNDONE_INDICATOR = "false";

const int TASKNAME_INDEX  = 0;
const int STARTDATE_INDEX = 1;
const int STARTTIME_INDEX = 2;
const int ENDDATE_INDEX   = 3;
const int ENDTIME_INDEX   = 4;
const int STATUS_INDEX    = 5;

const int TOKEN_NUMBER = 6;
const int DATE_LENGTH  = 8;
const int TIME_LENGTH  = 4;

const int TMSTRUCT_PARAMETER      = 0;
const int SYSTEM_MONTH_ADJUSTMENT = 1;
const int SYSTEM_YEAR_ADJUSTMENT  = 1900;

WWFileStorage::WWFileStorage() {
	_isCorruptedFile  = false;
	_isCorruptedToken = false;
}

//read strings of task content from the text file
//break them down to components used to construct a WWTask object
//a corrupted string wont be used to construct a WWTask object
bool WWFileStorage::openFile(vector<WWTask>& fileContent) {
	ifstream readFile(FILENAME.c_str());
	string lineContent;

	while(getline(readFile, lineContent)) {
		vector<string> tokenStorage;
		WWTask newTask;

		tokenizeContent(lineContent, tokenStorage);  //break down a string of task content to tokens

		if(!_isCorruptedToken){
			newTask = createTaskWithTokens(tokenStorage);
			fileContent.push_back(newTask);
		}

		_isCorruptedToken = false;  //each time after checking if a token is corrupted, set _isCorruptedToken to false;
	}

	readFile.close();

	return !_isCorruptedFile;
}

//save the content stored in a WWTask into the text file in the form of a string
void WWFileStorage::saveFile(vector<WWTask>& fileContent) {
	ofstream writeFile(FILENAME.c_str());

	for(unsigned int i = 0; i < fileContent.size(); i++) {
		string lineContent = taskToString(fileContent[i]);
		writeFile << lineContent << endl;
	}

	writeFile.close();
}

//we recognize ";" as the separator of different attributes of a WWTask object
//string will be split into tokens representing WWTask attributes
//tokens are then stored in a vector and to be verified if corrupted, in case the text file is modified
//once tokens are corrupted, the text file is also corrupted
//if token not corrupted, it will be then adjusted according to the correct date and time format, i.e. 20140231 is adjusted to 20140303, 0964 is adjusted to 1004
void WWFileStorage::tokenizeContent(string content, vector<string>& tokenStorage) {
	istringstream iss(content);
	string token;

	while(getline(iss, token, PARAMETER_SEPARATOR)) {
		tokenStorage.push_back(token);
	}

	verifyTokenContent(tokenStorage);

	if(!_isCorruptedToken) {
		adjustTokenContent(tokenStorage);
	} else {
		_isCorruptedFile = true;
	}
}

//token content will be verified if corrupted due to modification of the text file
void WWFileStorage::verifyTokenContent(const vector<string>& tokenStorage) {

	//by right there should be 6 tokens in tokenStorage, including task name, start date, start time, end date, end time and status
	//if the number of tokens in tokenStorage is not 6, token is corrupted
	if(tokenStorage.size() != TOKEN_NUMBER)
		_isCorruptedToken = true;

	//if the number os tokens is correct, length and format of tokens are checked
	if(!_isCorruptedToken) {

		if(!tokenStorage[STARTDATE_INDEX].empty()) {
			if(tokenStorage[STARTDATE_INDEX].size() != DATE_LENGTH) {  //non-empty token of start date must have 8 digit, otherwise corrupted
				_isCorruptedToken = true;
			} else {
				if(!isNumber(tokenStorage[STARTDATE_INDEX])) {  //if this token is 8-digit long but it is not a string of integer, then corrupted
					_isCorruptedToken = true;
				}
			}
		}

		if(!tokenStorage[STARTTIME_INDEX].empty()) {
			if(tokenStorage[STARTDATE_INDEX].empty()) {  //non-empty token of start time only exists when there is non-empty token of start time, otherwise corrupted
				_isCorruptedToken = true;
			} else {
				if(tokenStorage[STARTTIME_INDEX].size() != TIME_LENGTH) {  //this token must have 4 digits, otherwise corrupted
					_isCorruptedToken = true;
				} else {
					if(!isNumber(tokenStorage[STARTTIME_INDEX])) {  //if this token is 8-digit long but it is a string of integer, then corrupted
						_isCorruptedToken = true;
					}
				}
			}
		}

		//similar to checking tokenStorage[STARTDATE_INDEX]
		if(!tokenStorage[ENDDATE_INDEX].empty()) {
			if(tokenStorage[ENDDATE_INDEX].size() != DATE_LENGTH) {
				_isCorruptedToken = true;
			} else {
				if(!isNumber(tokenStorage[ENDDATE_INDEX])) {
					_isCorruptedToken = true;
				}
			}
		}

		//similar to checking tokenStorage[STARTTIME_INDEX]
		if(!tokenStorage[ENDTIME_INDEX].empty()) {
			if(tokenStorage[ENDDATE_INDEX].empty()) {
				_isCorruptedToken = true;
			} else {
				if(tokenStorage[ENDTIME_INDEX].size() != TIME_LENGTH) {
					_isCorruptedToken = true;
				} else {
					if(!isNumber(tokenStorage[ENDTIME_INDEX])) {
						_isCorruptedToken = true;
					}
				}
			}
		}
	}
}

//if token not corrupted, adjust its format
//this is helpful when the user wants to modify the task detail directly in the text file withou running the program
//i.e. a task ends on 28 Feb, and the user wants to extend by 3 days but forgets noly 28 or 29 days in Feb, then this method will help adjust it to 3 Mar or 2 Mar according to that specific year
void WWFileStorage::adjustTokenContent(vector<string>& tokenStorage) {
	string startDate = tokenStorage[STARTDATE_INDEX];
	string startTime = tokenStorage[STARTTIME_INDEX];
	string endDate   = tokenStorage[ENDDATE_INDEX];
	string endTime   = tokenStorage[ENDTIME_INDEX];

	if(!startDate.empty()) {
		adjustDateTime(startDate, startTime);  //adjust format of date and time strings if date string is not empty
	}
	if(!endDate.empty()) {
		adjustDateTime(endDate, endTime);  //adjust format of date and time strings if date string is not empty
	}

	tokenStorage[STARTDATE_INDEX] = startDate;
	tokenStorage[STARTTIME_INDEX] = startTime;
	tokenStorage[ENDDATE_INDEX]   = endDate;
	tokenStorage[ENDTIME_INDEX]   = endTime;

	// If the status is neither "DONE" nor "UNDONE", this method will automatically
	// set it as "UNDONE".
	if(tokenStorage[STATUS_INDEX] != DONE_INDICATOR && tokenStorage[STATUS_INDEX] != UNDONE_INDICATOR) {
		tokenStorage[STATUS_INDEX] = UNDONE_INDICATOR;
	}
}

//adjust date and time string to correct format
//i.e. 20140231 is adjusted to 20140303, 0964 is adjusted to 1004
//strings already have correct format will not be adjusted
//i.e 20140415, 0819 will not be adjusted
void WWFileStorage::adjustDateTime(string &contentDate, string &contentTime) {
	int min = 0, hr = 0, day = 0, mon = 0, year = 0;
	WWConverter converter;
	struct tm tmStruct;
	time_t timeInfo;

	string date = contentDate;
	converter.convertDateStringToInt(date, day, mon, year);

	assert(!date.empty());  //date must not be empty

	//retrieving parameters needed to construct a tm object
	tmStruct.tm_mday  = day;
	tmStruct.tm_mon   = mon - SYSTEM_MONTH_ADJUSTMENT;  //range for tm_mon is 0-11
	tmStruct.tm_year  = year - SYSTEM_YEAR_ADJUSTMENT;  //range for tm_year is from 1900
	
	string time = contentTime;
	if(!time.empty()) {
		converter.convertTimeStringToInt(time, hr, min);
	}

	//if time string is not empty, then tm_min and tm_hour are retrieved from that
	//otherwise they are still zero
	tmStruct.tm_min   = min;
	tmStruct.tm_hour  = hr;
	
	//parameters needed to construct a tm object, but not used by our program are set to zero
	tmStruct.tm_isdst = TMSTRUCT_PARAMETER;
	tmStruct.tm_sec   = TMSTRUCT_PARAMETER;
	tmStruct.tm_wday  = TMSTRUCT_PARAMETER;
	tmStruct.tm_yday  = TMSTRUCT_PARAMETER;

	//adjust the tm object to correct format
	timeInfo = mktime(&tmStruct);
	localtime_s(&tmStruct, &timeInfo);

	//get back parameters needed by our program
	int resultYear = tmStruct.tm_year + SYSTEM_YEAR_ADJUSTMENT;
	int resultMon  = tmStruct.tm_mon + SYSTEM_MONTH_ADJUSTMENT;
    int resultDay  = tmStruct.tm_mday;
	int resultHr   = tmStruct.tm_hour;
    int resultMin  = tmStruct.tm_min;

	string resultDate, resultTime;
	 
	converter.convertIntDateToString(resultDay, resultMon, resultYear, resultDate);
	converter.convertIntTimeToString(resultHr, resultMin, resultTime);

	contentDate = resultDate;
	if(!time.empty()) {  //if time string is empty, it will not be modified throughout this method
		contentTime = resultTime;
	}
}

//check whether a string purely consists of integers
bool WWFileStorage::isNumber(const string& s) {
    string::const_iterator it = s.begin();

    while (it != s.end() && isdigit(*it)) {
		++it;
	}

    return !s.empty() && it == s.end();
}

//encapsulate details of a WWTask object with corresponding tokens in tokenStorage
WWTask WWFileStorage::createTaskWithTokens(vector<string>& tokenStorage) {
	WWTask newTask;

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		newTask.setTaskName(tokenStorage[TASKNAME_INDEX]);
	}

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		newTask.setStartDate(tokenStorage[STARTDATE_INDEX]);
	}

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		newTask.setStartTime(tokenStorage[STARTTIME_INDEX]);
	}

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		newTask.setEndDate(tokenStorage[ENDDATE_INDEX]);
	}

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		newTask.setEndTime(tokenStorage[ENDTIME_INDEX]);
	}

	if(tokenStorage[TASKNAME_INDEX] != EMPTY_PARAMETER) {
		bool taskStatus = stringToBool(tokenStorage[STATUS_INDEX]);
		newTask.setStatus(taskStatus);
	}

	return newTask;
}

//convert the string of "true" or "false" to a bool _isDone of a WWTask object
bool WWFileStorage::stringToBool(string inputString) {
	bool isDoneStatus = false;

	if(inputString == DONE_INDICATOR) {
		isDoneStatus = true;
	}

	return isDoneStatus;
}

//convert a bool _isDone to a string of "true" or "false"
string WWFileStorage::boolToString(bool isDone) {
	string statusString;

	if(isDone) {
		statusString = DONE_INDICATOR;
	} else {
		statusString = UNDONE_INDICATOR;
	}

	return statusString;
}

//convert a WWTask object to a string by separating each attribute by a ";"
//then this string will be written in the text file
string WWFileStorage::taskToString(WWTask inputTask) {
	string statusString = boolToString(inputTask.getStatus());

	ostringstream oss;

	oss << inputTask.getTaskName() << PARAMETER_SEPARATOR
		<< inputTask.getStartDate() << PARAMETER_SEPARATOR  
		<< inputTask.getStartTime() << PARAMETER_SEPARATOR		
		<< inputTask.getEndDate() << PARAMETER_SEPARATOR		
		<< inputTask.getEndTime() << PARAMETER_SEPARATOR
		<< statusString << PARAMETER_SEPARATOR;

	return oss.str();
}