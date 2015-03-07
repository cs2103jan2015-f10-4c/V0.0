//@author A0097547M

#ifndef WWUTILITIES_H
#define WWUTILITIES_H

#include <string>
#include "WWUtilitiesMonth.h"
#include "WWUtilitiesTime.h"


// This class provides common and often reused enum types and functions
// for other classes. Also, this class have functions to assist clients 
// to obtain system date and time and do the convertion between 
// month abbreviations string and integer month.
class WWUtilities {
public:
	enum CommandType {
		ADD, DELETE, DELETEALL, EDIT, DONE, UNDONE, SEARCH, UNDO, REDO,
		VIEWALL, VIEWDEADLINE, VIEWTIMED, VIEWFLOATING, VIEWTODAY, VIEWDONE, VIEWUNDONE, VIEWOVERDUE, VIEWSEARCH, 
		REFRESH, EXIT, INVALID
	};

	enum TaskType {
		DEADLINE, TIMED, FLOATING, TASKINVALID
	};

	enum PageType {
		PAGEALL, PAGEDEADLINE, PAGETIMED, PAGEFLOATING, PAGETODAY, PAGEDONE, PAGEUNDONE, PAGEOVERDUE, PAGESEARCH, PAGEINVALID
	};

	static WWUtilities& getInstance() {
		static WWUtilities instance;
		return instance;
	}

	int convertMonthFromStringToInt(std::string);
	std::string convertMonthFromIntToString(int);

	int getCurrentDay();
	int getCurrentMonth();
	int getCurrentYear();
	int getCurrentMinute();
	int getCurrentHour();

private:
	WWUtilitiesMonth _monthUtility;
	WWUtilitiesTime  _timeUtility;

	WWUtilities();

};
#endif