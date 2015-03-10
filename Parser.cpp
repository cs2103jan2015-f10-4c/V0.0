#include "Parser.h"

time_t Parser::strToDateTime(char ymd[], char hn[]) {
    char y[5];                               // YEAR
    char m[3];                                 // MONTH
    char d[3];                                 // DAY
    char h[3];                                 // HOUR
    char n[3];                                 // MINUTE
    struct tm when;
    
    // Break down String
    sscanf(ymd, "%4s-%2s-%2s",y, m,d);
    sscanf(hn, "%[^:]:%s", h, n);
    
    /*
    //printf("mmdd: %s \n",mmdd);
    printf("y: %s \n",y);
    printf("m: %s \n",m);
    printf("d: %s \n",d);
    printf("h: %s \n",h);
    printf("n: %s \n",n);
    */
    // Convertion
    when.tm_year = atoi(y) - 1900;
    when.tm_mon = atoi(m) - 1;
    when.tm_mday = atoi(d);
    when.tm_hour = atoi(h);
    when.tm_min = atoi(n) - 40;
    when.tm_sec = 0;
    
    time_t t = mktime(&when);
    
    return t;
}

int main()
{
    int end = 0;
    char action[80];
    char title[80];
    
    time_t startDateTime;
    char startDay[20];
    char startTime[20];
    char sDateTime[40];
    
    time_t endDateTime;
    char endDay[20];
    char endTime[20];
    char eDateTime[40];
    
    strftime (sDateTime, 100, "%Y-%m-%d %H:%M", localtime(&startDateTime));
    
    while (end >= 0) {
        cout << "Please enter the command: ";
        scanf ("%79s",action);
        if(strcmp(action, "end") == 0){
            end = -1;
        }
        else{
            cout << "Please enter the title: ";
            scanf ("%79s",title);
            cout << "Please enter the start day and time: ";
            scanf ("%19s %19s",startDay, startTime);
            //printf("startDay: %s \n",startDay);
            //printf("startTime: %s \n",startTime);
            startDateTime = strToDateTime(startDay, startTime);
            strftime (sDateTime, 100, "%Y-%m-%d %H:%M", localtime(&startDateTime));
            
            cout << "Please enter the end day and time: ";
            scanf ("%19s %19s",endDay,endTime);
            endDateTime = strToDateTime(endDay, endTime);
            startDateTime = strToDateTime(endDay, endTime);
            strftime (eDateTime, 100, "%Y-%m-%d %H:%M", localtime(&endDateTime));
            
		    


            printf("Your action is: %s \n",action);
            printf("the title is: %s \n",title);
            printf("form %s \n",sDateTime);
            printf("to %s \n",eDateTime);
        }
        
    }
    
    return(0);
}