#include "Parser.h"

const string Parser::DELIMITERS = ";";

Parser::Parser(){
    
}
Parser::~Parser(){
    
}


bool Parser::determineCommand(string userCommand){
    string task = getCommandType(userCommand);
    string detail = getDetail(userCommand);
    bool systemFeedback = false;
    if (task == "add"){
        systemFeedback = true;
        size_t task = std::count(detail.begin(), detail.end(), ';');
        if (task == 2){
            string taskName;
            string startTime;
            string endTime;
            taskName = getTaskName(detail);
            startTime = getStartDetail2(detail);
            endTime = getEndDetail(detail);
            logic.addTask(taskName, startTime, endTime);
        }else if (task == 1){
            string taskName;
            string startTime;
            taskName = getTaskName(detail);
            startTime = getStartDetail1(detail);
            //cout<<taskName<<"& "<< startTime;
            logic.addDeadlineTask(taskName, startTime);
        }else{
            string taskName;
            taskName = getTaskName(detail);
            logic.addFloatingTask(taskName);
        }
        
        
    }
    else if (task == "delete"){
        systemFeedback = true;
        int index;
        index = getIndex(detail);
        logic.deleteTask(index);
    }
   
    else if (task == "search"){
        systemFeedback = true;
        string keyWord = detail;
        logic.searchTask(keyWord);
    }
    
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
        //logic.editTask(index,taskName, startTime, endTime);
    }
    else return false;
    
    return systemFeedback;
    
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
    int index = atoi(input.c_str());
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
