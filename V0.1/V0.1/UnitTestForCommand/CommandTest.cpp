//@author A0116363L
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForCommand
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(test_delete1){// test for normal deletion

			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");

			logic.executeUserCommand("delete;1");
			Assert::IsTrue(logic.taskList[0].taskName == "tutorial");
			logic.executeUserCommand("delete;1");
			Assert::IsTrue(logic.taskList[0].taskName == "buy breakfast");





		}


		TEST_METHOD(test_search1)
		{
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");

			logic.executeUserCommand("search;u");
			string expectedSysResp = "Search Result is displayed.";
			string actualSysResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			ostringstream oss;
			oss << "[1.][buy milk][][][ongoing]"
				<< endl
				<< "[2.][tutorial][][06-04-2015 09:00][ongoing]"
				<< endl
				<< "[3.][buy breakfast][][][ongoing]"
				<< endl;
			string expectedResult = oss.str();
			string actualResult = logic.tellGUI();
			Assert::AreEqual(expectedResult, actualResult);


		}

		TEST_METHOD(test_search2){

			Logic logic;

			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");

			logic.executeUserCommand("search;buy");
			string expectedSysResp = "Search Result is displayed.";
			string actualSysResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			ostringstream oss2;
			oss2 << "[1.][buy milk][][][ongoing]"
				<< endl
				<< "[2.][buy breakfast][][][ongoing]"
				<< endl;
			string expectedResult = oss2.str();
			string actualResult = logic.tellGUI();
			Assert::AreEqual(expectedResult, actualResult);

		}
		TEST_METHOD(test_search3){// test no matching search
			Logic logic;

			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");

			logic.executeUserCommand("search;timed");
			string expectedSysResp = "There is no result found.";
			string actualSysResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			ostringstream oss3;
			oss3 << "";
			string expectedResult = oss3.str();
			string actualResult = logic.tellGUI();
			Assert::AreEqual(expectedResult, actualResult);
		}
		TEST_METHOD(test_search4){//test esearch empty

			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");


			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");


			//for the case when there is no task in the list"
			logic.executeUserCommand("search;timed");
			string expectedSysResp = "There is no result found.";
			string actualSysResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			ostringstream oss4;
			oss4 << "";
			string expectedResult = oss4.str();
			string actualResult = logic.tellGUI();
			Assert::AreEqual(expectedResult, actualResult);
		}
	};
}