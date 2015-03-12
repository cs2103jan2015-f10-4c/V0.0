#include "Parser.h"

const string Parser::DELIMITERS = ";";
const int Parser::NO_OF_TIME_INDICATORS = 6;
const string Parser::TIME_INDICATORS[NO_OF_TIME_INDICATORS] = { " from "," by "," at "," on "," in ", " to "};

Parser::Parser(){
    
}
Parser::~Parser(){
    
}
/*
bool Parser::determineCommand(string input,string& commandType,string& userTask,string& startDetail, string& endDetail){
    commandType = getCommandType(input);
    userTask = getUserTask(input);
    startDetail = getStartDetail(input);
    endDetail = getEndDetail(input);
    
    return true;
}
*/

bool Parser::determineCommand(string userCommand){
    COMMAND_TYPE command;
    size_t positionA = 0;
    size_t positionB = 0;
    string task;
    positionB = userCommand.find_first_of(DELIMITERS);
    task = userCommand.substr(positionA, positionB - positionA);
    
    bool systemFeedback = false;
    if (task == "add"){
        command = COMMAND_ADD;
        systemFeedback = true;
        
        string taskName;
        string startTime;
        string endTime;
        taskName = getUserTask(userCommand);
        startTime = getStartDetail(userCommand);
        endTime = getEndDetail(userCommand);
        logic.addTask(taskName, startTime, endTime);
    }
    else if (task == "delete"){
        command = COMMAND_DELETE;
        systemFeedback = true;
        
        int index;
        cout << USER_PROMPT_INDEX;
        cin >> index;
        logic.deleteTask(index);
    }
    else if (task == "search"){
        command = COMMAND_SEARCH;
        systemFeedback = true;
        
        string keyWord;
        cout << USER_PROMPT_KEYWORD;
        cin >> keyWord;
        logic.searchTask(keyWord);
    }
    else if (task == "edit"){
        command = COMMAND_EDIT;
        systemFeedback = true;
        
        string taskName;
        string startTime;
        string endTime;
        taskName = getUserTask(userCommand);
        startTime = getStartDetail(userCommand);
        endTime = getEndDetail(userCommand);
        int index;
        logic.editTask(index,taskName, startTime, endTime);
    }
    else return false;
    
    processCommand(command);
    
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

string Parser::getUserTask(string input){
    size_t positionA=0;
    size_t positionB=0;
    string task;
    positionA = input.find_first_of(DELIMITERS);
    positionA++;
    for (int i = 0; i < NO_OF_TIME_INDICATORS; i++){
        positionB = input.find(TIME_INDICATORS[i], positionA + 1);
        if (positionB != string::npos){
            break;
        }
    }
    task = input.substr(positionA, positionB - positionA);
    
    return task;
}


string Parser::getStartDetail(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    string task;
    for (int i = 0; i < NO_OF_TIME_INDICATORS; i++){
        positionA = input.find(TIME_INDICATORS[i]);
        if (positionA != string::npos && TIME_INDICATORS[i]!=" by "){
            positionA = input.find(DELIMITERS, positionA + 1);
            positionA++;
            positionB = input.find(DELIMITERS, positionA);
            break;
        }
    }
    if (positionB==0){
        task = "";
    }
    else{
        task = input.substr(positionA, positionB - positionA);
    }
    return task;
}

string Parser::getEndDetail(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    string task;
    for (int i = 0; i < NO_OF_TIME_INDICATORS; i++){
        positionA = input.find(TIME_INDICATORS[i]);
        if (positionA != string::npos && TIME_INDICATORS[i] != " from "){
            positionA = input.find(DELIMITERS, positionA + 1);
            positionA++;
            positionB = input.find(DELIMITERS, positionA);
            break;
        }
    }
    if (positionB == 0){
        task = "";
    }
    else{
        task = input.substr(positionA, positionB - positionA);
    }
    return task;
}
/*
bool Parser::determineCommandType(string userCommand){
    COMMAND_TYPE command;
    bool systemFeedback = false;
    if (userCommand == "add"){
        command = COMMAND_ADD;
        systemFeedback = true;
    }
    else if (userCommand == "delete"){
        command = COMMAND_DELETE;
        systemFeedback = true;
    }
    else if (userCommand == "search"){
        command = COMMAND_SEARCH;
        systemFeedback = true;
    }
    else if (userCommand == "edit"){
        command = COMMAND_EDIT;
        systemFeedback = true;
    }
    else return false;
    
    processCommand(command);
    
    return systemFeedback;
    
}

void Parser::processCommand(COMMAND_TYPE command){
    switch (command)
    {
        case Parser::COMMAND_ADD:{
            string taskName;
            string startTime;
            string endTime;
            
            //cout << USER_PROMPT_TASKNAME;
            cin >> taskName;
            cout << USER_PROMPT_STARTTIME;
            cin >> startTime;
            cout << USER_PROMPT_ENDTIME;
            cin >> endTime;
            logic.addTask(taskName, startTime, endTime);
            break;
            
        }case Parser::COMMAND_DELETE:{
            int index;
            cout << USER_PROMPT_INDEX;
            cin >> index;
            logic.deleteTask(index);
            break;
        }case Parser::COMMAND_SEARCH:{
            string keyWord;
            cout << USER_PROMPT_KEYWORD;
            cin >> keyWord;
            logic.searchTask(keyWord);
            break;
        }case Parser::COMMAND_EDIT:{
            int index;
            string newTaskName;
            string newStartTime;
            string newEndTime;
            cout << USER_PROMPT_INDEX;
            cin >> index;
            cout << USER_PROMPT_NEWTASKNAME;
            cin >> newTaskName;
            cout << USER_PROMPT_NEWSTARTTIME;
            cin >> newStartTime;
            cout << USER_PROMPT_ENDTIME;
            cin >> newEndTime;
            logic.editTask(index, newTaskName, newStartTime, newEndTime);
            break;
        }default:
            break;
    }
}
*/
