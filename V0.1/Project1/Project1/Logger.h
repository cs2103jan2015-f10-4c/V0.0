#pragma once


#include <string>
#include <vector>

class Logger{

private:
	std::vector<std::string> _logContent;



public:
	static Logger& getInstance() {
		static Logger instance;
		return instance;
	}

	void addLog(std::string);
	void saveLog();
    Logger();
	~Logger();


	




};

