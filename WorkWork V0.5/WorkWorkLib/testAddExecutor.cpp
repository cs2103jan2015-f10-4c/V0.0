//@author A0105476E

//**************************************************************
//			    Unit Test: AddExecutor Class
//					  Author: AI YUE
//
//			      File: testAddExecutor.cpp
//
// testAddExecutor tests 2 cases: 1. add task with task name
//                                2. add task without task name
//**************************************************************

#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "AddExecutor.h"
#include "WWTask.h"
#include "WWDisplay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest{
	TEST_CLASS(testAddExecutor){
	public:
		//*****************************************************************
		//        Positive test: test add task with task name
		//
		// 1. the task should be successfully added into the task vector
		// 2. pageType inside display should be set as PAGEALL
		// 3. systemResponse inside display should be set as add successful
		//   system response
		//*****************************************************************
		TEST_METHOD(test_addTask_with_taskname){
			AddExecutor addExecutor;
			WWTask testTask;
			WWDisplay display;
			std::vector<WWTask> taskList;

			std::string expectedTaskName;
			std::string actualTaskName;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			//Arrange
			taskList.clear();
			testTask.setTaskName("test task");
			expectedTaskName = "test task";
			expectedSystemResponse = "test task created";
			expectedPageType = WWUtilities::PAGEALL;

			//Act
			addExecutor.addTask(taskList, testTask, display);
			actualTaskName = taskList[0].getTaskName();
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 1);			//after add task, taskList size should be 1
			Assert::AreEqual(expectedTaskName, actualTaskName);
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}

	    //*****************************************************************
		//        Negative test: test add task without task name
		//
		// 1. the task will not be added into the task vector
		// 2. pageType inside display should be set as PAGEALL
		// 3. systemResponse inside display should be set as add failed
		//   system response
		//*****************************************************************
		TEST_METHOD(test_addTask_without_taskname){
			AddExecutor addExecutor;
			WWTask testTask;
			WWDisplay display;
			std::vector<WWTask> taskList;

			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			//Arrange
			taskList.clear();
			testTask.setTaskName("");
			expectedSystemResponse = "Please input task name";
			expectedPageType = WWUtilities::PAGEALL;

			//Act
			addExecutor.addTask(taskList, testTask, display);
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 0);			//task won't be added into the task vector, taskList size should remain 0
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}
	};
}