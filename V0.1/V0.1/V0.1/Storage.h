#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Storage.h"
#include "Task.h"

using namespace std;

void Storage::storeTask(string task, string startingTime, string endingTime,string date){
	Task tempStorage;
	tempStorage.taskName = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTime = endingTime;
	tempStorage.date = date;
	taskList.push_back(tempStorage);
};

void Storage::updateTaskList(vector<Task> taskStorage){
	taskList = taskStorage;
};

void Storage::saveFile(string textFileName){
	ofstream writeFile;
	writeFile.open(textFileName);
	for (int i = 0; i < taskList.size(); i++){
		writeFile << taskList[i].taskName;
		writeFile << taskList[i].date;
		writeFile << taskList[i].startingTime;
		writeFile << taskList[i].endingTime << endl;
	}
	writeFile.close();
};

vector<Task> Storage::getTaskList(){
	return taskList;
};

