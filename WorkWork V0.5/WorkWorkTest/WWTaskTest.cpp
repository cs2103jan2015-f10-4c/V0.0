//@author A0101014L
// WWTaskTest.cpp

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TASK_NAME       = "taskName";
const string START_DATE      = "19911105";
const string START_TIME      = "0636";
const string END_DATE        = "20140411";
const string END_TIME        = "2103";
const string EMPTY_PARAMETER = "";

namespace UnitTest
{
	TEST_CLASS(WWTaskTest)
	{
	public:
		TEST_METHOD(setGetTaskNameTest)
		{
			WWTask task;

			task.setTaskName(TASK_NAME);
			Assert::AreEqual(task.getTaskName(), TASK_NAME);
		}

		TEST_METHOD(setGetDateTest)
		{
			WWTask task;

			task.setStartDate(START_DATE);
			Assert::AreEqual(task.getStartDate(), START_DATE);

			task.setEndDate(END_DATE);
			Assert::AreEqual(task.getEndDate(), END_DATE);			
		}

		TEST_METHOD(setGetTimeTest)
		{
			WWTask task;

			task.setStartTime(START_TIME);
			Assert::AreEqual(task.getStartTime(), START_TIME);

			task.setEndTime(END_DATE);
			Assert::AreEqual(task.getEndTime(), END_DATE);
		}

		TEST_METHOD(setGetStatusTest)
		{
			WWTask task;

			task.setStatus(true);
			Assert::IsTrue(task.getStatus());

			task.setStatus(false);
			Assert::IsFalse(task.getStatus());
		}

		//test using non-empty parameters and empty parameters
		TEST_METHOD(hasAttributeTest)
		{
			WWTask task;

			task.setTaskName(TASK_NAME);
			task.setStartDate(START_DATE);
			task.setStartTime(START_TIME);
			task.setEndDate(END_DATE);
			task.setEndTime(END_DATE);

			//non-empty parameters will return a bool of true
			Assert::IsTrue(task.hasTaskName());
			Assert::IsTrue(task.hasStartDate());
			Assert::IsTrue(task.hasStartTime());
			Assert::IsTrue(task.hasEndDate());
			Assert::IsTrue(task.hasEndTime());
						
			task.setTaskName(EMPTY_PARAMETER);
			task.setStartDate(EMPTY_PARAMETER);
			task.setStartTime(EMPTY_PARAMETER);
			task.setEndDate(EMPTY_PARAMETER);
			task.setEndTime(EMPTY_PARAMETER);

			//empty parameters will return a bool of false
			Assert::IsFalse(task.hasTaskName());
			Assert::IsFalse(task.hasStartDate());
			Assert::IsFalse(task.hasStartTime());
			Assert::IsFalse(task.hasEndDate());
			Assert::IsFalse(task.hasEndTime());
		}
		
		TEST_METHOD(checkTaskType)
		{
			WWTask task;

			task.setTaskName(TASK_NAME);
			task.setStartDate(START_DATE);
			task.setStartTime(START_TIME);
			task.setEndDate(END_DATE);
			task.setEndTime(END_DATE);
			
			WWUtilities::TaskType timed = WWUtilities::TIMED;

			//if start date, end date, start time, end time are not empty, task is a timed task
			Assert::IsTrue(timed == task.getTaskType());

			task.setStartTime(EMPTY_PARAMETER);
			task.setEndTime(EMPTY_PARAMETER);

			//if only start date and end date are not empty, task is still a timed task
			Assert::IsTrue(timed == task.getTaskType());

			task.setStartDate(EMPTY_PARAMETER);
			task.setStartTime(EMPTY_PARAMETER);
			task.setEndDate(EMPTY_PARAMETER);
			task.setEndTime(EMPTY_PARAMETER);

			WWUtilities::TaskType floating = WWUtilities::FLOATING;

			//if both start date and end date are empty(meaning start time and end time are also empty, checked by parser)
			//task is a floating task
			Assert::IsTrue(floating == task.getTaskType());

			task.setStartDate(START_DATE);

			WWUtilities::TaskType deadline = WWUtilities::DEADLINE;

			//if a task only has a start date, it is a deadline task
			Assert::IsTrue(deadline == task.getTaskType());

			task.setStartTime(START_TIME);

			//if a task only has start date and start time, it is still deadline task
			Assert::IsTrue(deadline == task.getTaskType());
		}
	};
}