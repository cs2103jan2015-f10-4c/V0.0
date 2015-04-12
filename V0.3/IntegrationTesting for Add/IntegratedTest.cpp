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
		//	SystemResponse test;
		//	string userCommand;

		//	//add command invalid
		//	userCommand = "add;meeting;11/04/2015;10/04/2015";
		//	testLogic.executeUserCommand(userCommand);
		//	
		//	

		//}

	};
}