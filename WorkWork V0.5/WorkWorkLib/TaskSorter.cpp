//@author A0105476E

//**************************************************************
//					  Author: AI YUE
//
//					File: TaskSorter.cpp
//**************************************************************

#include <algorithm>
#include "TaskSorter.h"

const int MAX_TIME_STRING = 13;		//for yyyymmddhhmm

TaskSorter::TaskSorter(void){
}

//the compare2Task is the compare method used by stable_sort algorithm
bool compare2Task(WWTask task_1, WWTask task_2){

	//done tasks sorted after undone tasks
	if((task_1.getStatus()) && (!task_2.getStatus())){                          
		return false;
	} else if ((!task_1.getStatus()) && (task_2.getStatus())){
		return true;
	} else if ((task_1.getStatus()) && (task_2.getStatus())){
		return false;
	} else if((!task_1.getStatus()) && (!task_2.getStatus())){

		//for undone tasks
		//floating tasks sorted after timed and deadline tasks
		if((task_1.getTaskType() == WWUtilities::FLOATING) && (task_2.getTaskType() != WWUtilities::FLOATING)){                //floating sorted after timed
			return false;															
		} else if ((task_1.getTaskType() != WWUtilities::FLOATING) && (task_2.getTaskType() == WWUtilities::FLOATING)){
			return true;
		} else if ((task_1.getTaskType() == WWUtilities::FLOATING) && (task_2.getTaskType() == WWUtilities::FLOATING)){
			return false;
		} else if((task_1.getTaskType() != WWUtilities::FLOATING) && (task_2.getTaskType() != WWUtilities::FLOATING)){
			
			//for timed and deadline tasks
			//they are sorted by time, where the start time a timed task is used
			char taskTime1[MAX_TIME_STRING];
			char taskTime2[MAX_TIME_STRING];

			sprintf_s(taskTime1, (task_1.getStartDate() + task_1.getStartTime()).c_str());
			sprintf_s(taskTime2, (task_2.getStartDate() + task_2.getStartTime()).c_str());

			int i = 0;
			while(taskTime1[i] != '\0'){
				while(taskTime2[i] != '\0'){
					if(taskTime1[i] < taskTime2[i]){
						return true;
					} else if(taskTime1[i] > taskTime2[i]){
						return false;
					}
					i++;
				}
				return false;
			}
			return false;
		}
	}
	return false;
}

void TaskSorter::sortTask(std::vector<WWTask>& taskList){
	stable_sort(taskList.begin(), taskList.end(), compare2Task);
}
