#include "DisplayWindow.h"
#include <iomanip>

DisplayWindow::DisplayWindow(){}
DisplayWindow::~DisplayWindow(){}

void DisplayWindow::setContent(vector<Task>& tasklist){

   ostringstream oss;
   for (unsigned i = 0; i < tasklist.size(); i++){
	   oss << '[' << i + 1 << '.' << ']'
		   << '['<<tasklist[i].taskName<<']';
		   if (tasklist[i].type == "deadline" || "floating"){
			   oss << "[N/A]";
			   if (tasklist[i].type == "floating"){
				   oss << "[N/A]";
			   }
			   else{
				   oss << '['<<tasklist[i].endingTime<<']';
			   }
		   }
		   else if(tasklist[i].type == "timed"){ 
			   oss << '[' << tasklist[i].startingTime << ']'
			         << '[' << tasklist[i].endingTime<<']';
		   }
		  
		   oss << '[' << tasklist[i].status <<']'<< endl;
   }
        _content = oss.str();
}

string DisplayWindow::getContent(){
	   return _content;
}