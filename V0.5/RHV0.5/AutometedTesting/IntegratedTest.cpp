//@author A0114946B

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
const string DEFAULT_TYPE_ONE = "timed";
const string DEFAULT_TYPE_TWO = "deadline";
const string DEFAULT_TYPE_THREE = "floating";


namespace sysTest
{		
	TEST_CLASS(IntegrationTest)
	{
	public:
		
		TEST_METHOD(test_add1)
		{
			Logic* logic = new Logic();
			string userCommand;
			
			//test for timed task
			userCommand = "add;tutorial;01-01-2015 0900;01-01-2015 1000";
			logic->executeUserCommand(userCommand);
			string taskName = "tutorial";
			string startTime = "01-01-2015 09:00";
			string endTime = "01-01-2015 10:00";
			string type = DEFAULT_TYPE_ONE;
			Assert::IsTrue(logic->taskList[0].taskName == taskName);
			Assert::IsTrue(logic->taskList[0].startingTime == startTime);
			Assert::IsTrue(logic->taskList[0].endingTime == endTime);
			Assert::IsTrue(logic->taskList[0].type == type);

			string output = logic->tellGUIResponse();
			string expectedOutput = "The task is added successfully.";
			Assert::AreEqual(output, expectedOutput);

			//test for deadline task
			userCommand = "add;assignment;02-02-2015 2359";
			logic->executeUserCommand(userCommand);
			taskName = "assignment";
			startTime = "";
			endTime = "02-02-2015 23:59";
			type = DEFAULT_TYPE_TWO;
			Assert::IsTrue(logic->taskList[1].taskName == taskName);
			Assert::IsTrue(logic->taskList[1].startingTime == startTime);
			Assert::IsTrue(logic->taskList[1].endingTime == endTime);
			Assert::IsTrue(logic->taskList[1].type == type);

			output = logic->tellGUIResponse();
			expectedOutput = "The task is added successfully.";
			Assert::AreEqual(output, expectedOutput);

			//test for floating task
			userCommand = "add;meeting";
			logic->executeUserCommand(userCommand);
			taskName = "meeting";
			startTime = "";
			endTime = "";
			type = DEFAULT_TYPE_THREE;
			Assert::IsTrue(logic->taskList[2].taskName == taskName);
			Assert::IsTrue(logic->taskList[2].startingTime == startTime);
			Assert::IsTrue(logic->taskList[2].endingTime == endTime);
			Assert::IsTrue(logic->taskList[2].type == type);

			output = logic->tellGUIResponse();
			expectedOutput = "The task is added successfully.";
			Assert::AreEqual(output, expectedOutput);
		}

		TEST_METHOD(test_add2)
		{
			Logic testLogic;
			string userCommand;

			//add command invalid
			userCommand = "add2";
			testLogic.executeUserCommand(userCommand);
			int size = testLogic.taskList.size();
			int expectedSize = 0;

			Assert::AreEqual(size, expectedSize);
			string output = testLogic.tellGUIResponse();
			string expectedOutput = "Command invalid, please re-enter.";
			Assert::AreEqual(output, expectedOutput);

			//add format invalid
			userCommand = "add;";
			testLogic.executeUserCommand(userCommand);
			size = testLogic.taskList.size();
			expectedSize = 0;

			Assert::AreEqual(size, expectedSize);
			output = testLogic.tellGUIResponse();
			expectedOutput = "Failed to add task. Please enter in the correct format.";
			Assert::AreEqual(output, expectedOutput);

			//add timing invalid
			userCommand = "add;meeting;11may;10may";
			testLogic.executeUserCommand(userCommand);
			size = testLogic.taskList.size();
			expectedSize = 0;
			Assert::AreEqual(size, expectedSize);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Failed to add task. Starting time is later than ending time.";
			Assert::AreEqual(output, expectedOutput);

			
		}

		TEST_METHOD(test_delete1)
		{
			Logic testLogic;
			string task1 = "add;assignment;11may2015 23:59";
			string task2 = "add;reply email";
			string task3 = "add;lecture;10may2015 1030am;10may2015 1130am";

			testLogic.executeUserCommand(task1);
			testLogic.executeUserCommand(task2);
			testLogic.executeUserCommand(task3);

			//delete index is out of range
			string userCommand = "delete;10";
			testLogic.executeUserCommand(userCommand);
			
			int size = testLogic.taskList.size();
			int expectedSize = 3;
			Assert::AreEqual(size, expectedSize);

			string output = testLogic.tellGUIResponse();
			string expectedOutput = "Failed to delete the task. Task \"10\" is not in the list.";
			Assert::AreEqual(output, expectedOutput);
			
			//delete deadline task
			userCommand = "delete;1";
			testLogic.executeUserCommand(userCommand);

			size = testLogic.taskList.size();
			expectedSize = 2;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "reply email");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_THREE);

