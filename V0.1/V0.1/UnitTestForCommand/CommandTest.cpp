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
			string expectedResp = "Task 1 is deleted successfully";
			string actualResp = logic.tellGUIResponse();	
			Assert::AreEqual(expectedResp, actualResp);
			Assert::IsTrue(logic.taskList[0].taskName == "tutorial");
		

			logic.executeUserCommand("delete;1");
			Assert::IsTrue(logic.taskList[0].taskName == "buy breakfast");


		}

		TEST_METHOD(test_delete2){// test for boundary case deletion

			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;tutorial;6/4 9:00");
			logic.executeUserCommand("add;buy breakfast");

			//invalid index deletion
			logic.executeUserCommand("delete;0");
			string expectedResp = "Failed to delete the task. Task \"0\" is not in the list.";
			string actualResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedResp, actualResp);
			Assert::IsTrue(logic.taskList[0].taskName == "buy milk");

			logic.executeUserCommand("delete;4");
			Assert::IsTrue(logic.taskList[0].taskName == "buy milk");
			expectedResp = "Failed to delete the task. Task \"4\" is not in the list.";
			actualResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedResp, actualResp);


		}
		//for display all
		TEST_METHOD(test_display1){

			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;all");
			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][buy milk][][][ongoing]\n[2.][complete tutorial][][04-05-2015 09:00][done]\n[3.][have breakfast][02-03-2015 09:00][04-06-2015 10:00][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);
	        
			//test for invalid dispaly type
			logic.executeUserCommand("display;nothing");
		    actualResp = logic.tellGUIResponse();
			expectedResp = "This display type is invalid";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
		    expectedOutput = "[1.][buy milk][][][ongoing]\n[2.][complete tutorial][][04-05-2015 09:00][done]\n[3.][have breakfast][02-03-2015 09:00][04-06-2015 10:00][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);


		}

		//for display floating
		TEST_METHOD(test_display2){

			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;floating");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][buy milk][][][ongoing]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;floating");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no floating task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);


		}

		//for display deadline
		TEST_METHOD(test_display3){
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;deadline");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][complete tutorial][][04-05-2015 09:00][done]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;deadline");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no deadline task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		//for display timed
		TEST_METHOD(test_display4){
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;timed");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][have breakfast][02-03-2015 09:00][04-06-2015 10:00][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;timed");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no timed task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		//for display ongoing 
		TEST_METHOD(test_display5){
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;ongoing");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][buy milk][][][ongoing]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;ongoing");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no ongoing task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}


		//for display overdue
		TEST_METHOD(test_display6){
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;overdue");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][have breakfast][02-03-2015 09:00][04-06-2015 10:00][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;overdue");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no overdue task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		//for display done
		TEST_METHOD(test_display7){
			Logic logic;
			logic.executeUserCommand("add;buy milk");
			logic.executeUserCommand("add;complete tutorial;04-05-2015 09:00");
			logic.executeUserCommand("add;have breakfast;02-03-2015 09:00;04-06-2015 10:00");
			logic.executeUserCommand("mark done;2");
			logic.taskList[2].setDone("overdue");
			logic.executeUserCommand("display;done");

			string actualResp = logic.tellGUIResponse();
			string expectedResp = "The target tasklist has been displayed";
			Assert::AreEqual(expectedResp, actualResp);
			string actualOutput = logic.tellGUI();
			string expectedOutput = "[1.][complete tutorial][][04-05-2015 09:00][done]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			logic.taskList.clear();
			logic.executeUserCommand("display;done");

			actualResp = logic.tellGUIResponse();
			expectedResp = "There is no done task";
			Assert::AreEqual(expectedResp, actualResp);
			actualOutput = logic.tellGUI();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
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