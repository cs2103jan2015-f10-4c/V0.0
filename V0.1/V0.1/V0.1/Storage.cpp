#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include "Storage.h"
#include "Task.h"

using namespace std;

const string TEXTFILENAME = "rushhour.txt";

void Storage::storeTask(string task, string startingTime, string endingTime){
	Task tempStorage;
	tempStorage.taskName = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTime = endingTime;
	//tempStorage.date = date;
	taskList.push_back(tempStorage);
};

void Storage::updateTaskList(vector<Task> taskStorage){
	taskList = taskStorage;
};

void Storage::saveFile(string TEXTFILENAME){
	ofstream writeFile;
	writeFile.open(TEXTFILENAME.c_str());
	for (int i = 0; i < taskList.size(); i++){
		writeFile << i + 1 << ".";
		writeFile << taskList[i].taskName << "from";
		//writeFile << taskList[i].date;
		writeFile << taskList[i].startingTime << "to";
		writeFile << taskList[i].endingTime << endl;
	}
	writeFile.close();
};

vector<Task> Storage::getTaskList(){
	return taskList;
};

