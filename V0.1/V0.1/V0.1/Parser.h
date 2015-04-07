
#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
//#include "History.h"
#include "TransformTime.h"

using namespace std;

class Parser{
    
private:
    //Logic logic;
	//History history;
	TransformTime TransformTime;
    static const string DELIMITERS;    
    static  string USER_PROMPT_TASKNAME ;
    static  string USER_PROMPT_STARTTIME;
    static  string USER_PROMPT_ENDTIME;
    static  string USER_PROMPT_INDEX;
    static  string USER_PROMPT_KEYWORD ;
    static  string USER_PROMPT_NEWTASKNAME ;
    static  string USER_PROMPT_NEWSTARTTIME ;
    static  string USER_PROMPT_NEWENDTIME ;
    
    
    
    
    string taskType;
    string taskName;
    string startTime;
    string endTime;
    int index;
    string searchWord;
    bool validTime;
    
    
    string getCommandType(string);
    string getDetail(string);
    int getIndex(string);
    string getTaskName(string);
    string getStartDetail1(string);
    string getStartDetail2(string);
    string getEndDetail(string);
    
    
public:
    
    Parser();
    ~Parser();
    
    //bool determineCommand(string command);
    
    string getCommandWord(string command);
    
    string getTaskType();
    
    string getTaskName();
    
    string getStartTime();
    
    string getEndTime();
    
    int getIndex();
    
    string getSearchWord();
    
    bool getvalidTime();
};

#endif
