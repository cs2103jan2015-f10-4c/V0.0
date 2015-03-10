//@author A0099689W
#include <string>
#include <vector>

#include "WWLogic.h"

using namespace std;

const int    WWLogic::ERROR_INDEX        = -1;
const string WWLogic::ADD_LOG            = "adding task.";
const string WWLogic::EDIT_LOG           = "editing task.";
const string WWLogic::DELETE_LOG         = "deleting task.";
const string WWLogic::DELETEALL_LOG      = "deleteingall task.";
const string WWLogic::SEARCH_LOG         = "searching task.";
const string WWLogic::DONE_LOG           = "marking done.";
const string WWLogic::UNDONE_LOG         = "marking undone task.";
const string WWLogic::VIEWALL_LOG        = "viewing all task.";
const string WWLogic::VIEWTIMED_LOG      = "viewing timed task.";
const string WWLogic::VIEWFLOATING_LOG   = "viewing floating task.";
const string WWLogic::VIEWDONE_LOG       = "viewing done task.";
const string WWLogic::VIEWUNDONE_LOG     = "viewing undone task.";
const string WWLogic::VIEWDEADLINE_LOG   = "viewing deadline task.";
const string WWLogic::VIEWOVERDUE_LOG    = "viewing overdue task.";
const string WWLogic::VIEWTODAY_LOG      = "viewing today task.";
const string WWLogic::UNDO_LOG           = "undoing operation.";
const string WWLogic::REDO_LOG           = "redoing operation.";
const string WWLogic::REFRESH_LOG        = "refreshing tasklist.";
const string WWLogic::EXIT_LOG           = "Exiting program.";


// retrieve storage infomation upon construction
WWLogic::WWLogic() {
	_executor.openFile();
}

// executes the user command
// _display is adjusted after this function is executed
void WWLogic::runInput(string inputString, WWUtilities::PageType pageType) {
	_parser.parseInput(inputString);
	WWCommand parsedCommand = _parser.retrieveCommand();
	executeCommand(parsedCommand, pageType);
}

// assist UI to retrieve display information after execution of user command
WWDisplay WWLogic::getDisplay() {
	return _display;
}

// adjust the user command based on different command types and 
// interact with functionalities of the executor to execute the program.
void WWLogic::executeCommand(WWCommand parsedCommand, WWUtilities::PageType pageType) {
	WWUtilities::CommandType command = parsedCommand.getCommand();
	
	WWLogger& logger = WWLogger::getInstance();
	
	switch(command) {
		case WWUtilities::CommandType::ADD: {
			WWTask taskToBeAdded;
			_commandInterpreter.interpretAdd(parsedCommand, taskToBeAdded);
			logger.addLog(ADD_LOG);
			_display = _executor.addTask(taskToBeAdded);
			break;
		}

		case WWUtilities::CommandType::DELETE: {
			logger.addLog(DELETE_LOG);
			if(parsedCommand.hasDetail()) {    //check whether user has input an index
				int deleteIndex;
				_commandInterpreter.interpretDelete(parsedCommand, deleteIndex);
				
				_display = _executor.deleteTask(deleteIndex, pageType);
			} else {
				_display = _executor.deleteTask(ERROR_INDEX, pageType);
			}
			
			break;
		}

		case WWUtilities::CommandType::DELETEALL: {
			logger.addLog(DELETEALL_LOG);
			_display = _executor.deleteAll();
			break;
		}								   

		case WWUtilities::CommandType::EDIT: {
			int editIndex;
			WWTask taskToBeEdited;
			
			logger.addLog(EDIT_LOG);
			
			_commandInterpreter.interpretEdit(parsedCommand, editIndex, taskToBeEdited);
			_display = _executor.editTask(editIndex, taskToBeEdited, pageType);
			
			break;
		}

		case WWUtilities::CommandType::DONE: {
			logger.addLog(DONE_LOG);
			
			if(parsedCommand.hasDetail()) {
				int doneIndex;
				_commandInterpreter.interpretDone(parsedCommand, doneIndex);
				_display = _executor.markDone(doneIndex, pageType);
			} else{
				_display = _executor.markDone(ERROR_INDEX, pageType);
			}
			
			break;
			
		}

		case WWUtilities::CommandType::UNDONE: {
			logger.addLog(UNDONE_LOG);
			
			if(parsedCommand.hasDetail()) {
				int undoneIndex;
				_commandInterpreter.interpretUndone(parsedCommand, undoneIndex);
				_display = _executor.markUndone(undoneIndex, pageType);
			} else{
				_display = _executor.markUndone(ERROR_INDEX, pageType);
			}
			
			break;
		}

		case WWUtilities::SEARCH: {
			vector<string> keywordStorage;
			
			logger.addLog(SEARCH_LOG);
			
			_commandInterpreter.interpretSearch(parsedCommand, keywordStorage);
			_display = _executor.searchTask(keywordStorage);
			break;
		}
		
		case WWUtilities::CommandType::UNDO:{
			logger.addLog(UNDO_LOG);
			
			_display = _executor.undo(pageType);
			break;
	    }

		case WWUtilities::CommandType::REDO:{
			logger.addLog(REDO_LOG);
			
			_display = _executor.redo(pageType);
			break;
	    }

		
		case WWUtilities::CommandType::VIEWALL: {
			logger.addLog(VIEWALL_LOG);
			
			_display = _executor.viewAll();
			break;
		}
		
		case WWUtilities::CommandType::VIEWDEADLINE: {
			logger.addLog(VIEWDEADLINE_LOG);
			
			_display = _executor.viewDeadlineTask();
			break;
		}

		case WWUtilities::CommandType::VIEWTIMED: {
			logger.addLog(VIEWTIMED_LOG);
			
			_display = _executor.viewTimedTask();
			break;
		}

		case WWUtilities::CommandType::VIEWFLOATING: {
			logger.addLog(VIEWFLOATING_LOG);
			
			_display = _executor.viewFloatingTask();
			break;
		}

		case WWUtilities::CommandType::VIEWTODAY: {
			logger.addLog(VIEWTODAY_LOG);
			
			_display = _executor.viewToday();
			break;
		}

		case WWUtilities::CommandType::VIEWDONE: {
			logger.addLog(VIEWDONE_LOG);
			
			_display = _executor.viewDone();
			break;
		}

		case WWUtilities::CommandType::VIEWUNDONE: {
			logger.addLog(VIEWUNDONE_LOG);
			
			_display = _executor.viewUndone();
			break;
		}

		case WWUtilities::CommandType::VIEWOVERDUE: {
			logger.addLog(VIEWOVERDUE_LOG);
			
			_display = _executor.viewOverdue();
			break;
		}
		
		case WWUtilities::CommandType::REFRESH: {
			logger.addLog(REFRESH_LOG);
			
			_display = _executor.refresh(pageType);
			break;
		}

		case WWUtilities::CommandType::EXIT: {
			logger.addLog(EXIT_LOG);
			
			exit(0);
		}

		default: {
			_display = _executor.invalidCommand(pageType);
		}
	}
}