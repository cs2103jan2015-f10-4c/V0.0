//@author A0105476E

//**************************************************************
//			    Unit Test: SearchExecutor Class
//					  Author: AI YUE
//
//			      File: testSearchExecutor.cpp
//
// testSearchExecutor tests 1 cases: search keyword within time
//									period
//**************************************************************

#include <vector>
#include <string>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "SearchExecutor.h"
#include "WWTask.h"
#include "WWUtilities.h"
#include "WWDisplay.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest
{
	TEST_CLASS(testSearchExecutor)
	{
	public:
		TEST_METHOD(test_search_task_within_time_period)
		{
			SearchExecutor searchExecutor;
			WWDisplay display;
			std::vector<WWTask> taskList;
			std::vector<WWTask> resultList;
			WWTask testTask1, testTask2, testTask3, testTask4;

			std::string expectedSystemResponse;
			std::string actualSystemResponse;
			std::vector<std::string> expectedTaskNames;
			std::vector<std::string> actualTaskNames;

			//arrange
			testTask1.setTaskName("Floating task 1");
			taskList.push_back(testTask1);
			testTask2.setTaskName("Deadline task 1");
			testTask2.setStartDate("20140404");
			taskList.push_back(testTask2);
			testTask3.setTaskName("Timed task 1");
			testTask3.setStartDate("20140403");
			testTask3.setEndDate("20140405");
			testTask3.setEndTime("1800");
			taskList.push_back(testTask3);
			testTask4.setTaskName("Timed task 2");
			testTask4.setStartDate("20140405");
			testTask4.setStartTime("0200");
			testTask4.setEndDate("20140406");
			testTask4.setEndTime("0200");
			taskList.push_back(testTask4);

			expectedSystemResponse = "2 results are found";			
			expectedTaskNames.push_back("Timed task 1");
			expectedTaskNames.push_back("Deadline task 1");

			//act
			searchExecutor.searchTask(taskList, "", 201404040000, 201404042359, display);
			searchExecutor.getSearchResult(resultList);

			actualSystemResponse = display.getSystemResponse();

			//assert
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
			Assert::AreEqual(expectedTaskNames[0], resultList[0].getTaskName());
			Assert::AreEqual(expectedTaskNames[1], resultList[1].getTaskName());
		}

	};
}