#include <iostream>
#include "WWUtilities.h"

using namespace std;

int main() {
	WWUtilities& UtiTest = WWUtilities::getInstance();
	
	WWUtilities::CommandType thisIsACommandType = WWUtilities::ADD;

	if(thisIsACommandType == WWUtilities::ADD) {
		cout << "yes commandtype is add" << endl;
	}
	if(thisIsACommandType == WWUtilities::DELETE) {
		cout << "no commandtype is add" << endl;
	} else {
		cout << "yes commandtype is not delete" << endl;
	}

	WWUtilities::TaskType thisIsATaskType = WWUtilities::FLOATING;

	if(thisIsATaskType == WWUtilities::FLOATING) {
		cout << "yes tasktype is floating" << endl;
	}
	if(thisIsATaskType == WWUtilities::DEADLINE) {
		cout << "no tasktype is floating" << endl;
	} else {
		cout << "yes tasktype is not deadline" << endl;
	}

	WWUtilities::PageType thisIsAPageType = WWUtilities::PAGEOVERDUE;

	if(thisIsAPageType == WWUtilities::PAGEOVERDUE) {
		cout << "yes pagetype is overdue" << endl;
	}
	if(thisIsAPageType == WWUtilities::PAGETODAY) {
		cout << "no pagetype is overdue" << endl;
	} else {
		cout << "yes pagetype is not today" << endl;
	}
/*
	string monthString;
	int monthInt;

	while(true) {
		cin >> monthString;
		cout << UtiTest.stringToIntMonth(monthString) << endl;
		//cin >> monthInt;
		//cout << UtiTest.intToStringMonth(monthInt) << endl;
	}
*/

	cout << "current date is: " << UtiTest.getCurrentDay() << UtiTest.getCurrentMonth() << UtiTest.getCurrentYear() << endl;
	cout << "current time is: " << UtiTest.getCurrentHour() << UtiTest.getCurrentMinute() << endl;

	system("pause");
	return 0;
}