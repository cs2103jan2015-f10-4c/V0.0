//@author A0097547M-reused

#include "Logger.h"

const string LOG_FILENAME = "logFile.txt";

Logger::Logger() {
}

void Logger::addLog(string newLog) {
	_logContent.push_back(newLog);
}

//write log entries into the file named "logFile.txt"
void Logger::saveLog() {
	ofstream writeFile(LOG_FILENAME.c_str());

	for (unsigned int i = 0; i < _logContent.size(); i++) {
		writeFile << _logContent[i] << endl;
	}

	writeFile.close();
}