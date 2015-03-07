//@author A0105476E

//**************************************************************
//			    Unit Test: DeleteExecutor Class
//					  Author: AI YUE
//
//			      File: testDeleteExecutor.cpp
//
// testAddExecutor tests 2 cases: 1. delete a valid index
//                                2. delete an invalid index
//**************************************************************

#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "DeleteExecutor.h"
#include "WWDisplay.h"
#include "WWTask.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest{
	TEST_CLASS(testDeleteExecutor){
	public:

		//********************************************************************
		//        Positive test: test delete valid index
		//
		// 1. the task should be successfully deleted from the task vector
		// 2. pageType inside display should remain same
		// 3. systemResponse inside display should be set as delete successful
		//   system response
		//********************************************************************
		TEST_METHOD(test_delete_valid_index){
			DeleteExecutor deleteExecutor;
			WWTask testTask;
			WWDisplay display;
			WWUtilities::PageType pageType = WWUtilities::PAGEALL;
			std::vector<WWTask> taskList;

			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			int expectedPageType;
			int actualPageType;

			//Arrange
			testTask.setTaskName("test task");
			taskList.push_back(testTask);
			expectedSystemResponse = "test task deleted";
			expectedPageType = pageType;

			//Act
			deleteExecutor.deleteTask(taskList, 0, pageType, display);
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 0);			//after delete task, taskList size should be 0
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}

	    //*****************************************************************
		//        Negative test: test delete invalid index
		//
		// 1. the task will not be deleted from the task vector
		// 2. pageType inside display should remain unchanged
		// 3. systemResponse inside display should be set as delete failed
		//   system response
		//*****************************************************************
		TEST_METHOD(test_addTask_with_taskname){
			DeleteExecutor deleteExecutor;
			WWTask testTask;
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
			expectedTaskName = "test task";
			expectedSystemResponse = "Index not found";
			expectedPageType = pageType;

			//Act
			deleteExecutor.deleteTask(taskList, 2, pageType, display);
			actualTaskName = taskList[0].getTaskName();
			actualSystemResponse = display.getSystemResponse();
			actualPageType = display.getPageIndex();

			//Assert
			Assert::AreEqual((int)taskList.size(), 1);			//the task will not be deleted, taskList size remains 1
			Assert::AreEqual(expectedTaskName, actualTaskName);
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedPageType, actualPageType);
		}
	};
}