#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TASK_NAME = "ABC";
const string STARTING_TIME = "0001";
const string ENDING_TIME = "2359";
const string STATUS = "DONE";

namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestStorage)
	{
	public:
		
		TEST_METHOD(getTaskList)
		{
			Storage Storage;
			vector<Task> tasklist;
			tasklist = Storage.getTaskList();
			int size = tasklist.size();
			Assert::AreEqual(size, 0);

			Task task;
			task.taskName = TASK_NAME;
			task.startingTime = STARTING_TIME;
			task.endingTime = ENDING_TIME;
			task.status = STATUS;

			tasklist = Storage.getTaskList();
			Assert::IsTrue(tasklist[0].taskName == "ABC");
			Assert::IsTrue(tasklist[0].startingTime == "0001");
			Assert::IsTrue(tasklist[0].endingTime == "2359");
			Assert::IsTrue(tasklist[0].status == "DONE");

		}
		
		
		TEST_METHOD(updateTaskList)
		{
			Task task;
			task.taskName = TASK_NAME;
			task.startingTime = STARTING_TIME;
			task.endingTime = ENDING_TIME;
			task.status = STATUS;

			Storage storage;
			vector<Task> tasklist;
			vector<Task> storageTasklist;
			tasklist.push_back(task);

			storage.updateTaskList(tasklist);
			storageTasklist = storage.getTaskList();

			int size = storageTasklist.size();
			Assert::AreEqual(size,1);

			Assert::IsTrue(storageTasklist[0].taskName == "ABC");
			Assert::IsTrue(storageTasklist[0].startingTime == "0001");
			Assert::IsTrue(storageTasklist[0].endingTime == "2359");
			Assert::IsTrue(storageTasklist[0].status == "DONE");

		}

	};
}