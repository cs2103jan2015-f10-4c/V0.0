//parser is used to process user input before it is used for furthur operations



#ifndef PARSER_H
#define PARSER_H 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Logic.h"

using namespace std;

class Parser{
private:

public:

	 Parser();

     time_t strToDateTime(char[], char[]);

};

#endif