			Assert::IsTrue(testLogic.taskList[1].taskName == "lecture");
			Assert::IsTrue(testLogic.taskList[1].startingTime == "10-05-2015 10:30");
			Assert::IsTrue(testLogic.taskList[1].endingTime == "10-05-2015 11:30");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_ONE);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Task 1 is deleted successfully.";
			Assert::AreEqual(output, expectedOutput);

			//test for undo 
			userCommand = "undo";
			testLogic.executeUserCommand(userCommand);
			size = testLogic.taskList.size();
			expectedSize = 3;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "assignment");
			Assert::IsTrue(testLogic.taskList[0].endingTime == "11-05-2015 23:59");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_TWO);
			
			Assert::IsTrue(testLogic.taskList[1].taskName == "reply email");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_THREE);

			Assert::IsTrue(testLogic.taskList[2].taskName == "lecture");
			Assert::IsTrue(testLogic.taskList[2].startingTime == "10-05-2015 10:30");
			Assert::IsTrue(testLogic.taskList[2].endingTime == "10-05-2015 11:30");
			Assert::IsTrue(testLogic.taskList[2].type == DEFAULT_TYPE_ONE);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Undo successful.";
			Assert::AreEqual(output, expectedOutput);

			//delete floating task
			userCommand = "delete;2";
			testLogic.executeUserCommand(userCommand);

			size = testLogic.taskList.size();
			expectedSize = 2;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "assignment");
			Assert::IsTrue(testLogic.taskList[0].endingTime == "11-05-2015 23:59");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_TWO);

			Assert::IsTrue(testLogic.taskList[1].taskName == "lecture");
			Assert::IsTrue(testLogic.taskList[1].startingTime == "10-05-2015 10:30");
			Assert::IsTrue(testLogic.taskList[1].endingTime == "10-05-2015 11:30");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_ONE);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Task 2 is deleted successfully.";
			Assert::AreEqual(output, expectedOutput);

			userCommand = "undo";
			testLogic.executeUserCommand(userCommand);
			size = testLogic.taskList.size();
			expectedSize = 3;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "assignment");
			Assert::IsTrue(testLogic.taskList[0].endingTime == "11-05-2015 23:59");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_TWO);
			
			Assert::IsTrue(testLogic.taskList[1].taskName == "reply email");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_THREE);

			Assert::IsTrue(testLogic.taskList[2].taskName == "lecture");
			Assert::IsTrue(testLogic.taskList[2].startingTime == "10-05-2015 10:30");
			Assert::IsTrue(testLogic.taskList[2].endingTime == "10-05-2015 11:30");
			Assert::IsTrue(testLogic.taskList[2].type == DEFAULT_TYPE_ONE);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Undo successful.";
			Assert::AreEqual(output, expectedOutput);

			//delete timed task
			userCommand = "delete;3";
			testLogic.executeUserCommand(userCommand);

			size = testLogic.taskList.size();
			expectedSize = 2;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "assignment");
			Assert::IsTrue(testLogic.taskList[0].endingTime == "11-05-2015 23:59");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_TWO);

			Assert::IsTrue(testLogic.taskList[1].taskName == "reply email");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_THREE);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Task 3 is deleted successfully.";
			Assert::AreEqual(output, expectedOutput);

			userCommand = "undo";
			testLogic.executeUserCommand(userCommand);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Undo successful.";
			Assert::AreEqual(output, expectedOutput);
			

		}

		TEST_METHOD(test_clear)
		{
			Logic testLogic;
			string task1 = "add;assignment;11may2015 23:59";
			string task2 = "add;reply email";
			string task3 = "add;lecture;10may2015 1030am;10may2015 1130am";

			testLogic.executeUserCommand(task1);
			testLogic.executeUserCommand(task2);
			testLogic.executeUserCommand(task3);

			int size = testLogic.taskList.size();
			int expectedSize = 3;
			Assert::AreEqual(size, expectedSize);

			string userCommand = "clear";
			testLogic.executeUserCommand(userCommand);

			size = testLogic.taskList.size();
			expectedSize = 0;
			Assert::AreEqual(size, expectedSize);

			string output = testLogic.tellGUIResponse();
			string expectedOutput = "The task list has been cleared.";
			Assert::AreEqual(output, expectedOutput);

		}

		TEST_METHOD(test_UndoRedo)
		{
			Logic testLogic;
			string userCommand;

			string task1 = "add;assignment;11may2015 23:59";
			
			testLogic.executeUserCommand(task1);
			int size = testLogic.taskList.size();
			int expectedSize = 1;
			Assert::AreEqual(size, expectedSize);

			//test for redo fail case
			userCommand = "redo";
			testLogic.executeUserCommand(userCommand);
			string output = testLogic.tellGUIResponse();
			string expectedOutput = "Failed to redo. No undo action performed.";
			Assert::AreEqual(output, expectedOutput);

			//test for undo success case
			userCommand = "undo";
			testLogic.executeUserCommand(userCommand);

			size = testLogic.taskList.size();
			expectedSize = 0;
			Assert::AreEqual(size, expectedSize);
			output = testLogic.tellGUIResponse();
			expectedOutput = "Undo successful.";
			Assert::AreEqual(output, expectedOutput);

			//test for undo fail case
			userCommand = "undo";
			testLogic.executeUserCommand(userCommand);

			output = testLogic.tellGUIResponse();
			expectedOutput = "Failed to undo. Exceed number of actions performed.";
			Assert::AreEqual(output, expectedOutput);

			//test for redo success case
			userCommand = "redo";
			testLogic.executeUserCommand(userCommand);
			output = testLogic.tellGUIResponse();
			expectedOutput = "Redo successful.";
			Assert::AreEqual(output, expectedOutput);

			size = testLogic.taskList.size();
			expectedSize = 1;
			Assert::AreEqual(size, expectedSize);

		}

