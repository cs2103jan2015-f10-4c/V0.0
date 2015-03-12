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
    string task = getCommandType(userCommand);
    string detail = getDetail(userCommand);
    bool systemFeedback = false;
    if (task == "add"){
        //command = COMMAND_ADD;
        systemFeedback = true;
        
        size_t task = std::count(detail.begin(), detail.end(), ';');
        if (task == 3){
            string taskName;
            string startTime;
            string endTime;
            taskName = getTaskName(detail);
            cout << "TName is : "<< taskName << "\n";
            startTime = getStartDetail2(detail);
            cout << "start time is : "<< startTime << "\n";
            endTime = getEndDetail(detail);
            cout << "end time is : "<< endTime << "\n";
            logic.addTask(taskName, startTime, endTime);
        }else if (task == 2){
            string taskName;
            string startTime;
            taskName = getTaskName(detail);
            cout << "TName is : "<< taskName << "\n";
            startTime = getStartDetail1(detail);
            cout << "time is : "<< startTime << "\n";
            //logic.addTask(taskName, startTime);
        }else{
            string taskName;
            taskName = getTaskName(detail);
            cout << "TName is : "<< taskName << "\n";
            //logic.addTask(taskName);
        }
        
        
    } /*
    else if (task == "delete"){
        //command = COMMAND_DELETE;
        systemFeedback = true;
        int index;
        index = getIndex(userCommand);
        logic.deleteTask(index);
    }
   
    else if (task == "search"){
        //command = COMMAND_SEARCH;
        systemFeedback = true;
        
        string keyWord;
        cout << USER_PROMPT_KEYWORD;
        cin >> keyWord;
        logic.searchTask(keyWord);
    }
    else if (task == "edit"){
        //command = COMMAND_EDIT;
        systemFeedback = true;
        
        string taskName;
        string startTime;
        string endTime;
        taskName = getUserTask(userCommand);
        startTime = getStartDetail(userCommand);
        endTime = getEndDetail(userCommand);
        int index;
        logic.editTask(index,taskName, startTime, endTime);
    }*/
    else return false;
    
    //processCommand(command);
    
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
    size_t positionA = 0;
    positionA = input.find_first_of(DELIMITERS);
    positionA++;
    string indexs = input.substr(positionA);
    int index;
    
    index = atoi(indexs.c_str());
    cout << index;
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
    
    //asdas;32456;
    //     A     B
}

string Parser::getStartDetail2(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    size_t positionC = 0;
    string time;
    
    
    positionA = input.find_first_of(DELIMITERS) + 1;
    positionC = input.find_last_of(DELIMITERS);
    string temp = input.substr(positionA, positionC - positionA);
    positionB = temp.find_first_of(DELIMITERS);
    positionA = 0;
    time = temp.substr(positionA, positionB - positionA);
    return time;
    
    //asdas;32456;43546;
    //     A     B     C
}

string Parser::getEndDetail(string input){
    size_t positionA = 0;
    size_t positionB = 0;
    size_t positionC = 0;
    string time;
    
    
    positionA = input.find_first_of(DELIMITERS) + 1;
    positionC = input.find_last_of(DELIMITERS);
    string temp = input.substr(positionA, positionC - positionA);
    positionB = temp.find_first_of(DELIMITERS) + 1;
    positionA = temp.find_first_of(DELIMITERS) + 1;
    time = temp.substr(positionB, positionC - positionB);
    return time;
    
    //asdas;32456;43546;
    //     A     B     C
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
