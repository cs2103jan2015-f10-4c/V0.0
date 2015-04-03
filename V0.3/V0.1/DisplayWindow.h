


#ifndef DISPLAYWINDOW_H
#define DISPLAYWINDOW_H
#include <vector>
#include <string>
#include "Task.h"
#include <sstream>
class DisplayWindow{

private:

	 string _content;

public:

	DisplayWindow();
	~DisplayWindow();

	void setContent(vector<Task>&);
	string getContent();

};




#endif