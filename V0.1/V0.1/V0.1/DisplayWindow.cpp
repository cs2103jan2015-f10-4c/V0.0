// @author A0116363L
#include "DisplayWindow.h"
#include <iomanip>

const char DisplayWindow::OPEN_BRACKET='[';
const char DisplayWindow::CLOSE_BRACKET=']';
const char DisplayWindow::FULL_STOP='.';



DisplayWindow::DisplayWindow(){}
DisplayWindow::~DisplayWindow(){}

void DisplayWindow::setContent(vector<Task>& tasklist){

   ostringstream oss;
   for (unsigned i = 0; i < tasklist.size(); i++){
	   oss << OPEN_BRACKET << i + 1 << FULL_STOP << CLOSE_BRACKET
		   << OPEN_BRACKET<<tasklist[i].taskName<<CLOSE_BRACKET
		   << OPEN_BRACKET << tasklist[i].startingTime << CLOSE_BRACKET
		   << OPEN_BRACKET << tasklist[i].endingTime<<CLOSE_BRACKET
		   << OPEN_BRACKET << tasklist[i].status <<CLOSE_BRACKET<< endl;
   }
        _content = oss.str();
}

string DisplayWindow::getContent(){
	   return _content;
}