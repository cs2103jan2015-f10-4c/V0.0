//@author A0099689W
#include "WWConverter.h"

using namespace std;

const int    WWConverter::STRING_STARTING_POSITION      = 0;
const int    WWConverter::SINGLE_DIGIT_LIMIT            = 9;
const int	 WWConverter::DIGIT_MIDNIGHT				= 0;
const int	 WWConverter::DIGIT_NOON_HOUR			    = 12;
const int	 WWConverter::DIGIT_NOON_MINUTE				= 0;
const int    WWConverter::DIGIT_MIDNIGHT_TO_MERIDIEM    = 12;
const int    WWConverter::LENGTH_YEAR                   = 4;
const int    WWConverter::LENGTH_MONTH                  = 2;
const int    WWConverter::LENGTH_DAY                    = 2;
const int    WWConverter::LENGTH_HOUR                   = 2;
const int    WWConverter::LENGTH_MINUTE                 = 2;
const string WWConverter::LABEL_MORNING                 = "am";
const string WWConverter::LABEL_NOON                    = "nn";
const string WWConverter::LABEL_AFTERNOON               = "pm";
const string WWConverter::LABEL_MIDNIGHT                = "mn";
const string WWConverter::LABEL_SINGLE_DIGIT_COMPLEMENT = "0";
const string WWConverter::LABEL_COLON                   = ":";
const string WWConverter::LABEL_SPACE                   = " ";


WWConverter::WWConverter() {
}


// Change the format of the taskdate string stored in task 
// to the desired display format on the GUI.
// e.g. from "20131214" to "14 Dec 2013
// It is the client's responsibility to ensure the validity
// and format of the taskDate passed into the function.
void WWConverter::formatDateForDisplay(string& taskDate)
{
	string yearString, monthString, dayString;

	if(taskDate.empty()) {
		return;
	} else {
		yearString  = taskDate.substr(STRING_STARTING_POSITION , LENGTH_YEAR);
		monthString = taskDate.substr(LENGTH_YEAR, LENGTH_MONTH);
		dayString   = taskDate.substr(LENGTH_YEAR + LENGTH_MONTH, LENGTH_DAY);
	}

	int year  = convertStringToInt(yearString);
	int month = convertStringToInt(monthString);
	int day   = convertStringToInt(dayString);

	taskDate = getFormatedDate(day, month, year);
}
// Change the format of the tasktime string stored in task 
// to the desired display format on the GUI.
// e.g. from "1215" to "12:15pm"
// It is the client's responsibility to ensure the validity
// and format of the taskTime passed into the function.
void WWConverter::formatTimeForDisplay(string& taskTime)
{
	string hourString, minuteString;

	if(taskTime.empty()) {
		return;
	} else {
		hourString   = taskTime.substr(STRING_STARTING_POSITION, LENGTH_HOUR);
		minuteString = taskTime.substr(LENGTH_HOUR, LENGTH_MINUTE);
	}

	int hour   = convertStringToInt(hourString);
	int minute = convertStringToInt(minuteString);
	
	taskTime = getFormatedTime(hour, minute);
}


// Convert the integer hour and minute to string format
// Output format is "hhmm" which is a string of size 4.
// It is the client's responsibility to ensure the validity
// of the integer hour and minute passed into the function.
void WWConverter::convertIntTimeToString(int hour, int minute, string& timeString){
	ostringstream oss;

	if(!isSingleDigit(hour) && !isSingleDigit(minute)) {
		oss << hour << minute;
	} else if(isSingleDigit(hour) && !isSingleDigit(minute)) {
		oss << LABEL_SINGLE_DIGIT_COMPLEMENT << hour << minute;
	} else if(!isSingleDigit(hour) && isSingleDigit(minute)) {
		oss << hour << LABEL_SINGLE_DIGIT_COMPLEMENT << minute;
	} else {
		oss << LABEL_SINGLE_DIGIT_COMPLEMENT << hour << LABEL_SINGLE_DIGIT_COMPLEMENT << minute;
	}

	timeString = oss.str();
}

// Convert the integer year, month and day to a string
// Output format is "yyyymmdd" which is a string of size 8
// It is the client's responsibility to ensure the validity
// of the integer day, month and year passed into the function.
void WWConverter::convertIntDateToString(int day, int month, int year, std::string& dateString){

	ostringstream oss;

	if(!isSingleDigit(month) && !isSingleDigit(day)) {
		oss << year << month << day; 
	} else if(isSingleDigit(month) && !isSingleDigit(day)) {
		oss << year << LABEL_SINGLE_DIGIT_COMPLEMENT<< month << day;
	} else if(!isSingleDigit(month) && isSingleDigit(day)) {
		oss << year << month << LABEL_SINGLE_DIGIT_COMPLEMENT << day;
	} else {
		oss << year << LABEL_SINGLE_DIGIT_COMPLEMENT << month << LABEL_SINGLE_DIGIT_COMPLEMENT << day;
	}

	dateString = oss.str();
}


