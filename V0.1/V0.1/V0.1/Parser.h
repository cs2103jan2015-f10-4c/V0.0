
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Logic.h"


using namespace std;

class Parser{
    
private:
    Logic logic;
    //static enum COMMAND_TYPE {COMMAND_ADD,  COMMAND_DELETE, COMMAND_SEARCH, COMMAND_EDIT};
    static const string DELIMITERS;
    static const string TIME_INDICATORS[];
    static const int NO_OF_TIME_INDICATORS;
    
    static  string USER_PROMPT_TASKNAME ;
    static  string USER_PROMPT_STARTTIME;
    static  string USER_PROMPT_ENDTIME;
    static  string USER_PROMPT_INDEX;
    static  string USER_PROMPT_KEYWORD ;
    static  string USER_PROMPT_NEWTASKNAME ;
    static  string USER_PROMPT_NEWSTARTTIME ;
    static  string USER_PROMPT_NEWENDTIME ;
    
    string getCommandType(string);
    string getTaskName(string);
    string getStartDetail1(string);
    string getStartDetail2(string);
    string getEndDetail(string);
    int getIndex(string input);
    string getDetail(string input);
    
public:
    
    Parser();
    ~Parser();
    
    bool determineCommand(string);
    
    //void processCommand(COMMAND_TYPE);
    
    
};

#endif
