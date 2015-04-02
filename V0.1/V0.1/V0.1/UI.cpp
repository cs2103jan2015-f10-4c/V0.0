#include "UI.h"

const string UI::WELCOME_MESSAGE = "Welcome to RushHour, your private assistant\n";



UI::UI(){}
UI::~UI(){}


void UI::main(){
	 getUserCommand();
	
}


string UI::getUserCommand(){
	string command;
	cout << WELCOME_MESSAGE;
	//logic.retriveStorage();
	while (true){
		logic.checkDirectory();
		cout << "command: ";
		getline(cin, command);
		logic.executeUserCommand(command);
	}
}