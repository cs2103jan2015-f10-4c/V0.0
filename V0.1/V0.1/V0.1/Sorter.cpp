#include "Sorter.h"



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


}



bool cmpStartingTime(Task a, Task b){

}


vector<Task> Sorter::sortFloatingTaskList(vector<Task> tasklist){

	sort(tasklist.begin(), tasklist.end(), cmpName);
	return tasklist;
}

vector<Task> Sorter::sortDeadlineTaskList(vector<Task> tasklist){
	sort(tasklist.begin(), tasklist.end(), cmpEndingTime);
	return tasklist;
}