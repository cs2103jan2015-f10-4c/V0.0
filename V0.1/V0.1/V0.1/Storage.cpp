#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Storage.h"
#include "Task.h"

using namespace std;

const string TEXTFILENAME = "rushhour.txt";

Storage::Storage(void){}
Storage::~Storage(void){}

/*void Storage::storeTask(string task, string startingTime, string endingTime){
	Task tempStorage;
	tempStorage.taskName = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTime = endingTime;
	//tempStorage.date = date;
	taskList.push_back(tempStorage);
};*/

void Storage::updateTaskList(vector<Task> taskStorage){
	taskList = taskStorage;
};

void Storage::updateDeadlineTaskList(vector<Task> deadlineTaskStorage){
	deadlineTaskList = deadlineTaskStorage;
};

void Storage::updateFloatingTaskList(vector<Task> floatingTaskStorage){
	floatingTaskList = floatingTaskStorage;
};

void Storage::saveFile(){
	ofstream writeFile(TEXTFILENAME);
	
	writeFile << " Normal Tasklist:" << endl;
	for (int i = 0; i < taskList.size(); i++){
		writeFile << i + 1 << ". ";
		writeFile << taskList[i].taskName << " from ";
		//writeFile << taskList[i].date;
		writeFile << taskList[i].startingTime << " to ";
		writeFile << taskList[i].endingTime << endl;
	}
	
	writeFile << " Deadline Tasklist:" << endl;
	for (int i = 0; i < deadlineTaskList.size(); i++){
		writeFile << i + 1 << ". ";
		writeFile << deadlineTaskList[i].taskName << " at ";
		//writeFile << taskList[i].date;
		writeFile << deadlineTaskList[i].startingTime << endl;
	}

	writeFile << " Floating Tasklist:" << endl;
	for (int i = 0; i < floatingTaskList.size(); i++){
		writeFile << i + 1 << ". ";
		writeFile << floatingTaskList[i].taskName << endl;
	}
	writeFile.close();
};

vector<Task> Storage::getTaskList(){
	return taskList;
};

vector<Task> Storage::getDeadlineTaskList(){
	return deadlineTaskList;
};

vector<Task> Storage::getFloatingTaskList(){
	return floatingTaskList;
};

void Storage::saveOperation(vector<Task> taskStorage){
	historyStorage.saveOperation(taskStorage);
};