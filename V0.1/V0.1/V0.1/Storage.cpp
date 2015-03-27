#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
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

void Storage::undo(){
	taskList = historyStorage.undo();
}

void Storage::redo(){
	taskList = historyStorage.redo();
}

void Storage::saveOperation(){
	historyStorage.saveOperation(taskList);
}

void Storage::updateTaskList(vector<Task> taskStorage){
	taskList = taskStorage;
};

//void Storage::updateDeadlineTaskList(vector<Task> deadlineTaskStorage){
//	deadlineTaskList = deadlineTaskStorage;
//};
//
//void Storage::updateFloatingTaskList(vector<Task> floatingTaskStorage){
//	floatingTaskList = floatingTaskStorage;
//};

void Storage::saveFile(){
	ofstream writeFile(TEXTFILENAME);
	

	writeFile << " Tasklist:" << endl;
	for (int i = 0; i < taskList.size(); i++){
		
		if(taskList[i].type == "timed"){
			writeFile << i + 1 << ". ";
			writeFile << taskList[i].taskName << " ; ";
			writeFile << taskList[i].startingTime << " ; ";
			writeFile << taskList[i].endingTime << " ; ";
			writeFile << taskList[i].status << endl;
		}
		if(taskList[i].type == "deadline"){
			writeFile << i + 1 << ". ";
			writeFile << taskList[i].taskName << " ; ";
			writeFile << taskList[i].startingTime << " ; ";
			writeFile << taskList[i].status << endl;
		}
		if(taskList[i].type == "floating"){
			writeFile << i + 1 << ". ";
			writeFile << taskList[i].taskName << " ; ";
			writeFile << taskList[i].status << endl;
		}
		
	}
	
	/*writeFile << "Deadline Tasklist:" << endl;
	for (int i = 0; i < deadlineTaskList.size(); i++){
		writeFile << i + 1 << ". ";
		writeFile << deadlineTaskList[i].taskName << " ; ";
		writeFile << deadlineTaskList[i].startingTime << " ; ";
		writeFile << deadlineTaskList[i].status << endl;
	}

	writeFile << " Floating Tasklist:" << endl;
	for (int i = 0; i < floatingTaskList.size(); i++){
		writeFile << i + 1 << ". ";
		writeFile << floatingTaskList[i].taskName << " ; ";
		writeFile << floatingTaskList[i].status << endl;
	}*/
	
	writeFile.close();
};

//vector<Task> Storage::getOverallTaskList(){
//	overallTaskList.reserve(taskList.size() + deadlineTaskList.size() + floatingTaskList.size());
//	overallTaskList.insert(overallTaskList.end(), taskList.begin(), taskList.end());
//	overallTaskList.insert(overallTaskList.end(), deadlineTaskList.begin(), deadlineTaskList.end());
//	overallTaskList.insert(overallTaskList.end(), floatingTaskList.begin(), floatingTaskList.end());
//	
//	return overallTaskList; 
//}

vector<Task> Storage::getTaskList(){
	return taskList;
};

vector<Task> Storage::getTimedTaskList(){
	return timedTaskList;
};

vector<Task> Storage::getDeadlineTaskList(){
	return deadlineTaskList;
};

vector<Task> Storage::getFloatingTaskList(){
	return floatingTaskList;
};


void Storage::readFile(){
	ifstream file;
	string taskLine;
	string titleLine;

	tempTask.clear();
	file.open(TEXTFILENAME);

	getline(file, titleLine);
	
	while (getline(file, taskLine)){
		tempTask.push_back(taskLine);
		
		loadTask(tempTask);
	}

	
	file.close();
}

void Storage::loadTask (vector<string> taskLine){

	for (int i = 0; i<taskLine.size(); i++){
		
		string line = taskLine[i];
		string taskDetail = removeIndex(line);
		
		int numberOfDelimiter = count(taskDetail.begin(), taskDetail.end(), ';');

		if (numberOfDelimiter == 3){
	
			string taskName = getTaskName(taskDetail);
			string startingTime = getStartingTime(taskDetail);
			string endingTime = getEndingTime(taskDetail);
			string status = getStatus(taskDetail);
			string taskType = "timed";

			Task taskStorage;
			taskStorage.setTaskName(taskName);
			taskStorage.setStartingTime(startingTime);
			taskStorage.setEndingTime(endingTime);
			taskStorage.setDone(status);
			taskStorage.setType(taskType);

			taskList.push_back(taskStorage);
			timedTaskList.push_back(taskStorage);
		}
		if (numberOfDelimiter == 2){

			string taskName = getTaskName(taskDetail);
			string dueTime = getDueTime(taskDetail);
			string status = getStatus(taskDetail);
			string endTime = "";
			string taskType = "deadline";

			Task taskStorage;
			taskStorage.setTaskName(taskName);
			taskStorage.setStartingTime(dueTime);
			taskStorage.setDone(status);
			taskStorage.setEndingTime(endTime);
			taskStorage.setType(taskType);

			taskList.push_back(taskStorage);
			deadlineTaskList.push_back(taskStorage);
		}
		if (numberOfDelimiter == 1){

			string taskName = getTaskName(taskDetail);
			string status = getStatus(taskDetail);
			string startingTime = "";
			string endingTime = "";
			string taskType = "floating";

			Task taskStorage;
			taskStorage.setTaskName(taskName);
			taskStorage.setDone(status);
			taskStorage.setStartingTime(startingTime);
			taskStorage.setEndingTime(endingTime);
			taskStorage.setType(taskType);

			taskList.push_back(taskStorage);
			floatingTaskList.push_back(taskStorage);
		}

}

}

string Storage::removeIndex(string input){
	size_t positionStart = 0;
    size_t positionEnd = input.size();
    string task;
    positionStart = input.find_first_of(".");
    task = input.substr(positionStart, positionEnd - positionStart);
    return task;
}

string Storage::getTaskName(string input){
	size_t positionStart = 0;
	size_t positionEnd = 0;
	string task;
	positionEnd = input.find_first_of(";");
	task = input.substr(positionStart, positionEnd - positionStart);
	return task;
}

string Storage::getStartingTime(string input){
	size_t p1 = 0;
	size_t p2 = input.size();
	size_t p3 = 0;
	string task;
	p1 = input.find_first_of(";") + 1;
	string temp = input.substr(p1, p2-p1);
	p3 = temp.find_first_of(";");
	p1 =0;
	task = temp.substr(p1, p3-p1);
	return task;

}

string Storage::getEndingTime(string input){
	size_t p1 = 0;
	size_t p2 = 0;
	size_t p3 = 0;
	size_t p4 = input.size();
	p1 = input.find_first_of(";") + 1;
	string temp = input.substr(p1, p4-p1);
	p2 = temp.find_first_of(";") + 1;
	p4 = temp.size();
	string temp2 = temp.substr(p2, p4-p2);
	p3 = temp2.find_first_of(";");
	p1 = 0;
	string task = temp2.substr(p1, p3-p1);
	return task;
}

string Storage::getStatus(string input){
	size_t p1 = 0;
	size_t p2 = input.size();
	p1 = input.find_last_of(";") + 1;
	string task = input.substr(p1,p2-p1);
	return task;
}

string Storage::getDueTime(string input){
	size_t p1 = 0;
	size_t p2 = input.size();
	size_t p3 = 0;
	string task;
	p1 = input.find_first_of(";") + 1;
	string temp = input.substr(p1, p2-p1);
	p3 = temp.find_first_of(";");
	p1 =0;
	task = temp.substr(p1, p3-p1);
	return task;
}

