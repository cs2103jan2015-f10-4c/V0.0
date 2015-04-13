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
		
		TEST_METHOD(addTask1)
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

		}

		//TEST_METHOD(addTask2)
		//{
		//	Logic testLogic;
		//	string userCommand;

		//	//add command invalid
		//	userCommand = "add;meeting;11/04/2015;10/04/2015";
		//	testLogic.executeUserCommand(userCommand);
		//	
		//	

		//}

		TEST_METHOD(deleteTask)
		{
			Logic testLogic;
			string task1 = "add;assignment;11may2015 23:59";
			string task2 = "add;reply email";
			string task3 = "add;lecture;10may2015 1030am;10may2015 1130am";

			testLogic.executeUserCommand(task1);
			testLogic.executeUserCommand(task2);
			testLogic.executeUserCommand(task3);

			//delete deadline task
			string userCommand = "delete;1";
			testLogic.executeUserCommand(userCommand);

			int size = testLogic.taskList.size();
			int expectedSize = 2;
			Assert::AreEqual(size, expectedSize);

			Assert::IsTrue(testLogic.taskList[0].taskName == "reply email");
			Assert::IsTrue(testLogic.taskList[0].type == DEFAULT_TYPE_THREE);

			Assert::IsTrue(testLogic.taskList[1].taskName == "lecture");
			Assert::IsTrue(testLogic.taskList[1].startingTime == "10-05-2015 10:30");
			Assert::IsTrue(testLogic.taskList[1].endingTime == "10-05-2015 11:30");
			Assert::IsTrue(testLogic.taskList[1].type == DEFAULT_TYPE_ONE);

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

		}

		TEST_METHOD(addDirectory)
		{
			Logic testLogic;
			string userCommand;

			userCommand = "directory;C:\\Users\\Jason\\Desktop";
			testLogic.executeUserCommand(userCommand);

			ifstream read("myAppConfig.txt");
			string line;
			getline(read, line);
			Assert::IsTrue(line == "C:\Users\Jason\Desktop\rushhour.txt");

		}
	};
}