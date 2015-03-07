//@author A0101014L
// WWTaskTime.h

#ifndef WWTASKTIME_H
#define WWTASKTIME_H

//WWTaskTime is created by WWTask to determine if a task is overdue and if its start date is today

#include <string>

class WWTaskTime {
public:

	WWTaskTime();

	bool isOverdue(std::string, std::string);
	bool isToday(std::string);

private:

	bool _overdue;
	bool _today;
};
#endif
