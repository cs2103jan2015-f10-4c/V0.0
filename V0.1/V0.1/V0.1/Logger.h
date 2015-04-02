
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class Logger{
public:
	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}

	void addLog(string);
	void saveLog();


private:
    vector<string> _logContent;

	Logger();
};

#endif
