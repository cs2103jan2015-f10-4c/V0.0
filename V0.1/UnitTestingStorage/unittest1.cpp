#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TASK_NAME = "ABC";
const string STARTING_TIME = "0001";
const string ENDING_TIME = "2359";
const string STATUS = "DONE";

const string TEST_TIMED_TASK = "1. meeting ; 2012-01-01 1000 ; 2012-01-01 1300 ; Done";

namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestStorage)
	{
	public:
		
		/*TEST_METHOD(getTaskList)
		{
			Storage Storage;
			vector<Task> testTasklist;
			testTasklist = Storage.getTaskList();
			int size = testTasklist.size();
			Assert::AreEqual(size, 0);

			Task testTask;
			testTask.setTaskName(TASK_NAME);
			testTask.setStartingTime(STARTING_TIME);
			testTask.setEndingTime(ENDING_TIME);
			testTask.setDone(STATUS);

			
			vector<Task> newTasklist;
			newTasklist = Storage.getTaskList();
			int size1 = newTasklist.size();
			Assert::AreEqual(size1, 1);
			
			Assert::IsTrue(newTasklist[0].taskName == TASK_NAME);
			Assert::IsTrue(newTasklist[0].startingTime == STARTING_TIME);
			Assert::IsTrue(newTasklist[0].endingTime == ENDING_TIME);
			Assert::IsTrue(newTasklist[0].status == STATUS);

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

		}*/

		TEST_METHOD(removeIndexMethod)
		{
			Storage fileStorage;

			string testInput;
			testInput = TEST_TIMED_TASK;
			string testOutput;
			testOutput = fileStorage.removeIndex(testInput);

			Assert::IsTrue(testOutput == " meeting ; 2012-01-01 1000 ; 2012-01-01 1300 ; Done");
		}



	};
}