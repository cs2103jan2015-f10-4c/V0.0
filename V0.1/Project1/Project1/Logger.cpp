#include "Logger.h"
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

const std::string LOG_FILENAME = "logFile.txt";


void Logger::addLog(string newLog) {
	_logContent.push_back(newLog);
}

void Logger::saveLog() {

	ofstream writeFile(LOG_FILENAME.c_str());

	for (unsigned int i = 0; i < _logContent.size(); i++) {
		writeFile << _logContent[i] << endl;
	}

	writeFile.close();
}

Logger::Logger()
{
}


Logger::~Logger()
{
}



