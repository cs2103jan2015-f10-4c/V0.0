#include "Parser.h"
#include "assert.h"
#include <time.h>

const string Parser::DELIMITERS = ";";

Parser::Parser(){
    
}
Parser::~Parser(){
    
}

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
			startTime = TransformTime.convertTime(startTime);
			endTime = TransformTime.convertTime(endTime);
            validTime = TransformTime.checkTime(startTime,endTime);
            if (taskName=="")
                isCorrectFormat = false;
            else
                isCorrectFormat = true;
        }else if (type == 1) {
            taskType = "deadline";
            taskName = getTaskName(detail);
			startTime = "";
            endTime = getStartDetail1(detail);
			endTime = TransformTime.convertTime(endTime);
            validTime = true;
            if (taskName=="")
                isCorrectFormat = false;
            else
                isCorrectFormat = true;
        }else {
            taskType = "floating";
            taskName = getTaskName(detail);
			startTime = "";
			endTime = "";
            validTime = true;
            if (taskName=="")
                isCorrectFormat = false;
            else
                isCorrectFormat = true;
            
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
			startTime = TransformTime.convertTime(startTime);
            endTime = getEndDetail(editDetail);
			endTime = TransformTime.convertTime(endTime);
            validTime = TransformTime.checkTime(startTime,endTime);
        }else if (numberOfDelimiter == 1) {
            taskType = "deadline";
            taskName = getTaskName(editDetail);
			startTime = "";
            endTime = getStartDetail1(editDetail);
			endTime = TransformTime.convertTime(endTime);
            validTime = true;
        }else {
            taskType = "floating";
            taskName = getTaskName(editDetail);
			startTime = "";
			endTime = "";
            validTime = true;
        }
        
    }else if(task == "search"){
        searchWord = detail;
    }else if(task == "mark done"){
        index = getIndex(detail);
    }else if(task == "display"){
        taskType = detail;
    }else if(task == "undo"){
        // Not Done
    }else if(task == "redo"){
        // Not Done
    }else if(task == "directory"){
        taskType = detail;
    }else if(task == "clear"){
        
    }else if(task == "exit"){

    }else {
        //cout<< "Parser: worry input.\n";//task should be made invalid command;
		task = "Invalid Command";
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

bool Parser::getvalidTime(){
    return validTime;
}

bool Parser::getIsCorrectFormat(){
    return isCorrectFormat;
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
