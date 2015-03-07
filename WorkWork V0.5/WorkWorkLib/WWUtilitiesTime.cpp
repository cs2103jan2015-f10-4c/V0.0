//@author A0097547M

#include <ctime>
#include "WWUtilitiesTime.h"

using namespace std;

const int WWUtilitiesTime::SYSTEM_MONTH_ADJUSTMENT = 1;
const int WWUtilitiesTime::SYSTEM_YEAR_ADJUSTMENT = 1900;

WWUtilitiesTime::WWUtilitiesTime() {
}

int WWUtilitiesTime::getCurrentDay() {
	retrieveDetailsFromSystem();
	return _currentDay;
}

int WWUtilitiesTime::getCurrentMonth() {
	retrieveDetailsFromSystem();
	return _currentMonth;
}

int WWUtilitiesTime::getCurrentYear() {
	retrieveDetailsFromSystem();
	return _currentYear;
}

int WWUtilitiesTime::getCurrentMinute() {
	retrieveDetailsFromSystem();
	return _currentMinute;
}

int WWUtilitiesTime::getCurrentHour() {
	retrieveDetailsFromSystem();
	return _currentHour;
}


// retrieve system time and adjust the private attributes accordingly
void WWUtilitiesTime::retrieveDetailsFromSystem() {
	time_t rawTime = time(NULL);
	struct tm timeInformation;
	localtime_s(&timeInformation, &rawTime);

	_currentDay = timeInformation.tm_mday;
	_currentMonth = timeInformation.tm_mon + SYSTEM_MONTH_ADJUSTMENT;
	_currentYear = timeInformation.tm_year + SYSTEM_YEAR_ADJUSTMENT;
	_currentMinute = timeInformation.tm_min;
	_currentHour = timeInformation.tm_hour;
}