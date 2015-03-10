#ifndef Task_H_
#define Task_H_

#include <iostream>
#include <string>

using namespace std; 

class Task{

public:
	string taskDescription;
	string startingTime;
	string endingTIme;
	string date;
	
	Task();
	~Task();

};

#endif