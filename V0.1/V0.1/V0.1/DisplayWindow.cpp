#include "DisplayWindow.h"

DisplayWindow::DisplayWindow(){}
DisplayWindow::~DisplayWindow(){}

void DisplayWindow::setContent(vector<Task> tasklist){
   _content = tasklist;
   ostringstream oss;
   for (int i = 0; i < tasklist.size(); i++){
	   oss << i + 1 << '.'
		   << tasklist[i].taskName
		   << " from " << tasklist[i].startingTime
		   << " to " << tasklist[i].endingTime
		   << " " << tasklist[i].status << endl;
   }
   cout << oss.str();
}

vector<Task> DisplayWindow::getContent(){

	return _content;
}