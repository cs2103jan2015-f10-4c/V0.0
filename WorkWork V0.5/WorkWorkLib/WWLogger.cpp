//@author A0097547M

#include <iostream>
#include <string>
#include <fstream>
#include "WWLogger.h"

using namespace std;

const std::string LOG_FILENAME = "logFile.txt";

WWLogger::WWLogger() {
}

void WWLogger::addLog(string newLog) {
	_logContent.push_back(newLog);
}

void WWLogger::saveLog() {
	ofstream writeFile(LOG_FILENAME.c_str());

	for(unsigned int i = 0; i < _logContent.size(); i++) {
		writeFile << _logContent[i] << endl;		
	}

	writeFile.close();
}