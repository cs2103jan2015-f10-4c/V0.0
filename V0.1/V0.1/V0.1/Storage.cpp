//@author A0114946B

#include <sstream>
#include <fstream>
#include <algorithm>
#include <sys/stat.h>
#include <assert.h>
#include "Storage.h"
#include "Task.h"
#include "Logger.h"

using namespace std;

const string SAVE_FILE_MSG = "file is saved successfully";
const string READ_FILE_MSG = "file is retrieved successfully";
const string CREATE_FILE_MSG = "new file is created successfully";
const string TEXT_FILE_NAME = "rushhour.txt";
const string CONFIG_FILE_NAME = "myAppConfig.txt";
const string FILE_TITLE = " Tasklist: ";
const string DEFAULT_TIMED_TASK_TYPE = "timed";
const string DEFAULT_DEADLINE_TASK_TYPE = "deadline";
const string DEFAULT_FLOATING_TASK_TYPE = "floating";
const string INDEX_SPACER = ". ";
const string TASK_SPACER = " ; ";
const string DEFAULT_NO_TYPE_TASK_MSG = "Task has not been typed";
const string NEW_FILE_MSG = "Welcome";
const string INDEX_SEPERATOR = ".";
const string TASK_SEPERATOR = ";";
const char filePathSeparator =
#ifdef _WIN32
	'\\';
#else
	'/';
#endif


//constructor
Storage::Storage(){
}

//destructor
Storage::~Storage(){
}

///////////////////
// Getter Method //
///////////////////
string Storage::getOutfilePath(){
	return _outFilePath;
}

string Storage::getUserInputPath(){
	return _userInputPath;
}


///////////////////
// Setter Method //
///////////////////
void Storage::setOutFilePath(string outFilePath){
	_outFilePath = outFilePath;
}

//used to set user key-in input received by Logic as file path to be saved 
void Storage::setUserInputPath(string userInputPath){
	_userInputPath = userInputPath;
}

//check whether there is an existing file path for save .txt file in a Configuration file
//return true if file path is stored in the Configuration file and get the fiil path 
//return false if no file path stored in the Configuration file
bool Storage::hasDirectory(){
	bool directory = false;
	
	//this is the Configuration file, inside should only store one line, the file path to actual save .txt file
	string configPath = CONFIG_FILE_NAME; 
	
	ifstream configIn (configPath.c_str());
	if (configIn.is_open()){
		
		directory = true;
		assert(directory == true);
		
		//get and store the file path
		string line;
		if ( getline (configIn,line) )
		{
			_outFilePath = line;
		}
		configIn.close();
		
	}
	else{
		directory = false;
		assert(directory == false);
	}
	return directory;
}

//to save taskList passed from Logic by reference
//taskList is saveed after every operation, the current overwrites the previous taskList in the .txt file
//taskList is saved in user-defined location which stored in _outFilePath
void Storage::saveFile(vector<Task>& taskList){
	
	RHLogger logFile = RHLogger::getInstance();
	string filePath = getOutfilePath();
	
	//write file into user-defined location
	ofstream writeFile;
	writeFile.open(filePath.c_str());

	writeFile << FILE_TITLE << endl;

	for (unsigned i = 0; i < taskList.size(); i++){
		
		if(taskList[i].type == DEFAULT_TIMED_TASK_TYPE){
			writeFile << i + 1 << INDEX_SPACER;
			writeFile << taskList[i].taskName << TASK_SPACER;
			writeFile << taskList[i].startingTime << TASK_SPACER;
			writeFile << taskList[i].endingTime << TASK_SPACER;
			writeFile << taskList[i].status << endl;
		}
		else if(taskList[i].type == DEFAULT_DEADLINE_TASK_TYPE){
			writeFile << i + 1 << INDEX_SPACER;
			writeFile << taskList[i].taskName << TASK_SPACER;
			writeFile << taskList[i].endingTime << TASK_SPACER;
			writeFile << taskList[i].status << endl;
		}
		else if(taskList[i].type == DEFAULT_FLOATING_TASK_TYPE){
			writeFile << i + 1 << INDEX_SPACER;
			writeFile << taskList[i].taskName << TASK_SPACER;
			writeFile << taskList[i].status << endl;
		}
		else{
			writeFile << DEFAULT_NO_TYPE_TASK_MSG << endl;
		}
		
	}
	
	logFile.addLog(SAVE_FILE_MSG);
	logFile.saveLog();
	writeFile.close();
}

