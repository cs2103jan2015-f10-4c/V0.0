#ifndef StringToTime_H
#define StringToTime_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class TransformTime{

    
private:
    int year;
    int month;
    int day;
    int hour;
    int min;
    
    
public:
    
    string startingTime;
    string endingTime;
    time_t sTime;
    time_t eTime;
    
    TransformTime();
    ~TransformTime();
    
    // input the time(String format:yyyy-mm-dd hh:mm). Output the the time_t format
    time_t stringToTime(string t);
    // input the time_t format. output the time(String format:yyyy-mm-dd hh:mm)
    string timeToString(time_t t);
 
    // input the time_t. output the year
    int getYear(time_t t);
    // input the time_t. output the month
    int getMonth(time_t t);
    // input the time_t. output the day
    int getDay(time_t t);
    // input the time_t. output the hour
    int getHour(time_t t);
    // input the time_t. output the min
    int getMin(time_t t);
    
    string getCurrentTime();
	
	
		
    string convertTime(string input);
    
};

#endif


