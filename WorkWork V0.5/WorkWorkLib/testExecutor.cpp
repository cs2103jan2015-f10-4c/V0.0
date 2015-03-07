//@author A0105476E

//***************************************************************
//			    Integration Test: WWExecutor
//					  Author: AI YUE
//
//			       File: testExecutor.cpp
//
// 3 functions was tested: 1. addTask
//						   2. searchTask
//						   3. editTask
//***************************************************************

#include "stdafx.h" 
#include "CppUnitTest.h"
#include "WWDisplay.h"
#include "WWExecutor.h"
#include "WWTask.h"
#include "WWUtilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace ExecutorUnitTest{		
	TEST_CLASS(testExecutor){
	public:
		//executor add integration test
		TEST_METHOD(Executor_Add_Task_Integration_Test)
		{
			WWExecutor executor;
			WWDisplay display;
			WWTask testTask1;
			WWTask testTask2;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			std::vector<std::string> taskDisplay;
			std::vector<std::vector<std::string>> expectedMainDisplay;
			std::vector<std::vector<std::string>> actualMainDisplay;
			int expectedPageType;
			int actualPageType;

			
			//test add task without type in taskName
			//task will not be added
			//systemResponse should return please input task name
			//return to page all
			display = executor.deleteAll();
			display = executor.addTask(testTask2); //testTask2 is empty without taskname now

			expectedSystemResponse = "Please input task name";
			expectedPageType = WWUtilities::PAGEALL;
			expectedMainDisplay.clear();

			actualMainDisplay = display.getMainDisplay();
			actualPageType = display.getPageIndex();
			actualSystemResponse = display.getSystemResponse();
			
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
			Assert::AreEqual(expectedMainDisplay.size(), actualMainDisplay.size());

			//test add one task
			testTask1.setTaskName("Task1");
			testTask1.setStartDate("20140325");
			testTask1.setStartTime("0800");

			display = executor.addTask(testTask1);
			expectedSystemResponse = "Task1 created";
			taskDisplay.push_back("Task1");	
			taskDisplay.push_back("Due  : 25 Mar 2014, 08:00am");		
			taskDisplay.push_back("overdue");


			expectedMainDisplay.push_back(taskDisplay);
			expectedPageType = WWUtilities::PAGEALL;

			actualMainDisplay = display.getMainDisplay();
			actualPageType = display.getPageIndex();
			actualSystemResponse = display.getSystemResponse();
			
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
			Assert::AreEqual(expectedMainDisplay.size(), actualMainDisplay.size());
			if(!expectedMainDisplay.size()){
				Assert::AreEqual(expectedMainDisplay[0].size(), actualMainDisplay[0].size());
			}
			
			for(unsigned int i = 0; i < expectedMainDisplay.size(); i++){
				for(unsigned int j = 0; j < 3; j++){
					Assert::AreEqual(expectedMainDisplay[i][j], actualMainDisplay[i][j]);
				}
			}

			//test add two tasks
			testTask2.setTaskName("Task2");
			expectedPageType = WWUtilities::PAGEALL;
			taskDisplay.clear();
			taskDisplay.push_back("Task2");
			taskDisplay.push_back("");
			taskDisplay.push_back("incomplete");
			expectedMainDisplay.push_back(taskDisplay);
			expectedSystemResponse = "Task2 created";

			display = executor.addTask(testTask2);

			actualMainDisplay = display.getMainDisplay();
			actualPageType = display.getPageIndex();
			actualSystemResponse = display.getSystemResponse();
			
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
			Assert::AreEqual(expectedMainDisplay.size(), actualMainDisplay.size());
			if(!expectedMainDisplay.size()){
				Assert::AreEqual(expectedMainDisplay[0].size(), actualMainDisplay[0].size());
			}

			for(unsigned int i = 0; i < expectedMainDisplay.size(); i++){
				for(unsigned int j = 0; j < 3; j++){
					Assert::AreEqual(expectedMainDisplay[i][j], actualMainDisplay[i][j]);
				}
			}
		}
		
		//executor search integration test
		TEST_METHOD(Executor_Search_Integration_Test){
			WWExecutor executor;
			WWDisplay display;
			WWTask testTask1;
			WWTask testTask2;
			WWTask testTask3;
			std::vector<std::string> testSearchAttributes;
			std::vector<std::string> taskDisplay;
			std::vector<std::vector<std::string>> expectedMainDisplay;
			std::vector<std::vector<std::string>> actualMainDisplay;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			testTask1.setTaskName("Task1");
			testTask1.setStartDate("20140404");
			testTask1.setStartTime("0800");
			testTask1.setEndDate("20140405");
			display = executor.addTask(testTask1);
			testTask2.setTaskName("task2");
			testTask2.setStartDate("20140406");
			testTask2.setStartTime("0800");
			display = executor.addTask(testTask2);
			testTask3.setTaskName("3");
			testTask3.setStartDate("20140406");
			testTask3.setStartTime("0900");
			testTask3.setEndDate("20140406");
			testTask3.setEndTime("1900");
			display = executor.addTask(testTask3);

			//test search one keyword "task" only
			//two results should show: Task1 and task2

			//arrange
			testSearchAttributes.push_back("task");
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("");

			expectedSystemResponse = "2 results are found";
			expectedPageType = WWUtilities::PAGESEARCH;

			taskDisplay.clear();
			taskDisplay.push_back("Task1");
			taskDisplay.push_back("From: 04 Apr 2014, 08:00am\nTo     : 05 Apr 2014");
			taskDisplay.push_back("overdue");
			expectedMainDisplay.push_back(taskDisplay);

			taskDisplay.clear();
			taskDisplay.push_back("task2");
			taskDisplay.push_back("Due  : 06 Apr 2014, 08:00am");			
			taskDisplay.push_back("overdue");
			expectedMainDisplay.push_back(taskDisplay);

			//act
			display = executor.searchTask(testSearchAttributes);

			actualMainDisplay = display.getMainDisplay();
			actualPageType = display.getPageIndex();
			actualSystemResponse = display.getSystemResponse();
			
			//assert
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
			Assert::AreEqual(expectedMainDisplay.size(), actualMainDisplay.size());
			if(!expectedMainDisplay.size()){
				Assert::AreEqual(expectedMainDisplay[0].size(), actualMainDisplay[0].size());
			}

			for(unsigned int i = 0; i < expectedMainDisplay.size(); i++){
				for(unsigned int j = 0; j < 3; j++){
					Assert::AreEqual(expectedMainDisplay[i][j], actualMainDisplay[i][j]);
				}
			}

			//test search within a time period from 20140405 - 20140406 without keyword
			//2 results should be found: task2 and 3

			//Arrange
			testSearchAttributes.clear();
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("20140406");
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("");
			testSearchAttributes.push_back("");

			expectedSystemResponse = "2 results are found";
			expectedPageType = WWUtilities::PAGESEARCH;
			expectedMainDisplay.clear();

			taskDisplay.clear();
			taskDisplay.push_back("task2");
			taskDisplay.push_back("Due  : 06 Apr 2014, 08:00am");
			taskDisplay.push_back("overdue");
			expectedMainDisplay.push_back(taskDisplay);

			taskDisplay.clear();
			taskDisplay.push_back("3");
			taskDisplay.push_back("From: 06 Apr 2014, 09:00am\nTo     : 06 Apr 2014, 07:00pm");
			taskDisplay.push_back("overdue");
			expectedMainDisplay.push_back(taskDisplay);

			//act
			display = executor.searchTask(testSearchAttributes);

			actualMainDisplay.clear();
			actualMainDisplay = display.getMainDisplay();
			actualPageType = display.getPageIndex();
			actualSystemResponse = display.getSystemResponse();
			
			//assert
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
			Assert::AreEqual(expectedMainDisplay.size(), actualMainDisplay.size());
			if(!expectedMainDisplay.size()){
				Assert::AreEqual(expectedMainDisplay[0].size(), actualMainDisplay[0].size());
			}

			for(unsigned int i = 0; i < expectedMainDisplay.size(); i++){
				for(unsigned int j = 0; j < 3; j++){
					Assert::AreEqual(expectedMainDisplay[i][j], actualMainDisplay[i][j]);
				}
			}
		} 

		//executor edit integration test
		TEST_METHOD(Executor_Edit_Integration_Test){
			WWTask testTemp;
			WWTask editTask;
			WWExecutor executor;
			WWDisplay display;
			std::vector<std::vector<std::string>> taskList;
			string expected;
			string actual;

			testTemp.setTaskName("Before Edit");
			testTemp.setStartDate("20140404");
			testTemp.setStartTime("0800");
			testTemp.setEndDate("20140405");
			testTemp.setEndTime("1800");

			display = executor.addTask(testTemp);
			expected = "Before Edit";
			taskList = display.getMainDisplay();
			Assert::AreEqual(expected, taskList[0][0]);

			//test edit name
			editTask.setTaskName("After Edit Name");

			display = executor.editTask(1, editTask, WWUtilities::PAGEALL);
			expected = "After Edit Name";
			taskList = display.getMainDisplay();
			actual = taskList[0][0];

			Assert::AreEqual(expected, actual);
		}
	};
}