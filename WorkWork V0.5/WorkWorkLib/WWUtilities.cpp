//@author A0097547M

#include "WWUtilities.h"
#include "WWUtilitiesMonth.h"
#include "WWUtilitiesTime.h"

using namespace std;

WWUtilities::WWUtilities() {
}

int WWUtilities::convertMonthFromStringToInt(string inputString) {
	return _monthUtility.convertMonthFromStringToInt(inputString);
}

string WWUtilities::convertMonthFromIntToString(int inputInt) {
	return _monthUtility.convertMonthFromIntToString(inputInt);
}

int WWUtilities::getCurrentDay() {
	return _timeUtility.getCurrentDay();
}

int WWUtilities::getCurrentMonth() {
	return _timeUtility.getCurrentMonth();
}

int WWUtilities::getCurrentYear() {
	return _timeUtility.getCurrentYear();
}

int WWUtilities::getCurrentMinute() {
	return _timeUtility.getCurrentMinute();
}

int WWUtilities::getCurrentHour() {
	return _timeUtility.getCurrentHour();
}