// Extract year, month& day from dateString in the format of "yyyymmdd"
// The clients are responsible for ensuring the validity and format of
// the dateString passed to the function.
void WWConverter::convertDateStringToInt(std::string dateString, int& day, int& month, int& year){
	if(!dateString.empty()) {
		string yearString  = dateString.substr(STRING_STARTING_POSITION, LENGTH_YEAR);
		string monthString = dateString.substr(LENGTH_YEAR, LENGTH_MONTH);
		string dayString   = dateString.substr(LENGTH_YEAR + LENGTH_MONTH, LENGTH_DAY);
		
		year  = convertStringToInt(yearString);
		month = convertStringToInt(monthString);
		day   = convertStringToInt(dayString);
	
	} else {
		return;
	}
}

// Extract integer hour& minute from timeString in the format of "hhmm"
// The clients are responsible for ensuring the validity and format of
// the timeString passed to the function.
void WWConverter::convertTimeStringToInt(std::string timeString, int& hour, int& minute) {
	if(!timeString.empty()) {
		string hourString   = timeString.substr(STRING_STARTING_POSITION, LENGTH_HOUR);
		string minuteString = timeString.substr(LENGTH_HOUR, LENGTH_MINUTE);
		hour   = convertStringToInt(hourString);
		minute = convertStringToInt(minuteString);
	} else {
		return;
	}
}
	
// This method transform integer hour and minute to
// a time string for display.
string WWConverter::getFormatedTime(int hour, int minute) {
	ostringstream oss;
	string        period;

	if(hour < DIGIT_NOON_HOUR) {
		period = LABEL_MORNING;
	}

	if(hour > DIGIT_NOON_HOUR) {
		period = LABEL_AFTERNOON;
	}

	if((hour == DIGIT_NOON_HOUR) && (minute != DIGIT_NOON_MINUTE)) {
		period = LABEL_AFTERNOON;
	}

	if((hour == DIGIT_NOON_HOUR) && (minute == DIGIT_NOON_MINUTE)) {
		period = LABEL_NOON;
	}

	if((hour == DIGIT_MIDNIGHT) && (minute == DIGIT_MIDNIGHT)) {
		period = LABEL_MIDNIGHT;
	}

	if(hour == DIGIT_MIDNIGHT) {
		hour = hour + DIGIT_MIDNIGHT_TO_MERIDIEM;
	}

	if(hour > DIGIT_NOON_HOUR) {
		hour = hour - DIGIT_NOON_HOUR;
	}

	if (hour > SINGLE_DIGIT_LIMIT && minute > SINGLE_DIGIT_LIMIT) {
		oss << hour << LABEL_COLON << minute << period;
	} 
	
	if (hour > SINGLE_DIGIT_LIMIT && minute <= SINGLE_DIGIT_LIMIT) {
		oss << hour << LABEL_COLON << LABEL_SINGLE_DIGIT_COMPLEMENT << minute << period;
	} 
	
	if (hour <= SINGLE_DIGIT_LIMIT && minute > SINGLE_DIGIT_LIMIT) {
		oss << LABEL_SINGLE_DIGIT_COMPLEMENT << hour << LABEL_COLON << minute << period;
	} 
	
	if (hour <= SINGLE_DIGIT_LIMIT && minute <= SINGLE_DIGIT_LIMIT) {
		oss << LABEL_SINGLE_DIGIT_COMPLEMENT << hour << LABEL_COLON << LABEL_SINGLE_DIGIT_COMPLEMENT << minute << period;
	}

	return oss.str();
}

// This method transform integer day, month, and year to
// a date string for display.
string WWConverter::getFormatedDate(int day, int month, int year){
	WWUtilities& monthUtility = WWUtilities::getInstance();

	string monthString = monthUtility.convertMonthFromIntToString(month);

	ostringstream oss;

	if (day > SINGLE_DIGIT_LIMIT) {
		oss << day <<LABEL_SPACE<< monthString <<LABEL_SPACE<< year;
	} else {
		oss << LABEL_SINGLE_DIGIT_COMPLEMENT << day <<LABEL_SPACE<< monthString << LABEL_SPACE << year;
	}
	return oss.str();
}

bool WWConverter::isSingleDigit(int number)
{
	bool isSingleDigit = true;
	if(number > SINGLE_DIGIT_LIMIT) {
		isSingleDigit = false;
	}
	return isSingleDigit;
}

int WWConverter::convertStringToInt(std::string convertString) {
	return atoi(convertString.c_str());
}
