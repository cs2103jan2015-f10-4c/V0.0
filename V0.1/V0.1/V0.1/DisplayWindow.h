
// @author A0116363L

#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <vector>
#include <string>
#include "Task.h"
#include <sstream>
class DisplayWindow{

private:

	string _content;
	static const char OPEN_BRACKET;
	static const char CLOSE_BRACKET;
	static const char FULL_STOP;

public:

	DisplayWindow();
	~DisplayWindow();

	void setContent(vector<Task>&);
	string getContent();
	

};

#endif