#include "Parser.h"
#include "assert.h"
#include <time.h>

const string Parser::DELIMITERS = ";";

Parser::Parser(){
    
}
Parser::~Parser(){
    
}

/*
bool Parser::determineCommand(string userCommand){
	//assert(userCommand != "");
	//if (userCommand == "") {
	//	throw invalid_argument("Invalid user input!");
	//}
    
    // Divide two string 1) Type of the task 2) Content of the task
    string task = getCommandType(userCommand);
    string detail = getDetail(userCommand);
    
    bool systemFeedback = false;
    
    // The type of the task is ADD
    if (task == "add") {
        systemFeedback = true;
        size_t task = std::count(detail.begin(), detail.end(), ';');
        if (task == 2) {
            string taskName;
            string startTime;
            string endTime;
            taskName = getTaskName(detail);
            startTime = getStartDetail2(detail);
            endTime = getEndDetail(detail);
            logic.addTask(taskName, startTime, endTime);
        }else if (task == 1) {
            string taskName;
            string startTime;
            taskName = getTaskName(detail);
            startTime = getStartDetail1(detail);
            logic.addDeadlineTask(taskName, startTime);
        }else {
            string taskName;
            taskName = getTaskName(detail);
            logic.addFloatingTask(taskName);
        }
    }
    // The type of the task is DELETE
    else if (task == "delete"){
        systemFeedback = true;
        int index;
        index = getIndex(detail);
        logic.deleteTask(index);
    }
    // The type of the task is SEARCH
    else if (task == "search"){
        systemFeedback = true;
        string keyWord = detail;
        logic.searchTask(keyWord);
    }
    // The type of the task is EDIT
    else if (task == "edit"){
        systemFeedback = true;
        int index;
        index = getIndex(detail);
        string editDetail = getDetail(detail);
        string taskName;
        string startTime;
        string endTime;
        
        taskName = getTaskName(editDetail);
        startTime = getStartDetail2(editDetail);
        endTime = getEndDetail(editDetail);
        logic.editTask(index,taskName, startTime, endTime);
    }
    // The type of the task is DISPLAY
    else if (task == "display"){
        systemFeedback = true;
        string type = detail;
        if ( type == "all"){
            logic.displayAll();
        }
        else if ( type == "dl"){
            logic.displayDeadline();
        }
        else if( type == "ft"){
            logic.displayFloating();
        }else{}
    }
    // The type of the task is MARKDONE
    else if (task == "markdone"){
        systemFeedback = true;
        int index;
        index = getIndex(detail);
        logic.markdone(index);
    }
	else if (task == "undo") {
		systemFeedback = true;
		history.undoTaskStorage
    else return false;
    
    return systemFeedback;
}
*/

string Parser::getCommandWord(string command){
    string task = getCommandType(command);
    string detail = getDetail(command);
    if(task == "add"){
        size_t type = count(detail.begin(), detail.end(), ';');
        if (type == 2) {
            taskType = "timed";
            taskName = getTaskName(detail);
            startTime = getStartDetail2(detail);
            endTime = getEndDetail(detail);
        }else if (type == 1) {
            taskType = "deadline";
            taskName = getTaskName(detail);
            endTime = getStartDetail1(detail);

        }else {
            taskType = "floating";
            taskName = getTaskName(detail);
            
        }
    }else if(task == "delete"){
        index = getIndex(detail);
    }else if(task == "edit"){
        index = getIndex(detail);
		string editDetail = getDetail(detail);
		size_t numberOfDelimiter = count(editDetail.begin(), editDetail.end(), ';');

		if (numberOfDelimiter == 2) {
            taskType = "timed";
            taskName = getTaskName(editDetail);
            startTime = getStartDetail2(editDetail);
            endTime = getEndDetail(editDetail);
        }else if (numberOfDelimiter == 1) {
            taskType = "deadline";
            taskName = getTaskName(editDetail);
            endTime = getStartDetail1(editDetail);

        }else {
            taskType = "floating";
            taskName = getTaskName(editDetail);
            
        }
		
		/*index = getIndex(detail);
        string editDetail = getDetail(detail);
        taskName = getTaskName(editDetail);
        startTime = getStartDetail2(editDetail);
        endTime = getEndDetail(editDetail);*/
        
    }else if(task == "search"){
        searchWord = detail;
    }else if(task == "markdone"){
        index = getIndex(detail);
    }else if(task == "display"){
        taskType = detail;
    }else if(task == "undo"){
        // Not Done
    }else if(task == "redo"){
        // Not Done
    }else {
        cout<< "Parser: worry input.\n";
    }
    
    return task;
}


string Parser::getTaskType(){
    return taskType;
}

string Parser::getTaskName(){
    return taskName;
}

string Parser::getStartTime(){
    return startTime;
}

string Parser::getEndTime(){
    return endTime;
}

int Parser::getIndex(){
    return index;
}

string Parser::getSearchWord(){
    return searchWord;
}

string Parser::getCommandType(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    string task;
    positionB = input.find_first_of(DELIMITERS);
    task = input.substr(positionA, positionB - positionA);
    return task;
}

string Parser::getDetail(string input){
    size_t positionA = 0;
    string detail;
    positionA = input.find_first_of(DELIMITERS);
    positionA++;
    detail = input.substr(positionA);
    return detail;
}

int Parser::getIndex(string input){
    int index = atoi(input.c_str()); // String to Integer
    return index;
}

string Parser::getTaskName(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    string task;
    positionB = input.find_first_of(DELIMITERS);
    task = input.substr(positionA, positionB - positionA);
    return task;
}

string Parser::getStartDetail1(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    string time;
    positionA = input.find_first_of(DELIMITERS) + 1;
    positionB = input.find_last_of(DELIMITERS);
    time = input.substr(positionA, positionB - positionA);
    return time;
}

string Parser::getStartDetail2(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    size_t positionC = 0;
    string time;
    
    positionA = input.find_first_of(DELIMITERS) + 1;
    positionC = input.size();
    string temp = input.substr(positionA, positionC - positionA);
    positionB = temp.find_first_of(DELIMITERS);
    positionA = 0;
    time = temp.substr(positionA, positionB - positionA);
    return time;
}

string Parser::getEndDetail(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    size_t positionC = 0;
    string time;
    
    positionA = input.find_first_of(DELIMITERS) + 1;
    positionC = input.size();
    string temp = input.substr(positionA, positionC - positionA);
    positionB = temp.find_first_of(DELIMITERS) + 1;
    positionA = temp.find_first_of(DELIMITERS) + 1;
    time = temp.substr(positionB, positionC - positionB);
    return time;

}
