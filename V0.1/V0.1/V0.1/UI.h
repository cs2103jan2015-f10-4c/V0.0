

#ifndef UI_H
#define UI_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Parser.h"

using namespace std;

class UI{

private:
	Parser Parser;
	static const string WELCOME_MESSAGE;
	static const string SUCCESS_MESSAGE;
	static const string ERROR_MESAAGE;
	static const string USER_PROMPT_COMMAND;
	

	void displayUserMessage();

public:

	

	UI();
	~UI();
	string getUserCommand();
	void main();

};

#endif