//to retrieve file from local .txt file if there is existing file
//to create new file at given directory if there is no existing file
void Storage::readFile(vector<Task>& taskList){
	
	string filePath;
	vector<string> tempTask;
	RHLogger logFile = RHLogger::getInstance();
	
	//there is an existing file
	if(hasDirectory() == true){
		
		assert(hasDirectory() == true);
		filePath = getOutfilePath();
		
		ifstream file;
		string taskLine;
		string titleLine;

		file.open(filePath.c_str());
		tempTask.clear();
		
		//remove the tile line at start of .txt file
		getline(file, titleLine);
		
		//get each line as one whole string
		while (getline(file, taskLine)){
			tempTask.push_back(taskLine);
		}
		
		//partition the whole string accordingly and pass to Logic to store in taskList
		loadTask(tempTask, taskList);

		logFile.addLog(READ_FILE_MSG);
		logFile.saveLog();
		file.close();
	}
	//there is no existing file
	else{
		assert(hasDirectory() == false);
		string filePath = createFilePath();
		
		ofstream outputFile;
		outputFile.open(filePath.c_str());
		outputFile << NEW_FILE_MSG;

		logFile.addLog(CREATE_FILE_MSG);
		logFile.saveLog();
		outputFile.close();
	}
	
}

//create new file at user-defined location 
//save the user-defined file path into the Configuration file for future retrival use
string Storage::createFilePath(){
		
		string configPath = CONFIG_FILE_NAME; 
		
		//combine the user giving directory and defaul text file name to the actual file path
		string pathname;
		pathname = getUserInputPath();
		_outFilePath = pathname + filePathSeparator+ TEXT_FILE_NAME;

		// save this file path to the configuration file
		ofstream configOut;
		configOut.open(configPath.c_str());
		configOut << _outFilePath;
		configOut.close();

		return _outFilePath;

}


//partition every taskline into different components 
//taskList is passed by reference from Logic
//all valid tasks will be retrieved and categorised 
void Storage::loadTask (vector<string> taskLineList, vector<Task>& taskList){

	for (unsigned i = 0; i<taskLineList.size(); i++){
		
		//get each task string line and remove the display index
		string line = taskLineList[i];
		string taskDetail = removeIndex(line);
		
		int numberOfDelimiter = count(taskDetail.begin(), taskDetail.end(), ';');

		if (numberOfDelimiter == 3){
			retrieveTimedTask(taskDetail, taskList);
		}
		else if (numberOfDelimiter == 2){
			retrieveDeadlineTask(taskDetail, taskList);
		}
		else if (numberOfDelimiter == 1){
			retrieveFloatingTask(taskDetail, taskList);
		}
		else{
			string trashLine = taskDetail;
		}
	}
}

void Storage::retrieveTimedTask(string taskDetail, vector<Task>& taskList){
	string taskName = getTaskName(taskDetail);
	string startingTime = getStartingTime(taskDetail);
	string endingTime = getEndingTime(taskDetail);
	string status = getStatus(taskDetail);
	string taskType = DEFAULT_TIMED_TASK_TYPE;

	Task taskStorage;
	taskStorage.setTaskName(taskName);
	taskStorage.setStartingTime(startingTime);
	taskStorage.setEndingTime(endingTime);
	taskStorage.setDone(status);
	taskStorage.setType(taskType);

	taskList.push_back(taskStorage);
}

void Storage::retrieveDeadlineTask(string taskDetail, vector<Task>& taskList){
	string taskName = getTaskName(taskDetail);
	string dueTime = getDueTime(taskDetail);
	string status = getStatus(taskDetail);
	string startTime = "";
	string taskType = DEFAULT_DEADLINE_TASK_TYPE;

	Task taskStorage;
	taskStorage.setTaskName(taskName);
	taskStorage.setStartingTime(startTime);
	taskStorage.setDone(status);
	taskStorage.setEndingTime(dueTime);
	taskStorage.setType(taskType);

	taskList.push_back(taskStorage);
}

void Storage::retrieveFloatingTask(string taskDetail, vector<Task>& taskList){
	string taskName = getTaskName(taskDetail);
	string status = getStatus(taskDetail);
	string startingTime = "";
	string endingTime = "";
	string taskType = DEFAULT_FLOATING_TASK_TYPE;

	Task taskStorage;
	taskStorage.setTaskName(taskName);
	taskStorage.setDone(status);
	taskStorage.setStartingTime(startingTime);
	taskStorage.setEndingTime(endingTime);
	taskStorage.setType(taskType);

	taskList.push_back(taskStorage);
}
			
string Storage::removeIndex(string input){
	size_t positionStart = 0;
    size_t positionEnd = input.size();
    string taskDetail;
	positionStart = input.find_first_of(INDEX_SEPERATOR) + 1;
    taskDetail = input.substr(positionStart, positionEnd - positionStart);
    return taskDetail;
}

