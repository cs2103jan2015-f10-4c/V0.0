//@author A0116363L
#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "TransformTime.h"
using namespace std;


//Logger class is defined to keep track of the internal process of the running program.
//When ever an important action is made in the program, 
//a sentence will be stored in the logger file.
//This file can help us to check the progress of the program.
//Whenever a failure is incurred, user or developer can always refer to it for the elapsed point.

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
