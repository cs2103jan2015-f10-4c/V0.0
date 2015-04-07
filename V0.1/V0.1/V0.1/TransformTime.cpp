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

bool TransformTime::checkTime(string startTime,string endTime){
    time_t start = stringToTime(startTime);
    time_t end = stringToTime(endTime);
    
    if (start < end)
    {
        return true;
    }else{
        return false;
    }

}


string TransformTime::timeToString(time_t t){
    time_t inputTime = t;
    tm *timeinfo = localtime(&inputTime);
    char yyyymmddhhnn[40];
    strftime (yyyymmddhhnn,40,"%d-%m-%Y %H:%M",timeinfo);
    
    
    string outputTime(yyyymmddhhnn);
    //cout << ":) "<< outputTime;
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

size_t getSize(char *ptr){
    return sizeof(ptr);
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
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(year, sizeof(year), "%Y", timeinfo);
    strftime(month, sizeof(month), "%m", timeinfo);
    strftime(day, sizeof(day), "%d", timeinfo);
    strftime(hour, sizeof(hour), "%H", timeinfo);
    strftime(minute, sizeof(minute), "%M", timeinfo);
    //////////////////////////////////////////
    //cout<< "hh:mm"<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
    //cout<< "dd/mm/yyyy :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1]<<"/"<<year[0]<<year[1] <<year[2]<<year[3]<< endl;
    
	char *inputTime = new char[input.length()]; // creat the char to store the input
    strcpy(inputTime, input.c_str()); // convert string to char[]
   
	 cout << endl<< "**strlen(inputTime)"<< strlen(inputTime)  << endl;

    bool HasTimeDay = false; // check the input who has time and day
    bool HasTime = false; // check the input who has time
    bool HasDay = false; // check the input who has day
    
    int space = 0; // the position of space
    
    for (unsigned i=0;i<strlen(inputTime);i++){
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
        sizeOfTime = strlen(inputTime)-space-1;
    }
    
    
    if (!HasTimeDay)
    {
        if(strlen(inputTime) > 7)
        {
            sizeOfDay = strlen(inputTime);
        }
        else
        {
            for (unsigned i=0;i<strlen(inputTime);i++)
            {
                if ((inputTime[i] == 47 || inputTime[i] == 45)) //the input has / - ??
                {
                    sizeOfDay = strlen(inputTime);
                }
                else
                {
                    sizeOfTime  = strlen(inputTime);
                }
            }
            
        }
    }

    //cout << " sizeOfTime " <<  sizeOfTime << endl;
    //cout << " sizeOfDay " <<  sizeOfDay << endl;
    
    char *Theday = new char[sizeOfDay];
    char *Thetime = new char[sizeOfTime];
    
    if (HasTimeDay){
		unsigned i;
        for( i=0;i < space ; i++)
        {
            Theday[i] = inputTime[i];
        }
        HasDay = true;
        
        i++;
        int j=0;
        for( ;i < strlen(inputTime); i++)
        {
            Thetime[j] = inputTime[i];
            j++;
        }
        HasTime = true ;
        cout << "\n";
    }
    
   
    if (!HasTimeDay)
    {
        if(strlen(inputTime) > 7)
        {
            HasDay = true;
            for( unsigned i = 0 ;i < strlen(inputTime) ; i++)
            {
                Theday[i] = inputTime[i];
            }
        }
        else
        {
            for (unsigned i=0;i<strlen(inputTime);i++)
            {
                if ((inputTime[i] == 47 || inputTime[i] == 45)) //the input has / - ??
                {
                    HasDay = true ;
                }
            }
           
            if(!HasDay)
            {
                HasTime = true ;
                for( unsigned i = 0 ;i < strlen(inputTime) ; i++)
                {
                    Thetime[i] = inputTime[i];
                }
            }else
            {
                for( unsigned  i = 0 ;i < strlen(inputTime) ; i++)
                {
                    Theday[i] = inputTime[i];
                }
            }
            
        }
    }
    
    // check the analyze is correct
    
     cout << "\n\nHasTime: " << HasTime << endl;
     cout << "HasDay: " << HasDay << endl;
     cout << "HasTimeDay: " << HasTimeDay << endl;

	 cout << "Theday: " << Theday << endl;

	 cout<< "**sizeof(Theday)"<< sizeof(Theday);
	 cout<< "**sizeOfDay"<< sizeOfDay;
     /*cout << "Thetime SIZE :" << strlen(inputTime) << endl;
     
     cout << "\ninputTime: " << inputTime << endl;
     cout << "Theday: " << Theday << endl;
     cout << "Thetime: " << Thetime << endl;
     cout << "\nTheday SIZE :" << strlen(inputTime) << endl;
     
     
      cout<<  endl<< "hh:mm"<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;

	 cout<< "**sizeOfTime"<< sizeof(Theday);
	 */


    if (HasTime)
    {
        if (sizeOfTime < 4) //the format: HMM
        {
            hour[0] = '0';
            hour[1] = Thetime[0];
            minute[0] = Thetime[1];
            minute[1] = Thetime[2];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }else if(sizeOfTime < 5) //the format: HHMM
        {
            hour[0] = Thetime[0];
            hour[1] = Thetime[1];
            minute[0] = Thetime[2];
            minute[1] = Thetime[3];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }else if(sizeOfTime < 6 && (Thetime[2]==58||Thetime[2]==46)) //the format: HH:MM
        {
            hour[0] = Thetime[0];
            hour[1] = Thetime[1];
            minute[0] = Thetime[3];
            minute[1] = Thetime[4];
            //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
        }
        else
        {
            if(Thetime[sizeOfTime-1] == 'h') //the format: XX:XXh XX:.XXh XXXXh
            {
                hour[0] = Thetime[0];
                hour[1] = Thetime[1];
                minute[0] = Thetime[sizeOfTime-3];
                minute[1] = Thetime[sizeOfTime-2];
                //cout<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
            }
            else if(Thetime[sizeOfTime-1] == 'm') //the format:am/apm
            {
                if(Thetime[sizeOfTime-2] == 'a') //the format: XX:XXam XX:.XXam XXXXam
                {
                    hour[0] = Thetime[0];
                    hour[1] = Thetime[1];
                    minute[0] = Thetime[sizeOfTime-4];
                    minute[1] = Thetime[sizeOfTime-3];
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
                    minute[0] = Thetime[sizeOfTime-4];
                    minute[1] = Thetime[sizeOfTime-3];
                    //cout<< hour[0] << hour[1] << ":" << minute[0] <<minute[1] << endl;
                }
            }
        }
    }
   //sizeof(Theday)
	   //sizeOfDay
    if (HasDay){
        int i=0;
        int j=0;
        int number=0;
        for(int x=0;x<sizeOfDay;x++)
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
                if (sizeOfDay==3)
                {
                    day[0] = '0';
                    day[1] = Theday[0];
                    month[0] = '0';
                    month[1] = Theday[2];
                }
                else if(sizeOfDay==4)
                {
                    day[0] = '0';
                    day[1] = Theday[0];
                    month[0] = Theday[2];
                    month[1] = Theday[3];
                }
            }
            else if(i==2)
            {
                if (sizeOfDay==4)
                {
                    day[0] = Theday[0];
                    day[1] = Theday[1];
                    month[0] = '0';
                    month[1] = Theday[3];
                }
                else if(sizeOfDay==5)
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
                year[0] = Theday[sizeOfDay-4];
                year[1] = Theday[sizeOfDay-3];
                year[2] = Theday[sizeOfDay-2];
                year[3] = Theday[sizeOfDay-1];
                
                temp[0]=Theday[1];
                temp[1]=Theday[2];
                temp[2]=Theday[3];  
            }
            else if(i==2)
            {
                day[0] = Theday[0];
                day[1] = Theday[1];
                year[0] = Theday[sizeOfDay-4];
                year[1] = Theday[sizeOfDay-3];
                year[2] = Theday[sizeOfDay-2];
                year[3] = Theday[sizeOfDay-1];
                
                temp[0]=Theday[2];
                temp[1]=Theday[3];
                temp[2]=Theday[4];
            }
           
			if ( (temp[0]=='J' )||(temp[0]=='j') )
			{
				if ( (temp[1]=='A' )||(temp[1]=='a') )
				{
					month[0] = '0';
					month[1] = '3';
				}
				else if ( (temp[2]=='L') ||(temp[2]=='l') )
				{
					month[0] = '0';
					month[1] = '7';
				}
				else
				{
					month[0] = '0';
					month[1] = '6';
				}
			}
			else if ( (temp[0]=='F' )||(temp[0]=='f') )
			{
				month[0] = '0';
				month[1] = '2';
			}
			else if ( (temp[0]=='M') ||(temp[0]=='m') )
			{
				if ( (temp[2]=='R') ||(temp[2]=='r') )
				{
					month[0] = '0';
					month[1] = '3';
				}
				else
				{
					month[0] = '0';
					month[1] = '5';
				}
			}
			else if ( (temp[0]=='A') ||(temp[0]=='a') )
			{
				if ( (temp[1]=='P') ||(temp[1]=='p') )
				{
					month[0] = '0';
					month[1] = '4';
				}
				else
				{
					month[0] = '0';
					month[1] = '8';
				}
			}
			else if ( (temp[0]=='S') ||(temp[0]=='s') )
			{
				month[0] = '0';
                month[1] = '9';
			}
			else if ( (temp[0]=='O') ||(temp[0]=='o') )
			{
				month[0] = '1';
                month[1] = '0';
			}
			else if ( (temp[0]=='N' )||(temp[0]=='n') )
			{
				month[0] = '1';
                month[1] = '1';
			}
			else if ( (temp[0]=='D') ||(temp[0]=='d') )
			{
				month[0] = '1';
                month[1] = '2';
			}



            
            //cout<< "dd/mm/yyyy :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1]<<"/"<<year[0]<<year[1] <<year[2]<<year[3]<< endl;
            
        }
        
        
    }
   // cout<<  endl<< "hh:mm"<<  hour[0] <<  hour[1] << ":" << minute[0] <<minute[1] << endl;
   // cout<< "dd/mm/yyyy :"<<day[0]<<day[1]<<"/"<<month[0]<<month[1]<<"/"<<year[0]<<year[1] <<year[2]<<year[3]<< endl;
    
    
    
    
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
    cout <<  endl << "TransformTime ::output" << output << endl;
    return output;
    
}