string Storage::getTaskName(string input){
	
	//start after the spacing at the beginning
	size_t positionStart = 1;
	size_t positionEnd = 0;
	string taskName;

	//get rid of the spacing before the first TASK_SEPERATOR
	positionEnd = input.find_first_of(TASK_SEPERATOR) - 1;
	taskName = input.substr(positionStart, positionEnd - positionStart);
	return taskName;
}

string Storage::getStartingTime(string input){
	size_t positionStart = 0;
	size_t positionMid = 0;
	size_t positionEnd = input.size();

	//remove the part of task name 
	positionStart = input.find_first_of(TASK_SEPERATOR) + 1;
	string temp = input.substr(positionStart, positionEnd-positionStart);
	
	//get the part of starting time
	string startTime;
	positionMid = temp.find_first_of(TASK_SEPERATOR)-1;
	positionStart = 1;
	startTime = temp.substr(positionStart, positionMid-positionStart);
	
	return startTime;

}

string Storage::getEndingTime(string input){
	size_t positionStart = 0;
	size_t positionMid1 = 0;
	size_t positionMid2 = 0;
	size_t positionEnd = input.size();

	//remove part of task name
	positionStart = input.find_first_of(TASK_SEPERATOR) + 1;
	string temp = input.substr(positionStart, positionEnd-positionStart);

	//remove part of starting time
	positionMid1 = temp.find_first_of(TASK_SEPERATOR) + 1;
	positionEnd = temp.size();
	string temp2 = temp.substr(positionMid1, positionEnd-positionMid1);

	//get part of ending time
	positionMid2 = temp2.find_first_of(TASK_SEPERATOR)-1;
	positionStart = 1;
	string endTime = temp2.substr(positionStart, positionMid2-positionStart);
	return endTime;
}

string Storage::getStatus(string input){
	size_t positionStart = 0;
	size_t positionEnd = input.size();
	
	//start at the beginning of task status
	positionStart = input.find_last_of(TASK_SEPERATOR) + 2;
	string status = input.substr(positionStart, positionEnd-positionStart);
	return status;
}

string Storage::getDueTime(string input){
	size_t positionStart = 0;
	size_t positionMid = 0;
	size_t positionEnd = input.size();
	
	//remove the part of task name 
	positionStart = input.find_first_of(TASK_SEPERATOR) + 1;
	string temp = input.substr(positionStart, positionEnd-positionStart);
	
	//get the part of due time
	string dueTime;
	positionMid = temp.find_first_of(TASK_SEPERATOR)-1;
	positionStart = 1;
	dueTime = temp.substr(positionStart, positionMid-positionStart);
	
	return dueTime;
}



//void Storage::test(){
//	if (_taskList.empty()){
//		cout << "empty";// vector is now empty
//	}
//}
/*void Storage::storeTask(string task, string startingTime, string endingTime){
	Task tempStorage;
	tempStorage.taskName = task;
	tempStorage.startingTime = startingTime;
	tempStorage.endingTime = endingTime;
	//tempStorage.date = date;
	taskList.push_back(tempStorage);
};*/

//void Storage::undo(){
//	_taskList = historyStorage.undo();
//}
//
//void Storage::redo(){
//	_taskList = historyStorage.redo();
//}
//
//void Storage::saveOperation(){
//	historyStorage.saveOperation(_taskList);
//}

//void Storage::updateTaskList(vector<Task>& taskStorage){
//	_taskList.clear();
//	for (int i = 0; i < taskStorage.size(); i++){
//		_taskList.push_back(taskStorage[i]);
//	}
//	//cout << _taskList[0].taskName; //successful correctlly cout
//	test();
//};


//vector<Task> Storage::getOverallTaskList(){
//	overallTaskList.reserve(taskList.size() + deadlineTaskList.size() + floatingTaskList.size());
//	overallTaskList.insert(overallTaskList.end(), taskList.begin(), taskList.end());
//	overallTaskList.insert(overallTaskList.end(), deadlineTaskList.begin(), deadlineTaskList.end());
//	overallTaskList.insert(overallTaskList.end(), floatingTaskList.begin(), floatingTaskList.end());
//	
//	return overallTaskList; 
//}

//vector<Task> Storage::getTaskList(){
//	return _taskList;
//};
//
//vector<Task> Storage::getTimedTaskList(){
//	return timedTaskList;
//};
//
//vector<Task> Storage::getDeadlineTaskList(){
//	return deadlineTaskList;
//};
//
//vector<Task> Storage::getFloatingTaskList(){
//	return floatingTaskList;
//};