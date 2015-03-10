#include "UI.h"

string UI::WELCOME_MESSAGE = "Welcome to RushHour, your private assistant\n";
string UI::SUCCESS_MESSAGE = "Your command is successfully performed\n";
string UI::ERROR_MESSAGE = "Sorry, an error has inccurred\n";
string UI::USER_PROMPT_COMMAND = "Please enter your command: ";


UI::UI(){}
UI::~UI(){}


void UI::main(){
	 getUserCommand();
	
}


string UI::getUserCommand(){
	string command;
	cout << WELCOME_MESSAGE;
	while (true){
		cout << USER_PROMPT_COMMAND;
		getline(cin, command);
		if (parser.determineCommandType(command)){
			cout << SUCCESS_MESSAGE;
		}
		else{
			cout << ERROR_MESSAGE;
		}
	}
}