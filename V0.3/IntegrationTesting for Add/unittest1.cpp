#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;
const string DEFAULT_TYPE_ONE = "timed";
const string DEFAULT_TYPE_TWO = "deadline";
const string DEFAULT_TYPE_THREE = "floating";


namespace IntegrationTesting
{		
	TEST_CLASS(IntegrationTest)
	{
	public:
		
		TEST_METHOD(addTask)
		{
			Logic* logic = new Logic();
			string userCommand;
			userCommand = "add;tutorial;01-01-2015 0900;01-01-2015 1000";
			logic->executeUserCommand(userCommand);
			string taskName = "tutorial";
			string startTime = "01-01-2015 0900";
			string endTime = "01-01-2015 1000";
			string type = DEFAULT_TYPE_ONE;
			Assert::IsTrue(logic->taskList[0].taskName == taskName);
			Assert::IsTrue(logic->taskList[0].startingTime == startTime);
			Assert::IsTrue(logic->taskList[0].endingTime == endTime);
			Assert::IsTrue(logic->taskList[0].type == type);

			userCommand = "add;assignment;02-02-2015 2359";
			logic->executeUserCommand(userCommand);
			taskName = "assignment";
			startTime = "";
			endTime = "02-02-2015 2359";
			type = DEFAULT_TYPE_TWO;
			Assert::IsTrue(logic->taskList[0].taskName == taskName);
			Assert::IsTrue(logic->taskList[0].startingTime == startTime);
			Assert::IsTrue(logic->taskList[0].endingTime == endTime);
			Assert::IsTrue(logic->taskList[0].type == type);

			userCommand = "add;meeting";
			logic->executeUserCommand(userCommand);
			taskName = "meeting";
			startTime = "";
			endTime = "";
			type = DEFAULT_TYPE_THREE;
			Assert::IsTrue(logic->taskList[0].taskName == taskName);
			Assert::IsTrue(logic->taskList[0].startingTime == startTime);
			Assert::IsTrue(logic->taskList[0].endingTime == endTime);
			Assert::IsTrue(logic->taskList[0].type == type);

			
		}

	};
}