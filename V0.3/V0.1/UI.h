

#ifndef UI_H
#define UI_H


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Logic.h"

using namespace std;

class UI{

private:

	Logic logic;

	static const string WELCOME_MESSAGE;
public:

	UI();
	~UI();
	string getUserCommand();
	void main();

};

#endif