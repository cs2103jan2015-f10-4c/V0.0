//@author A0097547M

#ifndef WWDATETIMEPROCESSOR_H
#define WWDATETIMEPROCESSOR_H

#include <string>
#include <vector>

//WWDateTimeProcessor will process and interpret the date and time stored after parsing
//The number of dates and time received should be at most 2
//WWDateTimeProcessor will attach each time to the corresponding dates.
//If there are more time than dates, then the other date will be cloned.
//If there are time and no dates, then the current system date will be taken.
//WWDateTimeProcessor will then sort the dates with the earlier date appearing before.
//If the dates are the same, then the time will be sorted.
//WWDateTimeProcessor will also automatically adjust the date to the next day if the date is found to be overdue

class WWDateTimeProcessor {
public:
	WWDateTimeProcessor();

	void processDateTime(std::vector<std::string>&, std::vector<std::string>&);

private:
	void processTimed(std::vector<std::string>&, std::vector<std::string>&);
	void processDeadline(std::vector<std::string>&, std::vector<std::string>&);

	void rearrangeDateTime(std::vector<std::string>&, std::vector<std::string>&);
	void rearrangeDate(std::vector<std::string>&);
	void rearrangeTime(std::vector<std::string>&);

	std::string getCurrentDateString();
	std::string getNextDayDateString();
	std::string getCurrentTimeString();

	int stringToInt(std::string);
};
#endif