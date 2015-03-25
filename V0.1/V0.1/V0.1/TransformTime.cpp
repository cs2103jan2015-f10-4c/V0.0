#include "TransformTime.h"

TransformTime::TransformTime(){}

TransformTime::~TransformTime(){}

time_t TransformTime::stringToTime(string t){
    string inputTime = t;
    time_t outputTime;
    
    
    char y[5];                                 // YEAR
    char m[3];                                 // MONTH
    char d[3];                                 // DAY
    char h[3];                                 // HOUR
    char n[3];                                 // MINUTE
    struct tm when;
    
    char input[1024];
    strcpy(input, inputTime.c_str());
    
    char day[20];
    char time[20];
    // Break down String
    sscanf (input,"%19s %19s",day, time);
    
    sscanf(day, "%4s-%2s-%2s",y, m,d);
    sscanf(time, "%[^:]:%s", h, n);
    
    // Convertion
    when.tm_year = atoi(y) - 1900;
    when.tm_mon = atoi(m) - 1;
    when.tm_mday = atoi(d);
    when.tm_hour = atoi(h);
    when.tm_min = atoi(n) - 40;
    when.tm_sec = 0;
    
    outputTime = mktime(&when);

    return outputTime;
}




string TransformTime::timeToString(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    char yyyymmddhhnn[40];
    strftime (yyyymmddhhnn,40,"%Y-%m-%d %R",timeinfo);
    
   
    string outputTime(yyyymmddhhnn);
    
    return outputTime;
}