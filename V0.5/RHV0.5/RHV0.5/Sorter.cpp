

#include "Sorter.h"
#include "TransformTime.h"
#include <assert.h>

//@author A0116363L-reused
//This is the sorting algorithm for alphabets
bool cmpName(Task a, Task b){

	unsigned i = 0;
	while ((i < a.taskName.length()) && (i < b.taskName.length()))
	{
		if (tolower(a.taskName[i]) < tolower(b.taskName[i])) 
			return true;
		else if (tolower(a.taskName[i]) > tolower(b.taskName[i])) 
			return false;
		i++;
	}

	if (a.taskName.length() < b.taskName.length()) 
		return true;
	else 
		return false;
}
//@author A0116363L
//This is the sorting algorithm for ending time
bool cmpEndingTime(Task a, Task b){

	TransformTime time;
	time_t timeA = time.stringToTime(a.endingTime);
	time_t timeB = time.stringToTime(b.endingTime);
	if (timeA < timeB){
		return true;
	}
	else {
		return false;
	}

}


//This is the sorting algorithm for starting time
bool cmpStartingTime(Task a, Task b){

	TransformTime time;
	time_t timeA = time.stringToTime(a.startingTime);
	time_t timeB = time.stringToTime(b.startingTime);
	if (timeA < timeB){
		return true;
	}
	else {
		return false;
	}

}


vector<Task> Sorter::sortFloatingTaskList(vector<Task> tasklist){

	sort(tasklist.begin(), tasklist.end(), cmpName);
	for (unsigned i = 1; i < tasklist.size() ; i++){
		assert(tasklist[i-1].taskName < tasklist[i].taskName);
		//make sure the list is properly sorted
	}
	return tasklist;
}

vector<Task> Sorter::sortDeadlineTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpEndingTime);
	for (unsigned i = 1; i < tasklist.size(); i++){
		assert(tasklist[i-1].endingTime < tasklist[i].endingTime);
		//make sure the list is properly sorted
	}
	return tasklist;
}

vector<Task> Sorter::sortTimedTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpStartingTime);
	for (unsigned i = 1; i < tasklist.size(); i++){
		assert(tasklist[i-1].startingTime < tasklist[i].startingTime);
		//make sure the list is properly sorted
	}
	return tasklist;
}


vector<Task> Sorter::sortOverdueTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	for (unsigned i = 1; i < tasklist.size(); i++){
		assert(tasklist[i-1].taskName < tasklist[i].taskName);
		//make sure the list is properly sorted
	}
	return tasklist;
}


vector<Task> Sorter::sortDoneTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	for (unsigned i = 1; i < tasklist.size(); i++){
		assert(tasklist[i-1].taskName < tasklist[i].taskName);
		//make sure the list is properly sorted
	}
	return tasklist;
}

vector<Task> Sorter::sortOngoingTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	for (unsigned i = 1; i < tasklist.size(); i++){
		assert(tasklist[i-1].taskName < tasklist[i].taskName);
		//make sure the list is properly sorted
	}
	return tasklist;
}