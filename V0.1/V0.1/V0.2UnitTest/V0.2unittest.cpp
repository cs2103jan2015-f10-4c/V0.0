#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace V02UnitTest
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(HistorySave)
		{
			vector<Task> tasklist, tasklist2, actualTasklist;
			History history;
			stack<vector<Task>> actualOutput;
			Task task1;
			task1.setTaskName("write cs like hell");
			task1.setStartingTime("2015-1-12 08:00");
			task1.setEndingTime("2015-4-26 23:59");
			task1.setType("Timed");
			task1.setDone("Ongoing");
			tasklist.push_back(task1);
			vector<string> expectedOutput;
			expectedOutput[0] = "write cs like hell from 2015-1-12 08:00 to 2015-4-26 23:59 Ongoing Timed";
			//test saveOperation 1 task only//
			history.saveOperation(tasklist);
			actualOutput = history.getUndoStorageList();

			Assert::AreEqual(expectedOutput[0], (actualOutput.top())[0].ToString());

			//test saveOperation 2 task//
			//adding only
			Task task2;
			task2.setTaskName("hello world");
			task2.setStartingTime("2015-1-12 12:00");
			task2.setEndingTime("2015-4-30 23:59");
			task2.setType("Timed");
			task2.setDone("Ongoing");

			Task task3;
			task3.setTaskName("hello world!!!!");
			task3.setStartingTime("2015-1-12 12:00");
			task3.setEndingTime("2015-4-30 23:59");
			task3.setType("Timed");
			task3.setDone("Ongoing");

			tasklist2.push_back(task2);
			tasklist2.push_back(task3);

			history.saveOperation(tasklist2);
			actualOutput = history.getUndoStorageList();
			expectedOutput[1] = "hello world from 2015-1-12 12:00 to 2015-4-30 23:59 Ongoing Timed";
			expectedOutput[2] = "hello world!!!! from 2015-1-12 12:00 to 2015-4-30 23:59 Ongoing Timed";
			Assert::AreEqual(expectedOutput[0], (actualOutput.top())[0].ToString());//fail case
			Assert::AreEqual(expectedOutput[2], (actualOutput.top())[0].ToString());//success case
			Assert::AreEqual(expectedOutput[1], (actualOutput.top())[1].ToString());//success case


		}
		TEST_METHOD(HistoryUndo)
		{
			vector<Task> tasklist, actualTasklist;
			History history;
			stack<vector<Task>> actualOutput;
			Task task1;
			task1.setTaskName("write cs like hell");
			task1.setStartingTime("2015-1-12 08:00");
			task1.setEndingTime("2015-4-26 23:59");
			task1.setType("Timed");
			task1.setDone("Ongoing");
			tasklist.push_back(task1);
			vector<string> expectedOutput;
			expectedOutput[0] = "write cs like hell from 2015-1-12 08:00 to 2015-4-26 23:59 Ongoing Timed";
			//test saveOperation 1 task only//
			history.saveOperation(tasklist);
			actualOutput = history.getUndoStorageList();

			Assert::AreEqual(expectedOutput[0], (actualOutput.top())[0].ToString());

			//test saveOperation 2 task//
			//adding only to be imperoved;
			Task task2;
			task2.setTaskName("hello world");
			task2.setStartingTime("2015-1-12 12:00");
			task2.setEndingTime("2015-4-30 23:59");
			task2.setType("Timed");
			task2.setDone("Ongoing");

			tasklist.push_back(task2);
			history.saveOperation(tasklist);
			//test Undo//

			actualTasklist = history.undo(tasklist);
			Assert::AreEqual(expectedOutput[0], actualTasklist[0].ToString());
			actualTasklist = history.undo(tasklist);

			//task list updated  empty stack
			//fail case: since now stack actualOutput is empty
			//hence assertions need to ensure protection
			Assert::AreEqual(expectedOutput[0], (actualOutput.top())[0].ToString());

		}

	};
}