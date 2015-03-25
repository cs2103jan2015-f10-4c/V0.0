#ifndef StringToTime_H
#define StringToTime_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TransformTime{
    
public:
    
    string startingTime;
    string endingTime;
    time_t sTime;
    time_t eTime;
    
    
    TransformTime();
    ~TransformTime();
    
    time_t stringToTime(string t);
    
    string timeToString(time_t t);
 
    
};

#endif


