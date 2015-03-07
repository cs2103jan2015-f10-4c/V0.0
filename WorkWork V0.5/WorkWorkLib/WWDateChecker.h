//@author A0097547M

#ifndef WWDATECHECKER_H
#define WWDATECHECKER_H

#include <string>

//WWDateChecker is mainly used by WWDateParser to check if the dates that matched the regexs are valid
//WWDateChecker will account for leap years when checking
//When the year is not given, WWDateChecker will set the year as the current system year
//When the input date is already overdue, then WWDateChecker will adjust it to the nearest year that is not yet overdue
//WWDateChecker will then return the date in YYYYMMDD digit format through the reference string provided
//WWDateChecker will also return a bool to denote whether or not the check has passed

class WWDateChecker {
public:
	WWDateChecker();

	bool isValidDateWordFormat(std::string, std::string, std::string, std::string&);
	bool isValidDateWordFormatWithoutYear(std::string, std::string, std::string&);
	bool isValidDateDigitFormat(std::string, std::string, std::string, std::string&);
	bool isValidDateDigitFormatWithoutYear(std::string, std::string, std::string&);

private:
	int _year;
	int _month;
	int _day;

	bool isValidYear(std::string);
	bool isValidMonthWordFormat(std::string);
	bool isValidMonthDigitFormat(std::string);
	bool isValidDay(std::string);
	bool isLeapYear();
	bool isNextYear();

	bool isOverdueWithoutYear(std::string);
	void setNextYear(std::string&);
	int getCurrentDateInt();

	std::string composeProjectDate();
	int stringToInt(std::string);
};
#endif