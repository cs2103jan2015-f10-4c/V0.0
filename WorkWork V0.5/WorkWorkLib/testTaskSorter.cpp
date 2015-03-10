//@author A0105476E

//**************************************************************
//			    Unit Test: TaskSorter Class
//					  Author: AI YUE
//
//			      File: testTaskSorter.cpp
//**************************************************************

#include "stdafx.h"
#include "CppUnitTest.h"
#include "WWTask.h"
#include "TaskSorter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest{
	TEST_CLASS(testTaskSorter){
public:

	TEST_METHOD(test_sort_of_two_timed_task){
		TaskSorter taskSorter = TaskSorter::getInstance();
		std::vector<WWTask> testTaskList;
		WWTask testTemp;
		std::string expectedTaskName1;
		std::string expectedTaskName2;

		//arrange

		//testTaskList[0]: Timed Task 2; 20140404 0800; 20140405 0800; undone
		testTemp.setTaskName("Timed Task 2");
		testTemp.setStartDate("20140404");
		testTemp.setStartTime("0800");
		testTemp.setEndDate("20140405");
		testTemp.setEndTime("0800");
		testTaskList.push_back(testTemp);
		//testTaskList[1]: Timed Task 1; 20140404 0600; 20140405 1800; undone
		testTemp.setTaskName("Timed Task 1");
		testTemp.setStartDate("20140404");
		testTemp.setStartTime("0600");
		testTemp.setEndDate("20140405");
		testTemp.setEndTime("1800");
		testTaskList.push_back(testTemp);

		expectedTaskName1 = "Timed Task 1";
		expectedTaskName2 = "Timed Task 2";

		//act
		taskSorter.sortTask(testTaskList);

		//assert
		Assert::AreEqual(expectedTaskName1, testTaskList[0].getTaskName());
		Assert::AreEqual(expectedTaskName2, testTaskList[1].getTaskName());
	}

	TEST_METHOD(test_sort_of_two_deadline_task){
		TaskSorter taskSorter = TaskSorter::getInstance();
		std::vector<WWTask> testTaskList;
		WWTask testTemp;
		std::string expectedTaskName1;
		std::string expectedTaskName2;

		//arrange

		////testTaskList[0]: Deadline Task 2;				;20140503 1800; undone 
		testTaskList.push_back(testTemp);			
		testTemp.setTaskName("Deadline Task 2");
		testTemp.setStartDate("20140503");
		testTemp.setStartTime("1800");
		testTaskList.push_back(testTemp);			
		//testTaskList[1]: Deadline Task 2;				;20140502 1800; undone
		testTemp.setTaskName("Deadline Task 1");
		testTemp.setStartDate("20140502");
		testTemp.setStartTime("1800");
		testTaskList.push_back(testTemp);	

		expectedTaskName1 = "Deadline Task 1";
		expectedTaskName2 = "Deadline Task 2";

		//act
		taskSorter.sortTask(testTaskList);

		//assert
		Assert::AreEqual(expectedTaskName1, testTaskList[0].getTaskName());
		Assert::AreEqual(expectedTaskName2, testTaskList[1].getTaskName());
	}

	TEST_METHOD(test_sort_of_timed_and_deadline_and_floating_task){
		TaskSorter taskSorter = TaskSorter::getInstance();
		std::vector<WWTask> testTaskList;
		WWTask testTemp;
		std::string expectedTaskName1;
		std::string expectedTaskName2;
		std::string expectedTaskName3;

		//arrange

		//testTaskList[0]: Floating Task;				;				; undone
		testTemp.setTaskName("Floating Task");
		testTemp.setStartDate("");
		testTemp.setStartTime("");
		testTemp.setEndDate("");
		testTemp.setEndTime("");
		testTaskList.push_back(testTemp);
		//testTaskList[1]: Deadline Task;				;20140503 1800; undone 
		testTaskList.push_back(testTemp);			
		testTemp.setTaskName("Deadline Task");
		testTemp.setStartDate("20140503");
		testTemp.setStartTime("1800");
		testTaskList.push_back(testTemp);	
		//testTaskList[2]: Timed Task; 20140404 0800; 20140405 0800; undone
		testTemp.setTaskName("Timed Task 2");
		testTemp.setStartDate("20140404");
		testTemp.setStartTime("0800");
		testTemp.setEndDate("20140405");
		testTemp.setEndTime("0800");
		testTaskList.push_back(testTemp);

		expectedTaskName1 = "Timed Task";
		expectedTaskName2 = "Deadline Task";
		expectedTaskName3 = "Floating Task";

		//act
		taskSorter.sortTask(testTaskList);

		//assert
		Assert::AreEqual(expectedTaskName1, testTaskList[0].getTaskName());
		Assert::AreEqual(expectedTaskName2, testTaskList[1].getTaskName());
		Assert::AreEqual(expectedTaskName3, testTaskList[2].getTaskName());
	}

	TEST_METHOD(test_sort_of_done_and_undone_task){
		TaskSorter taskSorter = TaskSorter::getInstance();
		std::vector<WWTask> testTaskList;
		WWTask testTemp;
		std::string expectedTaskName1;
		std::string expectedTaskName2;

		//arrange
		//testTaskList[0]: Done Timed Task; 20140404 0900; 20140404 1800; done
		testTemp.setTaskName("Done Timed Task");
		testTemp.setStartDate("20140404");
		testTemp.setStartTime("0900");
		testTemp.setEndDate("20140404");
		testTemp.setEndTime("1800");
		testTemp.setStatus("true");
		testTaskList.push_back(testTemp);			
		//testTaskList[1]: Undone Timed Task; 20140404 0600; 20140405 1800; undone
		testTemp.setTaskName("Undone Timed Task");
		testTemp.setStartDate("20140404");
		testTemp.setStartTime("0600");
		testTemp.setEndDate("20140405");
		testTemp.setEndTime("1800");
		testTaskList.push_back(testTemp);


		expectedTaskName1 = "Undone Timed Task";
		expectedTaskName2 = "Done Timed Task";

		//act
		taskSorter.sortTask(testTaskList);

		//assert
		Assert::AreEqual(expectedTaskName1, testTaskList[0].getTaskName());
		Assert::AreEqual(expectedTaskName2, testTaskList[1].getTaskName());
	}
	};
}