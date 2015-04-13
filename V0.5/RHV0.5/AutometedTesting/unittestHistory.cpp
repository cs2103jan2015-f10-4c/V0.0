//@author A0114946B

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesthistory
{		
	TEST_CLASS(UnitTestHistory)
	{
	public:
		
		TEST_METHOD(testUndoRedo)
		{
			Task testTask1;
			testTask1.setTaskName("ABC");
			testTask1.setStartingTime ("0000");
			testTask1.setEndingTime ("2359");
			testTask1.setDone ("DONE");

			Task testTask2;
			testTask2.setTaskName("AAA");
			testTask2.setStartingTime ("1111");
			testTask2.setEndingTime ("2200");
			testTask2.setDone ("DONE");

			Task testTask3;
			testTask3.setTaskName("BBB");
			testTask3.setStartingTime ("1000");
			testTask3.setEndingTime ("2100");
			testTask3.setDone ("ONGOING");

			vector<Task> taskList1;
			vector<Task> taskList2;
			taskList1.push_back(testTask1);
			taskList1.push_back(testTask2);
			taskList2.push_back(testTask1);
			taskList2.push_back(testTask2);
			taskList2.push_back(testTask3);

			int size1 = taskList1.size();
			int size2 = taskList2.size();
			Assert::AreEqual(size1, 2);
			Assert::AreEqual(size2, 3);
			
			//taskList1 obtained by operation1 after first command
			//taskList2 obtained by operation2 after second command
			History histryStorage;
			histryStorage.saveOperation(taskList1);
			histryStorage.saveOperation(taskList2);
			
			//undo stack should have 2 tasklists
			stack <vector<Task>> undoStack;
			undoStack = histryStorage.getUndoStorageList();
			int size3 = undoStack.size();
			Assert::AreEqual(size3, 2);

			vector<Task> newTaskList;
			newTaskList = histryStorage.undo();
			undoStack = histryStorage.getUndoStorageList();
			int size4 = undoStack.size();
			Assert::AreEqual(size4, 1);
			
			stack <vector<Task>> redoStack;
			redoStack = histryStorage.getRedoStorageList();
			int size5 = redoStack.size();
			Assert::AreEqual(size5, 1);

			//after one undo, taskList obtained should be same as the tasklist1 
			Assert::IsTrue(newTaskList[0].taskName == taskList1[0].taskName);
			Assert::IsTrue(newTaskList[0].startingTime == taskList1[0].startingTime);
			Assert::IsTrue(newTaskList[0].endingTime == taskList1[0].endingTime);
			Assert::IsTrue(newTaskList[0].status == taskList1[0].status);

			Assert::IsTrue(newTaskList[1].taskName == taskList1[1].taskName);
			Assert::IsTrue(newTaskList[1].startingTime == taskList1[1].startingTime);
			Assert::IsTrue(newTaskList[1].endingTime == taskList1[1].endingTime);
			Assert::IsTrue(newTaskList[1].status == taskList1[1].status);

			//after 2 undo, undo stack should be empty
			newTaskList = histryStorage.undo();
			undoStack = histryStorage.getUndoStorageList();
			size4 = undoStack.size();
			Assert::AreEqual(size4, 0);
			redoStack = histryStorage.getRedoStorageList();
			size5 = redoStack.size();
			Assert::AreEqual(size5, 2);
			
			//after one redo
			newTaskList = histryStorage.redo();
			int size6 = newTaskList.size();
			Assert::AreEqual(size6, 2);
			redoStack = histryStorage.getRedoStorageList();
			size5 = redoStack.size();
			Assert::AreEqual(size5, 1);

			//after one redo, taskList obtained should be same as the tasklist1 
			Assert::IsTrue(newTaskList[0].taskName == taskList1[0].taskName);
			Assert::IsTrue(newTaskList[0].startingTime == taskList1[0].startingTime);
			Assert::IsTrue(newTaskList[0].endingTime == taskList1[0].endingTime);
			Assert::IsTrue(newTaskList[0].status == taskList1[0].status);

			Assert::IsTrue(newTaskList[1].taskName == taskList1[1].taskName);
			Assert::IsTrue(newTaskList[1].startingTime == taskList1[1].startingTime);
			Assert::IsTrue(newTaskList[1].endingTime == taskList1[1].endingTime);
			Assert::IsTrue(newTaskList[1].status == taskList1[1].status);

			newTaskList = histryStorage.redo();
			size6 = newTaskList.size();
			Assert::AreEqual(size6, 3);

			//after two redo, taskList obtained should be same as the tasklist2 
			Assert::IsTrue(newTaskList[0].taskName == taskList2[0].taskName);
			Assert::IsTrue(newTaskList[0].startingTime == taskList2[0].startingTime);
			Assert::IsTrue(newTaskList[0].endingTime == taskList2[0].endingTime);
			Assert::IsTrue(newTaskList[0].status == taskList2[0].status);

			Assert::IsTrue(newTaskList[1].taskName == taskList2[1].taskName);
			Assert::IsTrue(newTaskList[1].startingTime == taskList2[1].startingTime);
			Assert::IsTrue(newTaskList[1].endingTime == taskList2[1].endingTime);
			Assert::IsTrue(newTaskList[1].status == taskList2[1].status);

			Assert::IsTrue(newTaskList[2].taskName == taskList2[2].taskName);
			Assert::IsTrue(newTaskList[2].startingTime == taskList2[2].startingTime);
			Assert::IsTrue(newTaskList[2].endingTime == taskList2[2].endingTime);
			Assert::IsTrue(newTaskList[2].status == taskList2[2].status);

			redoStack = histryStorage.getRedoStorageList();
			undoStack = histryStorage.getUndoStorageList();
			size5 = redoStack.size();
			size4 = undoStack.size();
			Assert::AreEqual(size5, 0);
			Assert::AreEqual(size4, 2);
		}

		TEST_METHOD(testCheckUndoEmpty)
		{
			vector<Task> newTaskList;
			
			Task testTask1;
			testTask1.setTaskName("ABC");
			testTask1.setStartingTime ("0000");
			testTask1.setEndingTime ("2359");
			testTask1.setDone ("DONE");
			newTaskList.push_back(testTask1);
			
			History historyStorage;
			Assert::IsTrue(historyStorage.checkUndoEmpty() == false);

			historyStorage.saveOperation(newTaskList);
			Assert::IsTrue(historyStorage.checkUndoEmpty() == true);
			
		}

		TEST_METHOD(testCheckRedoEmpty)
		{
			History historyStorage;
			Assert::IsTrue (historyStorage.checkRedoEmpty() == false);

			vector<Task> testTaskList1;
			vector<Task> testTaskList2;
			Task testTask1;
			testTask1.setTaskName("ABC");
			testTask1.setStartingTime ("0000");
			testTask1.setEndingTime ("2359");
			testTask1.setDone ("DONE");
			testTaskList1.push_back(testTask1);
			historyStorage.saveOperation(testTaskList1);

			Task testTask2;
			testTask2.setTaskName("AAA");
			testTask2.setStartingTime ("1111");
			testTask2.setEndingTime ("2200");
			testTask2.setDone ("DONE");
			testTaskList2.push_back(testTask1);
			testTaskList2.push_back(testTask2);
			historyStorage.saveOperation(testTaskList2);
			
			vector<Task> newTaskList;
			newTaskList = historyStorage.undo();
			Assert::IsTrue (historyStorage.checkRedoEmpty() == true);
		
		}

	};
}