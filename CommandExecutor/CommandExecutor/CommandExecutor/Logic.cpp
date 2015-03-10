
#include "Logic.h"

vector <string> Logic::inputStorage;
vector <Logic::COMMAND_TYPE> Logic::commandStorage;


Logic::Logic(){
}

Logic::COMMAND_TYPE Logic::getCommandType(string command){

	if (command == "add"){
		return COMMAND_ADD;
	}
	else if (command == "display"){
		return COMMAND_DISPLAY;
	}
	else if (command == "delete"){
		return COMMAND_DELETE;
	}
	else if (command == "sort"){
		return COMMAND_SORT;
	}
	else if (command == "edit"){
		return COMMAND_EDIT;
	}
	else if (command == "search"){
		return COMMAND_SEARCH;
	}
	else if (command == "clear"){
		return COMMAND_CLEAR;
	}
	else if (command == "exit"){
		return COMMAND_EXIT;
	}
	else{
		return COMMAND_INVALID;
	}

}


void Logic::processCommand(string command){
	
	COMMAND_TYPE userCommand = getCommandType(command);
	commandStorage.push_back(userCommand);

	switch (userCommand){

	    case COMMAND_ADD:{
			string taskName = Parser::getTaskName();
			string date= Parser::getDate();
			string startTime =Parser::getStartTime();
			string duration=Parser::Duration();
			addExecutor::addTask(taskName, date, startTime, duration);
			
			break;
		}
		case COMMAND_DELETE:{
			int index = Parser::getIndex();
			deleteExecutor::deleteTask(index);
			displayExecutor::displayAll();
			break;
		}
		case COMMAND_DISPLAY:{
			//various display method
			break;
		}
		case COMMAND_EDIT:{
			int index = Parser::getIndex();

			break;
		}
		case COMMAND_CLEAR:{

			break;
		}
		case COMMAND_SORT:{
			//taskSorter should perform sorting function
			//And the function should be something perfoms after selecting the mode of display
			break;
		}
		case COMMAND_SEARCH:{
			string keyWord = Parser::getKeyWord();

			break;
		}
		case COMMAND_EXIT:{
			break;
		}
		case COMMAND_INVALID:{
			break;
		}

	}   

}