//@author A0105476E

//**************************************************************
//			    Unit Test: EditExecutor Class
//					  Author: AI YUE
//
//			      File: testEditExecutor.cpp
//
// testAddExecutor tests 2 cases: 1. edit task name
//                                2. edit invalid index
//**************************************************************

#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "EditExecutor.h"
#include "WWDisplay.h"
#include "WWTask.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest{
	TEST_CLASS(testEditExecutor){
	public:
		//*****************************************************************
		//        Positive test: test edit task name
		//
		// 1. the taskname should be changed
		// 2. pageType inside display should be remain unchanged
		// 3. systemResponse inside display should be set as edit successful
		//   system response
		//*****************************************************************
		TEST_METHOD(test_edit_task_name){
			EditExecutor editExecutor;
			WWTask testTask;
			WWTask newTask;
			WWDisplay display;
			std::vector<WWTask> taskList;
			WWUtilities::PageType pageType = WWUtilities::PAGEALL;

			std::string expectedTaskName;
			std::string actualTaskName;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			//Arrange
			taskList.clear();
			testTask.setTaskName("test task");
			taskList.push_back(testTask);
			newTask.setTaskName("test task edited");
			expectedTaskName = "test task edited";
			expectedSystemResponse = "test task edited edited";
			expectedPageType = pageType;

			//Act
			editExecutor.editTask(taskList, 0, newTask, pageType, display);
			actualTaskName = taskList[0].getTaskName();
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 1);			//after add task, taskList size should remains 1
			Assert::AreEqual(expectedTaskName, actualTaskName);
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}

	    //*****************************************************************
		//        Negative test: test edit invalid index
		//
		// 1. the task will not be edited
		// 2. pageType inside display should remain unchanged
		// 3. systemResponse inside display should be set as edit failed
		//   system response
		//*****************************************************************
		TEST_METHOD(test_edit_invalid_index){
			EditExecutor editExecutor;
			WWTask testTask;
			WWTask newTask;
			WWDisplay display;
			std::vector<WWTask> taskList;
			WWUtilities::PageType pageType = WWUtilities::PAGEALL;

			std::string expectedTaskName;
			std::string actualTaskName;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			//Arrange
			taskList.clear();
			testTask.setTaskName("test task");
			taskList.push_back(testTask);
			newTask.setTaskName("test task");
			expectedTaskName = "test task";
			expectedSystemResponse = "Index not found";
			expectedPageType = pageType;

			//Act
			editExecutor.editTask(taskList, 10, newTask, pageType, display);
			actualTaskName = taskList[0].getTaskName();
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 1);			//taskList size should remains 1
			Assert::AreEqual(expectedTaskName, actualTaskName);
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}

	};
}