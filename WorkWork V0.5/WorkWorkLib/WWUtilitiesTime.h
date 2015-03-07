//@author A0097547M

#ifndef WWUTILITIESTIME_H
#define WWUTILITIESTIME_H

// This class assist WWUtilities to obtain the system date and time
// in integer format.
class WWUtilitiesTime {
public:
	WWUtilitiesTime();

	int getCurrentDay();
	int getCurrentMonth();
	int getCurrentYear();
	int getCurrentMinute();
	int getCurrentHour();

private:
	static const int SYSTEM_YEAR_ADJUSTMENT;
	static const int SYSTEM_MONTH_ADJUSTMENT;

	int _currentDay;
	int _currentMonth;
	int _currentYear;
	int _currentMinute;
	int _currentHour;

	void retrieveDetailsFromSystem();
};
#endif