#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

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
    
    sscanf(day, "%2s-%2s-%4s", d,m,y);
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
    strftime (yyyymmddhhnn,40,"%d-%m-%Y %R",timeinfo);
    
   
    string outputTime(yyyymmddhhnn);
    
    return outputTime;
}



int TransformTime::getYear(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    year = timeinfo->tm_year;
    year += 1900;
    return year;
}


int TransformTime::getMonth(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    month = timeinfo->tm_mon;
    month += 1;
    
    return month;
}


int TransformTime::getDay(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    day = timeinfo->tm_mday;
    return day;
}

int TransformTime::getHour(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    hour = timeinfo->tm_hour;
    return hour;
}

int TransformTime::getMin(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    min = timeinfo->tm_min;
    return min;
}

string TransformTime::getCurrentTime(){
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    string currentTime = timeToString(rawtime);
    return currentTime;
}


string TransformTime::convertTime(string input){

    
    char year[5];                                 // YEAR
    char month[3];                                // MONTH
    char day[3];                                  // DAY
    char hour[3];                                 // HOUR
    char minute[3];                               // MINUTE
    ///////////////////////////////////////////
    // Set the Default time is current time
    time_t rawtime;
    struct tm * timeinfo;
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime(year,4,"%Y", timeinfo);
    strftime(month,2,"%m", timeinfo);
    strftime(day,2,"%d", timeinfo);
    strftime(hour,2,"%H", timeinfo);
    strftime(minute,2,"%M", timeinfo);
    //////////////////////////////////////////
    
    char inputTime[input.length()]; // creat the char to store the input
    strcpy(inputTime, input.c_str()); // convert string to char[]
    
    bool HasTimeDay = false; // check the input who has time and day
    bool HasTime = false; // check the input who has time
    bool HasDay = false; // check the input who has day
    
    int space = 0; // the position of space
    
    for (int i=0;i<sizeof(inputTime);i++){
        if (inputTime[i] == ' ')
        {// the input has day and time
            HasTimeDay = true;
            space = i;
        }
    }
    
    int sizeOfTime = 0;
    int sizeOfDay = 0;
    
    if(HasTimeDay){
        sizeOfDay = space;
        sizeOfTime = sizeof(inputTime)-space-1;
    }
    
    
    if (!HasTimeDay)
    {
        if(sizeof(inputTime) > 7)
        {
            sizeOfDay = sizeof(inputTime);
        }
        else
        {
            for (int i=0;i<sizeof(inputTime);i++)
            {
                if ((inputTime[i] == 47 || inputTime[i] == 45)) //the input has / - ??
                {
                    sizeOfDay = sizeof(inputTime);
                }
                else
                {
                    sizeOfTime  = sizeof(inputTime);
                }
            }
            
        }
    }
    
    //cout << " sizeOfTime " <<  sizeOfTime << endl;
    //cout << " sizeOfDay " <<  sizeOfDay << endl;
    
    char Theday[sizeOfDay];
    char Thetime[sizeOfTime];
    
    if (HasTimeDay){
        int i;
        for( i = 0 ;i < space ; i++)
        {
            Theday[i] = inputTime[i];
        }
        HasDay = true;
        
        i++;
        int j=0;
        for( ;i < sizeof(inputTime); i++)
        {
            Thetime[j] = inputTime[i];
            j++;
        }
        HasTime = true ;
        cout << "\n";
    }
    
    
    if (!HasTimeDay)
    {
        if(sizeof(inputTime) > 7)
        {
            HasDay = true;
            for( int i = 0 ;i < sizeof(inputTime) ; i++)
            {
                Theday[i] = inputTime[i];
            }
        }
        else
        {
            for (int i=0;i<sizeof(inputTime);i++)
            {
                if ((inputTime[i] == 47 || inputTime[i] == 45)) //the input has / - ??
                {
                    HasDay = true ;
                }
            }
            
            
            if(!HasDay)
            {
                HasTime = true ;
                for( int i = 0 ;i < sizeof(inputTime) ; i++)
                {
                    Thetime[i] = inputTime[i];
                }
            }else
            {
                for( int i = 0 ;i < sizeof(inputTime) ; i++)
                {
                    Theday[i] = inputTime[i];
                }
            }
            
        }
    }

    // check the analyze is correct
     /*
    cout << "\n\nHasTime: " << HasTime << endl;
    cout << "HasDay: " << HasDay << endl;
    cout << "HasTimeDay: " << HasTimeDay << endl;
    cout << "Thetime SIZE :" <<sizeof(Thetime) << endl;
   
    cout << "\ninputTime: " << inputTime << endl;
    cout << "Theday: " << Theday << endl;
    cout << "Thetime: " << Thetime << endl;
    
    
    cout << "\nTheday SIZE :" <<sizeof(Theday) << endl;
    
    */
    
    if (HasTime)
    {
        if (sizeof(Thetime) < 4) //the format: HMM
        {
            hour[0] = '0';
            hour[1] = Thetime[0];
            minute[0] = Thetime[1];
            minute[1] = Thetime[2];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }else if(sizeof(Thetime) < 5) //the format: HHMM
        {
            hour[0] = Thetime[0];
            hour[1] = Thetime[1];
            minute[0] = Thetime[2];
            minute[1] = Thetime[3];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }else if(sizeof(Thetime) < 6 && (Thetime[2]==58||Thetime[2]==46)) //the format: HH:MM
        {
            hour[0] = Thetime[0];
            hour[1] = Thetime[1];
            minute[0] = Thetime[3];
            minute[1] = Thetime[4];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }
        else
        {
            if(Thetime[sizeof(Thetime)-1] == 'h') //the format: XX:XXh XX:.XXh XXXXh
            {
                hour[0] = Thetime[0];
                hour[1] = Thetime[1];
                minute[0] = Thetime[sizeof(Thetime)-3];
                minute[1] = Thetime[sizeof(Thetime)-2];
                //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
            }
            else if(Thetime[sizeof(Thetime)-1] == 'm') //the format:am/apm
            {
                if(Thetime[sizeof(Thetime)-2] == 'a') //the format: XX:XXam XX:.XXam XXXXam
                {
                    hour[0] = Thetime[0];
                    hour[1] = Thetime[1];
                    minute[0] = Thetime[sizeof(Thetime)-4];
                    minute[1] = Thetime[sizeof(Thetime)-3];
                    //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
                }
                else //the format: XX:XXpm XX:.XXpm XXXXpm
                {
                    if (Thetime[1] == '1')
                    {
                        if(Thetime[0] == '0')
                        {
                            hour[0] = '1';
                            hour[1] = '3';
                        }
                        else if(Thetime[0] == '1')
                        {
                            hour[0] = '2';
                            hour[1] = '3';
                        }
                    }
                    else if(Thetime[1] == '2')
                    {
                        if(Thetime[0] == '0')
                        {
                            hour[0] = '1';
                            hour[1] = '4';
                        }
                        else if(Thetime[0] == '1')
                        {
                            hour[0] = '2';
                            hour[1] = '4';
                        }
                    }
                    else if(Thetime[1] == '3')
                    {
                        hour[0] = '1';
                        hour[1] = '5';
                    }
                    else if(Thetime[1] == '4')
                    {       hour[0] = '1';
                        hour[1] = '6';
                    }
                    else if(Thetime[1] == '5')
                    {
                        hour[0] = '1';
                        hour[1] = '7';
                    }
                    else if(Thetime[1] == '6')
                    {
                        hour[0] = '1';
                        hour[1] = '8';
                    }
                    else if(Thetime[1] == '7')
                    {
                        hour[0] = '1';
                        hour[1] = '9';
                    }
                    else if(Thetime[1] == '8')
                    {
                        hour[0] = '2';
                        hour[1] = '0';
                    }
                    else if(Thetime[1] == '9')
                    {
                        hour[0] = '2';
                        hour[1] = '1';
                    }
                    else if(Thetime[1] == '0')
                    {
                        hour[0] = '2';
                        hour[1] = '2';
                    }
                    minute[0] = Thetime[sizeof(Thetime)-4];
                    minute[1] = Thetime[sizeof(Thetime)-3];
                    //cout<< hour[0] << hour[1] << ":" << minute[0] <<minute[1] << endl;
                }
            }
        }
    }
    
    if (HasDay){
        int i=0;
        int j=0;
        int number=0;
        for(int x=0;x<sizeof(Theday);x++)
        {
            if (!(Theday[x] >= 48 && Theday[x] <= 57))
            {
                number++;
                if(number == 1)
                {
                    i=x;
                }
                else
                {
                    j=x;
                }
            }
        }
        //cout << "number is " << number << endl;
        //cout << "i is " << i << endl;
        //cout << "j is " << j << endl;
        
        if(number==1) //the format: dd-mm dd/mm
        {
            if(i==1)
            {
                if (sizeof(Theday)==3)
                {
                    day[0] = '0';
                    day[1] = Theday[0];
                    month[0] = '0';
                    month[1] = Theday[2];
                }
                else if(sizeof(Theday)==4)
                {
                    day[0] = '0';
                    day[1] = Theday[0];
                    month[0] = Theday[2];
                    month[1] = Theday[3];
                }
            }
            else if(i==2)
            {
                if (sizeof(Theday)==4)
                {
                    day[0] = Theday[0];
                    day[1] = Theday[1];
                    month[0] = '0';
                    month[1] = Theday[3];
                }
                else if(sizeof(Theday)==5)
                {
                    day[0] = Theday[0];
                    day[1] = Theday[1];
                    month[0] = Theday[3];
                    month[1] = Theday[4];
                }
            }
            //cout<< "dd/mm :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1] << endl;
        }
        else if(number == 2) //the format: dd/mm/yyyy dd-mm-yyyy
        {
            if(i==1 && j ==3)
            {
                day[0] = '0';
                day[1] = Theday[0];
                month[0] = '0';
                month[1] = Theday[2];
                year[0] = Theday[4];
                year[1] = Theday[5];
                year[2] = Theday[6];
                year[3] = Theday[7];
            }
            else if(i==1 && j ==4)
            {
                day[0] = '0';
                day[1] = Theday[0];
                month[0] = Theday[2];
                month[1] = Theday[3];
                year[0] = Theday[5];
                year[1] = Theday[6];
                year[2] = Theday[7];
                year[3] = Theday[8];
            }
            else if(i==2 && j ==4)
            {
                day[0] = Theday[0];
                day[1] = Theday[1];
                month[0] = '0';
                month[1] = Theday[3];
                year[0] = Theday[5];
                year[1] = Theday[6];
                year[2] = Theday[7];
                year[3] = Theday[8];
            }
            else if(i==2 && j ==5)
            {
                day[0] = Theday[0];
                day[1] = Theday[1];
                month[0] = Theday[3];
                month[1] = Theday[4];
                year[0] = Theday[6];
                year[1] = Theday[7];
                year[2] = Theday[8];
                year[3] = Theday[9];
            }
            //cout<< "dd/mm/yyyy :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1]<<"/"<<year[0]<<year[1] <<year[2]<<year[3]<< endl;
        }
        else if(number > 2)
        {
            string tempMonth;
            char temp[3];
            if(i==1)
            {
                day[0] = '0';
                day[1] = Theday[0];
                year[0] = Theday[sizeof(Theday)-4];
                year[1] = Theday[sizeof(Theday)-3];
                year[2] = Theday[sizeof(Theday)-2];
                year[3] = Theday[sizeof(Theday)-1];
                
                temp[0]=Theday[1];
                temp[1]=Theday[2];
                temp[2]=Theday[3];
                tempMonth = temp;
                
            }
            else if(i==2)
            {
                day[0] = Theday[0];
                day[1] = Theday[1];
                year[0] = Theday[sizeof(Theday)-4];
                year[1] = Theday[sizeof(Theday)-3];
                year[2] = Theday[sizeof(Theday)-2];
                year[3] = Theday[sizeof(Theday)-1];
                
                temp[0]=Theday[2];
                temp[1]=Theday[3];
                temp[2]=Theday[4];
                tempMonth = temp;
                
            }
            
            if((tempMonth=="jan")||(tempMonth=="Jan")||(tempMonth=="JAN"))
            {
                month[0] = '0';
                month[1] = '1';
            }else if((tempMonth=="feb")||(tempMonth=="Feb")||(tempMonth=="FEB"))
            {
                month[0] = '0';
                month[1] = '2';
            }else if((tempMonth=="mar")||(tempMonth=="Mar")||(tempMonth=="MAR"))
            {
                month[0] = '0';
                month[1] = '3';
            }else if((tempMonth=="apr")||(tempMonth=="Apr")||(tempMonth=="APR"))
            {
                month[0] = '0';
                month[1] = '4';
            }else if((tempMonth=="may")||(tempMonth=="May")||(tempMonth=="MAY"))
            {
                month[0] = '0';
                month[1] = '5';
            }else if((tempMonth=="jun")||(tempMonth=="Jun")||(tempMonth=="JUN"))
            {
                month[0] = '0';
                month[1] = '6';
            }else if((tempMonth=="jul")||(tempMonth=="Jul")||(tempMonth=="JUL"))
            {
                month[0] = '0';
                month[1] = '7';
            }else if((tempMonth=="aug")||(tempMonth=="Aug")||(tempMonth=="AUG"))
            {
                month[0] = '0';
                month[1] = '8';
            }else if((tempMonth=="sep")||(tempMonth=="Sep")||(tempMonth=="SEP"))
            {
                month[0] = '0';
                month[1] = '9';
            }else if((tempMonth=="oct")||(tempMonth=="Oct")||(tempMonth=="OCT"))
            {
                month[0] = '1';
                month[1] = '0';
            }else if((tempMonth=="nov")||(tempMonth=="Nov")||(tempMonth=="NOV"))
            {
                month[0] = '1';
                month[1] = '1';
            }else if((tempMonth=="dec")||(tempMonth=="Dec")||(tempMonth=="DEC"))
            {
                month[0] = '1';
                month[1] = '2';
            }
            
            //cout<< "dd/mm/yyyy :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1]<<"/"<<year[0]<<year[1] <<year[2]<<year[3]<< endl;
            
        }
        
        
    }
    
    
    
  
    
    struct tm when;
    time_t outputTime = mktime(&when);
    
    when.tm_year = atoi(year)-1900;
    when.tm_mon = atoi(month)-1;
    when.tm_mday = atoi(day);
    when.tm_hour = atoi(hour);
    when.tm_min = atoi(minute);
    when.tm_sec = 0;
    outputTime = mktime(&when);
    
    string output = timeToString(outputTime);
    
    return output;
    
}






