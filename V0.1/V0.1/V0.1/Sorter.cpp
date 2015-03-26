#include "Sorter.h"
#include "TransformTime.h"


bool cmpName(Task a, Task b){
	int i = 0;
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
	return tasklist;
}

vector<Task> Sorter::sortDeadlineTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpEndingTime);
	return tasklist;
}

vector<Task> Sorter::sortTimedTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpStartingTime);
	return tasklist;
}


vector<Task> Sorter::sortOverdueTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	return tasklist;
}


vector<Task> Sorter::sortDoneTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	return tasklist;
}

vector<Task> Sorter::sortOngoingTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpName);
	return tasklist;
}