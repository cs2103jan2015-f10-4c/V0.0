#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

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

			//Logic Logic;
			//Logic.addTask("abc", "1300", "1400");
			//tasklist = Storage.getTaskList();
			//int size1 = tasklist.size();
			//string starttime = tasklist[0].startingTime;
			////string endtime = tasklist[0].endingTime;
			////Assert::AreEqual(size1, 1);
			////Assert::IsTrue(starttime == "1300");
			////Assert::IsTrue(endtime == "1400");

		}
		TEST_METHOD(updateTaskList)
		{
			Task task;
			task.taskName = "ABC";
			task.startingTime = "0001";
			task.endingTime = "2359";
			task.status = "done";

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
			Assert::IsTrue(storageTasklist[0].status == "done");



		}

	};
}