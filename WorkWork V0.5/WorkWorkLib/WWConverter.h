//@author A0099689W
#ifndef WWCONVERTER_H
#define WWCONVERTER_H

#include <sstream>
#include <string>

#include "WWCommand.h"
#include "WWUtilities.h"
#include "WWLogger.h"

// Do the mutual conversions among system time & date, 
// time & date stored in WWTask and the display time & date for GUI.
// Sample usage:
// WWConverter dateConverter;
// std::string dateString;
// dateConverter.convertIntDateToString(12, 05, 2014, dateString);
class WWConverter{
public:
	WWConverter();
	
	void convertIntTimeToString (int, int, std::string&);
	void convertIntDateToString (int, int, int, std::string&);
	void convertDateStringToInt (std::string, int&, int&, int&);
	void convertTimeStringToInt (std::string, int&, int&);
	void formatDateForDisplay   (std::string&);
	void formatTimeForDisplay   (std::string&);
	
private:
	std::string getFormatedTime    (int, int);
	std::string getFormatedDate    (int, int, int);
	bool        isSingleDigit      (int);
	int         convertStringToInt (std::string);

	static const int            STRING_STARTING_POSITION;
    static const int            SINGLE_DIGIT_LIMIT;          
	static const int			DIGIT_MIDNIGHT;
	static const int			DIGIT_NOON_HOUR;
	static const int			DIGIT_NOON_MINUTE;
	static const int			DIGIT_MIDNIGHT_TO_MERIDIEM;
	static const int            LENGTH_YEAR;
	static const int            LENGTH_MONTH;
	static const int            LENGTH_DAY;
	static const int            LENGTH_HOUR;
	static const int            LENGTH_MINUTE;
	static const std::string    LABEL_MORNING;
	static const std::string    LABEL_NOON;
    static const std::string    LABEL_AFTERNOON;
	static const std::string    LABEL_MIDNIGHT;
	static const std::string    LABEL_SINGLE_DIGIT_COMPLEMENT;
	static const std::string    LABEL_COLON;
	static const std::string    LABEL_SPACE;
	static const std::string    EMPTY_CONTENT;
	
};
#endif