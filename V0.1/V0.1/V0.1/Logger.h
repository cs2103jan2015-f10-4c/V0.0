//@author A0097547M-reused
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class RHLogger{


private:
    vector<string> _logContent;

public:
	//This method is to return the current status 
	//of the logger object and allows modification in any otehr class
	static RHLogger& getInstance() {
		static RHLogger instance;
		return instance;
	}

	void addLog(string);
	void saveLog();
    RHLogger();

	vector<string> getLogContent();

	
};

#endif
