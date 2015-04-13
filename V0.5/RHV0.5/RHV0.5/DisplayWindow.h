
//@author A0116363L

#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <vector>
#include <string>
#include <sstream>
#include "Task.h"


//This class to format the tasklist and prepare it ready for display in GUI
//When the content is required, the formatted string of the tasks will be returned

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