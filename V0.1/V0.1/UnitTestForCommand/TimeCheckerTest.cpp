//@author A0116363L
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(timeCheckerTest)
	{
	public:
		
		TEST_METHOD(checkStatus_test){
			TimeChecker time;
			bool isOverdue;
			//not overdue case
			string testTime1 = "20-05-2015 09:00";
			isOverdue = time.checkStatus(testTime1);
			Assert::IsFalse(isOverdue);

			//overdue case
			string testTime2 = "03-04-2014 09:00";
			isOverdue = time.checkStatus(testTime2);
			Assert::IsTrue(isOverdue);
		}

		TEST_METHOD(updateStatus_test){
			
			TimeChecker time;
			Task testTask1;
			testTask1.setTaskName("buy milk");
			testTask1.setStartingTime("");
			testTask1.setEndingTime("");
			testTask1.setDone("done");
			testTask1.setType("floating");

			Task testTask2;
			testTask2.setTaskName("drink milk");
			testTask2.setStartingTime("");
			testTask2.setEndingTime("03-04-2014 09:23");
			testTask2.setDone("done");
			testTask2.setType("deadline");
			//floating & done type will not be set as overdue

			Task testTask3;
			testTask3.setTaskName("finish tutorial");
			testTask3.setStartingTime("03-04-2014 09:23");
			testTask3.setEndingTime("06-04-2015 23:59");
			testTask3.setDone("ongoing");
			testTask3.setType("timed");
			//timed will be set as overdue

			Task testTask4;
			testTask4.setTaskName("eat breakfast");
			testTask4.setStartingTime("");
			testTask4.setEndingTime("10-06-2015 08:00");
			testTask4.setDone("ongoing");
			testTask4.setType("deadline");
			//deadline& ongoing

			vector<Task> taskList;
			taskList.push_back(testTask1);
			taskList.push_back(testTask2);
			taskList.push_back(testTask3);
			taskList.push_back(testTask4);
			
			time.updateStatus(taskList);

			vector<Task> expectedOutput;
			vector<Task> actualOutput = taskList;
			expectedOutput.push_back(testTask1);
			expectedOutput.push_back(testTask2);
			expectedOutput.push_back(testTask3);
			expectedOutput.push_back(testTask4);
			expectedOutput[2].setDone("overdue");

			Assert::AreEqual(expectedOutput[2].status, actualOutput[2].status);

		}

	};
}