#include "UI.h"

static const string WELCOME_MESSAGE = "Welcome to RushHour, your private assistant";
static const string SUCCESS_MESSAGE = "Your command is successfully performed";
static const string ERROR_MESSAGE = "Sorry, an error has inccurred";
static const string USER_PROMPT_COMMAND = "Please enter your command: ";

void UI::main(){
	 getUserCommand();
	
}


string UI::getUserCommand(){
	string command;
	cout << WELCOME_MESSAGE;
	while (true){
		cout << USER_PROMPT_COMMAND;
		getline(cin, command);
		if (Parser.determineCommandType(command)){
			cout << SUCCESS_MESSAGE;
		}else{
			cout << ERROR_MESSAGE;
		}
	}
}