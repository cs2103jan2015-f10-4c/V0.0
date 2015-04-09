#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TASK_NAME = "ABC";
const string STARTING_TIME = "0001";
const string ENDING_TIME = "2359";
const string STATUS = "DONE";

const string TEST_TIMED_TASK = "1. meeting ; 2012-01-01 1000 ; 2012-01-01 1300 ; Done";
const string TEST_DEADLINE_TASK = "2. assignment ; 2012-01-01 1300 ; Ongoing";
const string TEST_FLOATING_TASK = "3. reply email ; Ongoing";

namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestStorage)
	{
	public:
		
	
		TEST_METHOD(removeIndexMethod)
		{
			Storage fileStorage;

			string testInput;
			testInput = TEST_TIMED_TASK;
			string testOutput;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " meeting ; 2012-01-01 1000 ; 2012-01-01 1300 ; Done");

			testInput = TEST_DEADLINE_TASK;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " assignment ; 2012-01-01 1300 ; Ongoing");

			testInput = TEST_FLOATING_TASK;
			testOutput = fileStorage.removeIndex(testInput);
			Assert::IsTrue(testOutput == " reply email ; Ongoing");

		}
		
		TEST_METHOD(getTaskName)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;
			
			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "meeting");

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "assignment");

			testInput = TEST_FLOATING_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getTaskName(testInput);
			Assert::IsTrue(testOutput == "reply email");

		}

		TEST_METHOD(getStartingTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStartingTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1000");
		}

		TEST_METHOD(getEndingTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getEndingTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1300");
		}

		TEST_METHOD(getDueTime)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getDueTime(testInput);
			Assert::IsTrue(testOutput == "2012-01-01 1300");
		}

		TEST_METHOD(getStatus)
		{
			Storage fileStorage;

			string testInput;
			string testOutput;

			testInput = TEST_TIMED_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Done");

			testInput = TEST_DEADLINE_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Ongoing");

			testInput = TEST_FLOATING_TASK;
			testInput = fileStorage.removeIndex(testInput);
			testOutput = fileStorage.getStatus(testInput);
			Assert::IsTrue(testOutput == "Ongoing");
		}

		TEST_METHOD(loadTask)
		{
			Storage fileStorage;
			vector<string> testTaskLine;
			vector<Task> testTaskList;

			testTaskLine.push_back(TEST_TIMED_TASK);
			testTaskLine.push_back(TEST_DEADLINE_TASK);
			testTaskLine.push_back(TEST_FLOATING_TASK);

			fileStorage.loadTask(testTaskLine,testTaskList);
			int tasklistSize; 
			tasklistSize = testTaskList.size();
			int expectedSize = 3;
			Assert::IsTrue(tasklistSize == expectedSize);

			string expectedTimedTaskName = "meeting";
			string expectedTimedTaskStartTime = "2012-01-01 1000";
			string expectedTimedTaskEndTime = "2012-01-01 1300";
			string expectedTimedTaskStatus = "Done";
			string expectedTimedTaskType = "timed";

			Assert::IsTrue(testTaskList[0].taskName == expectedTimedTaskName);
			Assert::IsTrue(testTaskList[0].startingTime == expectedTimedTaskStartTime);
			Assert::IsTrue(testTaskList[0].endingTime == expectedTimedTaskEndTime);
			Assert::IsTrue(testTaskList[0].status == expectedTimedTaskStatus);
			Assert::IsTrue(testTaskList[0].type == expectedTimedTaskType);

			string expectedDeadlineTaskName = "assignment";
			string expectedDeadlineTaskDueTime = "2012-01-01 1300";
			string expectedDeadlineTaskStatus = "Ongoing";
			string expectedDeadlineTaskType = "deadline";

			Assert::IsTrue(testTaskList[1].taskName == expectedDeadlineTaskName);
			Assert::IsTrue(testTaskList[1].endingTime == expectedDeadlineTaskDueTime);
			Assert::IsTrue(testTaskList[1].status == expectedDeadlineTaskStatus);
			Assert::IsTrue(testTaskList[1].type == expectedDeadlineTaskType);

			string expectedFloatingTaskName = "reply email";
			string expectedFloatingTaskStatus = "Ongoing";
			string expectedFloatingTaskType = "floating";
			
			Assert::IsTrue(testTaskList[2].taskName == expectedFloatingTaskName);
			Assert::IsTrue(testTaskList[2].status == expectedFloatingTaskStatus);
			Assert::IsTrue(testTaskList[2].type == expectedFloatingTaskType);

		}
	};
}

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