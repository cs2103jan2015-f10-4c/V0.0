//@author A0097547M
#ifndef WWLOGGER_H
#define WWLOGGER_H

#include <string>
#include <vector>

class WWLogger {
public:
	static WWLogger& getInstance() {
		static WWLogger instance;
		return instance;
	}

	void addLog(std::string);
	void saveLog();


private:
	std::vector<std::string> _logContent;

	WWLogger();
};
#endif