#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;




namespace LogicTest
{		
	TEST_CLASS(UnitTestLogic)
	{
	public:
		
		TEST_METHOD(TestAdd)
		{
			Logic logic;
			//test case 1 to add a floating task
			logic.executeUserCommand("add;tut");
			Assert::IsTrue(1 == logic.taskList.size());
			string expectedSysResp1 = "The task is added successfully.";
			string actualSysResp1 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp1, actualSysResp1);
			//test case 2 to add in wrong input format
			logic.executeUserCommand("add;");
			Assert::IsTrue(1 == logic.taskList.size());
			//test case 3 to add in wrong input format and test respective systemResponse
			logic.executeUserCommand("add");
			string expectedSysResp2 = "Failed to add task. Please enter in the correct format.";
			string actualSysResp2 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp2, actualSysResp2);
			//test case 4 to add in wrong time sequence and test respective systemResponse
			logic.executeUserCommand("add;meeting;20/4 12:00;20/4 9:00");
			string expectedSysResp3 = "Failed to add task. Starting time is later than ending time.";
			string actualSysResp3 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp3, actualSysResp3);
			//test case 5 to add a deadline task
			logic.executeUserCommand("add;cs submission;13/4 2359");
			Assert::IsTrue(logic.taskList[1].type == "deadline");
			//test case 6 to add a timed task
			logic.executeUserCommand("add;meeting;20/4 9:00;20/4 12:00");
			Assert::IsTrue(logic.taskList[2].type == "timed");
		}

		TEST_METHOD(TestDelete)
		{
			Logic logic;
			logic.executeUserCommand("add;tut");
			logic.executeUserCommand("add;meeting");
			logic.executeUserCommand("delete;1");
			Assert::IsTrue(1 == logic.taskList.size());
			string expectedSysResp1 = "Task 1 is deleted successfully.";
			string actualSysResp1 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp1, actualSysResp1);
			logic.executeUserCommand("delete;5");
			Assert::IsTrue(1 == logic.taskList.size());
			string expectedSysResp2 = "Failed to delete the task. Task \"5\" is not in the list."; 
			string actualSysResp2 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp2, actualSysResp2);
		}

		TEST_METHOD(TestEdit)
		{
			Logic logic;
			logic.executeUserCommand("add;meeting");
			logic.executeUserCommand("add;meeting");
			logic.executeUserCommand("add;meeting");
			//test case 1 is to test auto editing to deadline type
			logic.executeUserCommand("edit;1;submit report;15/4 13:00");
			Assert::IsTrue(logic.taskList[0].endingTime == "15-04-2015 13:00");   
			Assert::IsTrue(logic.taskList[0].type == "deadline");
			string expectedSysResp1 = "Task 1 is edited successfully.";
			string actualSysResp1 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp1, actualSysResp1);
		    //test case 2 is to test auto editing to timed type
			logic.executeUserCommand("edit;2;tut;15/4 9:00;15/4 10:00");
			Assert::IsTrue(logic.taskList[1].type == "timed");
			//test case 3 to test index out of bound
			logic.executeUserCommand("edit;5;exercise;14/4 14:00;14/4 15:00");
			Assert::IsTrue(logic.taskList[0].type == "deadline");
			Assert::IsTrue(logic.taskList[1].taskName == "tut");
			Assert::IsTrue(logic.taskList[2].startingTime == "");
			string expectedSysResp2 = "Fail to edit task. Task \"5\" is not in the list.";
			string actualSysResp2 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp2, actualSysResp2);
		}

		TEST_METHOD(TestSearch)
		{
			Logic logic;
			logic.executeUserCommand("add;tut;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;tut1");
			logic.executeUserCommand("add;meeting;15/4 10:00");
			logic.executeUserCommand("add;work;16/4 9:00;16/4 10:00");
			logic.executeUserCommand("add;tut2;14/4 9:00;14/4 10:00");
			//test case 1 to test partial search
			logic.executeUserCommand("search;tut");
			string expectedSysResp1 = "Search Result is displayed.";
			string actualSysResp1 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp1, actualSysResp1);
			ostringstream oss1;
			oss1 << "[1.][tut][15-04-2015 09:00][15-04-2015 10:00][ongoing]"
				<< endl
				<< "[2.][tut1][][][ongoing]"
				<< endl
				<< "[3.][tut2][14-04-2015 09:00][14-04-2015 10:00][ongoing]"
				<< endl;
			string expectedResult11 = oss1.str();
			string actualResult11 = logic.tellGUI();
			Assert::AreEqual(expectedResult11, actualResult11);
			//test case 2 to test partial search
			logic.executeUserCommand("search;t");
			ostringstream oss2;
			oss2 << "[1.][tut][15-04-2015 09:00][15-04-2015 10:00][ongoing]"
				<< endl
				<< "[2.][tut1][][][ongoing]"
				<< endl
				<< "[3.][meeting][][15-04-2015 10:00][ongoing]"
				<< endl
				<< "[4.][tut2][14-04-2015 09:00][14-04-2015 10:00][ongoing]"
				<< endl;
			string expectedResult2 = oss2.str();
			string actualResult2 = logic.tellGUI();
			Assert::AreEqual(expectedResult2, actualResult2);
			//test case 3 to test no result fund
			logic.executeUserCommand("search;timed");
			string expectedSysResp3 = "There is no result found.";
			string actualSysResp3 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp3, actualSysResp3);
			ostringstream oss3;
			oss3 << "";
			string expectedResult33 = oss3.str();
			string actualResult33 = logic.tellGUI();
			Assert::AreEqual(expectedResult33, actualResult33);
			//test case 4 to test search in an empty list
            logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("delete;1");
			logic.executeUserCommand("search;tut");
			string expectedSysResp4 = "There is no result found.";
			string actualSysResp4 = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp4, actualSysResp4);
			ostringstream oss4;
			oss4 << "";
			string expectedResult44 = oss4.str();
			string actualResult44 = logic.tellGUI();
			Assert::AreEqual(expectedResult44, actualResult44);

		}

		TEST_METHOD(TestMarkDone)
		{
			Logic logic;
			logic.executeUserCommand("add;tut;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;meeting;15/4 10:00");
			//test case 1 to test mark done
			Assert::IsTrue(logic.taskList[0].status == "ongoing");
			logic.executeUserCommand("mark done;1");
			Assert::IsTrue(logic.taskList[0].status == "done");
			logic.executeUserCommand("mark done;3");
			Assert::IsTrue(logic.taskList[1].status == "ongoing");
		}

		TEST_METHOD(TestCheckIndex)
		{
			Logic logic;
			logic.executeUserCommand("add;tut;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;meeting;15/4 10:00");
			//test case 1 to test exceed range
			bool isInRange1 = logic.checkIndex(3);
			Assert::IsTrue(isInRange1 == false);
			//test case 2 to test below the range
			bool isInRange2 = logic.checkIndex(0);
			Assert::IsTrue(isInRange2 == false);
			//test case 3 to test within the range
			bool isInRange3 = logic.checkIndex(1);
			Assert::IsTrue(isInRange3 == true);

		}

		TEST_METHOD(TestClear)
		{
			Logic logic;
			logic.executeUserCommand("add;tut;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;meeting;15/4 10:00");
			logic.executeUserCommand("clear");
			string expectedSysResp = "The task list has been cleared.";
			string actualSysResp = logic.tellGUIResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			ostringstream oss;
			oss << "";
			string expectedResult1 = oss.str();
			string actualResult1 = logic.tellGUI();
			Assert::AreEqual(expectedResult1, actualResult1);
		}

		TEST_METHOD(TestDisplayVariousType) //not finished
		{
			Logic logic;
			logic.executeUserCommand("add;tut;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;meeting;15/4 10:00");
			logic.executeUserCommand("add;work;15/4 9:00;15/4 10:00");
			logic.executeUserCommand("add;presentation;12/4 10:00");

		}

	};
}