//@author A0134921L
		TEST_METHOD(test_edit)
		{
			Logic* logic = new Logic();
			string userCommand;
			

			userCommand = "add;tutorial;01-01-2015 0900;01-01-2015 1000";
			logic->executeUserCommand(userCommand);
			userCommand = "add;assignment;02-02-2015 2359";
			logic->executeUserCommand(userCommand);
			userCommand = "add;meeting";
			logic->executeUserCommand(userCommand);

			//test for edit fail
			userCommand = "edit;5;meeting;01-02-2013 11:30;02-11-2013 12:00";
			logic->executeUserCommand(userCommand);
			string output = logic->tellGUIResponse();
			string expectedOutput = "Fail to edit task. Task \"5\" is not in the list.";
			Assert::AreEqual(output, expectedOutput);

			//test for timed task
			userCommand = "edit;1;meeting;01-02-2013 11:30;02-11-2013 12:00";
			logic->executeUserCommand(userCommand);
			string taskName = "meeting";
			string startTime = "01-02-2013 11:30";
			string endTime = "02-11-2013 12:00";
			string type = DEFAULT_TYPE_ONE;
			Assert::IsTrue(logic->taskList[0].taskName == taskName);
			Assert::IsTrue(logic->taskList[0].startingTime == startTime);
			Assert::IsTrue(logic->taskList[0].endingTime == endTime);
			Assert::IsTrue(logic->taskList[0].type == type);

			output = logic->tellGUIResponse();
			expectedOutput = "Task 1 is edited successfully.";
			Assert::AreEqual(output, expectedOutput);

			//test for deadline task
			userCommand = "edit;2;project deadline;03-03-2015 1159";
			logic->executeUserCommand(userCommand);
			taskName = "project deadline";
			startTime = "";
			endTime = "03-03-2015 11:59";
			type = DEFAULT_TYPE_TWO;
			Assert::IsTrue(logic->taskList[1].taskName == taskName);
			Assert::IsTrue(logic->taskList[1].startingTime == startTime);
			Assert::IsTrue(logic->taskList[1].endingTime == endTime);
			Assert::IsTrue(logic->taskList[1].type == type);

			output = logic->tellGUIResponse();
			expectedOutput = "Task 2 is edited successfully.";
			Assert::AreEqual(output, expectedOutput);
			
			//test for floating task
			userCommand = "edit;3;studing";
			logic->executeUserCommand(userCommand);
			taskName = "studing";
			startTime = "";
			endTime = "";
			type = DEFAULT_TYPE_THREE;
			Assert::IsTrue(logic->taskList[2].taskName == taskName);
			Assert::IsTrue(logic->taskList[2].startingTime == startTime);
			Assert::IsTrue(logic->taskList[2].endingTime == endTime);
			Assert::IsTrue(logic->taskList[2].type == type);

			output = logic->tellGUIResponse();
			expectedOutput = "Task 3 is edited successfully.";
			Assert::AreEqual(output, expectedOutput);





		}

	};
}