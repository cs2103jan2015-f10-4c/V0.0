


#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <vector>
#include <string>
#include "Task.h"
#include <sstream>
class DisplayWindow{

private:

	vector<Task> _content;

public:

	DisplayWindow();
	~DisplayWindow();

	void setContent(vector<Task>);
	vector<Task> getContent();

};




#endif