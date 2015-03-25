#include "DisplayWindow.h"

DisplayWindow::DisplayWindow(){}
DisplayWindow::~DisplayWindow(){}

void DisplayWindow::setContent(vector<Task> tasklist){
	_content = tasklist;
}

vector<Task> DisplayWindow::getContent(){

	return _content;
}