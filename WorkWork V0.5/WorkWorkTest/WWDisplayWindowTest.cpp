//@author A0099689W
#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
const string EMPTY_CONTENT = "";

const bool TEST_STATUS_DONE = true;
const bool TEST_STATUS_UNDONE = false;

const string TEST_TIMED_TASK_NAME = "timed";
const string TEST_DEADLINE_TASK_NAME= "deadline";
const string TEST_FLOATING_TASK_NAME = "floating";
const string TEST_START_DATE = "20140215";
const string TEST_END_DATE = "20140420";
const string TEST_START_TIME = "1920";
const string TEST_END_TIME = "2359";

const string DISPLAY_CASE_1_NAME   = "timed";
const string DISPLAY_CASE_1_DATE   = "From: 15 Feb 2014, 07:20pm\nTo     : 20 Apr 2014, 11:59pm";
const string DISPLAY_CASE_1_STATUS = "complete";
const string DISPLAY_CASE_2_NAME   = "timed";
const string DISPLAY_CASE_2_DATE   = "From: 15 Feb 2014\nTo     : 20 Apr 2014";
const string DISPLAY_CASE_2_STATUS = "complete";
const string DISPLAY_CASE_3_NAME   = "deadline";
const string DISPLAY_CASE_3_DATE   = "Due  : 15 Feb 2014, 07:20pm";
const string DISPLAY_CASE_3_STATUS = "complete";
const string DISPLAY_CASE_4_NAME   = "deadline";
const string DISPLAY_CASE_4_DATE   = "Due  : 15 Feb 2014";
const string DISPLAY_CASE_4_STATUS = "complete";
const string DISPLAY_CASE_5_NAME   = "deadline";
const string DISPLAY_CASE_5_DATE   = "Due  : 15 Feb 2014";
const string DISPLAY_CASE_5_STATUS = "overdue";
const string DISPLAY_CASE_6_NAME   = "floating";
const string DISPLAY_CASE_6_DATE   = "";
const string DISPLAY_CASE_6_STATUS = "incomplete";
namespace WWDisplayWindowTest
{
	TEST_CLASS(WWDisplayWindowTest)
	{
	public:
		
		TEST_METHOD(setGetContentTest)
		{
			WWDisplayWindow testDisplayWindow;
			vector<WWTask> testStorage;
			string actualName, actualDate, actualStatus;
			//TC1 when displaying a timed task with both dates and times
			WWTask testTask1;
			testTask1.setTaskName(TEST_TIMED_TASK_NAME);
			testTask1.setStartDate(TEST_START_DATE);
			testTask1.setEndDate(TEST_END_DATE);
			testTask1.setStartTime(TEST_START_TIME);
			testTask1.setEndTime(TEST_END_TIME);
			testTask1.setStatus(TEST_STATUS_DONE);

			testStorage.push_back(testTask1);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[0][0];
			actualDate = testDisplayWindow.getContent()[0][1];
			actualStatus = testDisplayWindow.getContent()[0][2];
			Assert::AreEqual(DISPLAY_CASE_1_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_1_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_1_STATUS, actualStatus);
			//TC2 when displaying a timed task with only dates
			WWTask testTask2;
			testTask2.setTaskName(TEST_TIMED_TASK_NAME);
			testTask2.setStartDate(TEST_START_DATE);
			testTask2.setEndDate(TEST_END_DATE);
			testTask2.setStatus(TEST_STATUS_DONE);

			testStorage.push_back(testTask2);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[1][0];
			actualDate = testDisplayWindow.getContent()[1][1];
			actualStatus = testDisplayWindow.getContent()[1][2];
			Assert::AreEqual(DISPLAY_CASE_2_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_2_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_2_STATUS, actualStatus);
			//TC3 when displaying a deadline task with date and time
			WWTask testTask3;
			testTask3.setTaskName(TEST_DEADLINE_TASK_NAME);
			testTask3.setStartDate(TEST_START_DATE);
			testTask3.setStartTime(TEST_START_TIME);
			testTask3.setStatus(TEST_STATUS_DONE);

			testStorage.push_back(testTask3);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[2][0];
			actualDate = testDisplayWindow.getContent()[2][1];
			actualStatus = testDisplayWindow.getContent()[2][2];
			Assert::AreEqual(DISPLAY_CASE_3_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_3_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_3_STATUS, actualStatus);
			//TC4 when displaying a deadline task with only date
			WWTask testTask4;
			testTask4.setTaskName(TEST_DEADLINE_TASK_NAME);
			testTask4.setStartDate(TEST_START_DATE);
			testTask4.setStatus(TEST_STATUS_DONE);

			testStorage.push_back(testTask4);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[3][0];
			actualDate = testDisplayWindow.getContent()[3][1];
			actualStatus = testDisplayWindow.getContent()[3][2];
			Assert::AreEqual(DISPLAY_CASE_4_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_4_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_4_STATUS, actualStatus);
			//TC5 when displaying an overdue task
			WWTask testTask5;
			testTask5.setTaskName(TEST_DEADLINE_TASK_NAME);
			testTask5.setStartDate(TEST_START_DATE);
			testTask5.setStatus(TEST_STATUS_UNDONE);

			testStorage.push_back(testTask5);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[4][0];
			actualDate = testDisplayWindow.getContent()[4][1];
			actualStatus = testDisplayWindow.getContent()[4][2];
			Assert::AreEqual(DISPLAY_CASE_5_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_5_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_5_STATUS, actualStatus);
			//TC6 when displaying a floating task
			WWTask testTask6;
			testTask6.setTaskName(TEST_FLOATING_TASK_NAME);
			testTask6.setStatus(TEST_STATUS_UNDONE);

			testStorage.push_back(testTask6);

			testDisplayWindow.setContent(testStorage);

			actualName = testDisplayWindow.getContent()[5][0];
			actualDate = testDisplayWindow.getContent()[5][1];
			actualStatus = testDisplayWindow.getContent()[5][2];
			Assert::AreEqual(DISPLAY_CASE_6_NAME, actualName);
			Assert::AreEqual(DISPLAY_CASE_6_DATE, actualDate);
			Assert::AreEqual(DISPLAY_CASE_6_STATUS, actualStatus);
		}

	};
}