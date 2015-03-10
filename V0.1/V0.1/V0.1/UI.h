

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

	Parser parser;
	static string WELCOME_MESSAGE;
    static string SUCCESS_MESSAGE;
	static string ERROR_MESSAGE;
	static string USER_PROMPT_COMMAND;
	

	void displayUserMessage();

public:

	UI();
	~UI();
	string getUserCommand();
	void main();

};

#endif