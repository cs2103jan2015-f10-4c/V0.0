//@author A0116363L 

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		//display and display window will be tested together
		//the get functions are privtae methods therefore could not be tested
		TEST_METHOD(display_setDefaultDisplay) 
		{
			Display display;
			Task testTask1;
			testTask1.setTaskName("buy milk");
			testTask1.setStartingTime("");
			testTask1.setEndingTime("");
			testTask1.setDone("done");

			Task testTask2;
			testTask2.setTaskName("tutorial");
			testTask2.setStartingTime("1111");
			testTask2.setEndingTime("2200");
			testTask2.setDone("done");

			Task testTask3;
			testTask3.setTaskName("buy breakfast");
			testTask3.setStartingTime("");
			testTask3.setEndingTime("10/5");
			testTask3.setDone("ongoing");

			vector<Task> taskList;
			taskList.push_back(testTask1);
			taskList.push_back(testTask2);
			taskList.push_back(testTask3);

			display.setDefaultDisplay(taskList);
			string actualOutput = display.getContent();
			ostringstream oss;
			oss << "[1.][buy milk][][][done]"
				<< endl
				<< "[2.][tutorial][1111][2200][done]"
				<< endl
				<< "[3.][buy breakfast][][10/5][ongoing]"
				<< endl;
			//since the time is not parsed by the parser,they will not be displayed in a standard format
			string expectedOutput = oss.str();
			Assert::AreEqual(expectedOutput, actualOutput);

			taskList.clear();//to test a empty tasklist
			display.setDefaultDisplay(taskList);
			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(display_setVariousDisplay)
		{
			string FLOATING_TASK = "floating";
			string DEADLINE_TASK = "deadline";
			string TIMED_TASK = "timed";
			Display display;
			Task testTask1;
			testTask1.setTaskName("buy milk");
			testTask1.setStartingTime("");
			testTask1.setEndingTime("");
			testTask1.setDone("done");
			testTask1.setType(FLOATING_TASK);
			//floating & done type

			Task testTask2;
			testTask2.setTaskName("tutorial");
			testTask2.setStartingTime("1111");
			testTask2.setEndingTime("2200");
			testTask2.setDone("overdue");
			testTask1.setType(TIMED_TASK);
			//timed & overdue

			Task testTask3;
			testTask3.setTaskName("buy breakfast");
			testTask3.setStartingTime("");
			testTask3.setEndingTime("10/5");
			testTask3.setDone("ongoing");
			testTask1.setType(DEADLINE_TASK);
			//deadline& ongoing

			vector<Task> taskList;
			taskList.push_back(testTask1);
			taskList.push_back(testTask2);
			taskList.push_back(testTask3);

			
			string OVERDUE_TASK = "overdue";
			string DONE_TASK = "done";
			string ONGOING_TASK = "ongoing";
			string ALL_TASK = "all";
			string INVALID_DISPLAYTYPE = "This display type is invalid";
			string NO_DEADLINE = "There is no deadline task";
			string NO_TIMED = "There is no timed task";
			string NO_FLOATING = "There is no floating task";
			string NO_DONE = "There is no done task";
			string NO_OVERDUE = "There is no overdue task";
			string NO_ONGOING = "There is no ongoing task";
			string DISPLAYED = "The target tasklist has been displayed";

			string actualResp = display.setVariousDisplay(taskList, ALL_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			string actualOutput = display.getContent();
			ostringstream oss;
			oss << "[1.][buy milk][][][done]"
				<< endl
				<< "[2.][tutorial][1111][2200][overdue]"
				<< endl
				<< "[3.][buy breakfast][][10/5][ongoing]"
				<< endl;
			//since the time is not parsed by the parser,they will not be displayed in a standard format
			string expectedOutput = oss.str();
			Assert::AreEqual(expectedOutput, actualOutput);

			//to test invalid displaytype
			actualResp = display.setVariousDisplay(taskList, "completed");
			Assert::AreEqual(INVALID_DISPLAYTYPE, actualResp);

			actualOutput = display.getContent();
			//expectedOutput will not be changed since the setContent function is not called.
			Assert::AreEqual(expectedOutput, actualOutput);
		}

			////////////////////////////////////////////////////////////////////////
			//Assertion failed

			TEST_METHOD(display_various){

            Display display;
			Task testTask1;
			testTask1.setTaskName("buy milk");
			testTask1.setStartingTime("");
			testTask1.setEndingTime("");
			testTask1.setDone("done");
			testTask1.type ="floating";
			//floating & done type

			Task testTask2;
			testTask2.setTaskName("tutorial");
			testTask2.setStartingTime("1111");
			testTask2.setEndingTime("2200");
			testTask2.setDone("overdue");
			testTask1.type="timed";
			//timed & overdue

			Task testTask3;
			testTask3.setTaskName("buy breakfast");
			testTask3.setStartingTime("");
			testTask3.setEndingTime("10/5");
			testTask3.setDone("ongoing");
			testTask1.type="deadline";
			//deadline& ongoing

			vector<Task> taskList;
			taskList.push_back(testTask1);
			taskList.push_back(testTask2);
			taskList.push_back(testTask3);

			string FLOATING_TASK = "floating";
			string DEADLINE_TASK = "deadline";
			string TIMED_TASK = "timed";
			string OVERDUE_TASK = "overdue";
			string DONE_TASK = "done";
			string ONGOING_TASK = "ongoing";
			string ALL_TASK = "all";
			string INVALID_DISPLAYTYPE = "This display type is invalid";
			string NO_DEADLINE = "There is no deadline task";
			string NO_TIMED = "There is no timed task";
			string NO_FLOATING = "There is no floating task";
			string NO_DONE = "There is no done task";
			string NO_OVERDUE = "There is no overdue task";
			string NO_ONGOING = "There is no ongoing task";
			string DISPLAYED = "The target tasklist has been displayed";


			string actualResp;
			string actualOutput;
			string expectedOutput;

			//to display timed
			actualResp = display.setVariousDisplay(taskList, TIMED_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][tutorial][1111][2200][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);


	        //to display floating
			actualResp = display.setVariousDisplay(taskList, FLOATING_TASK);	
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][buy milk][][][done]\n";
			Assert::AreEqual(expectedOutput, actualOutput);
		
			
			//to display deadline
			actualResp = display.setVariousDisplay(taskList, DEADLINE_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][buy breakfast][][10/5][ongoing]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			//Tasktypes are not working.....why???

			//to display ongoing
			actualResp = display.setVariousDisplay(taskList, ONGOING_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][buy breakfast][][10/5][ongoing]\n";
			Assert::AreEqual(expectedOutput, actualOutput);


			//to display done
			actualResp = display.setVariousDisplay(taskList, DONE_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][buy milk][][][done]\n";
			Assert::AreEqual(expectedOutput, actualOutput);


			//to display overdue
			actualResp = display.setVariousDisplay(taskList, OVERDUE_TASK);
			Assert::AreEqual(DISPLAYED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "[1.][tutorial][1111][2200][overdue]\n";
			Assert::AreEqual(expectedOutput, actualOutput);

			
			taskList.clear();//to test no target type for display

			//to display floating
			actualResp = display.setVariousDisplay(taskList, FLOATING_TASK);
			Assert::AreEqual(NO_FLOATING, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);


			//to display timed
			actualResp = display.setVariousDisplay(taskList, TIMED_TASK);
			Assert::AreEqual(NO_TIMED, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);

			//to display deadline
			actualResp = display.setVariousDisplay(taskList, DEADLINE_TASK);
			Assert::AreEqual(NO_DEADLINE, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);

			//to display ongoing
			actualResp = display.setVariousDisplay(taskList, ONGOING_TASK);
			Assert::AreEqual(NO_ONGOING, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);


			//to display done
			actualResp = display.setVariousDisplay(taskList, DONE_TASK);
			Assert::AreEqual(NO_DONE, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);


			//to display overdue
			actualResp = display.setVariousDisplay(taskList, OVERDUE_TASK);
			Assert::AreEqual(NO_OVERDUE, actualResp);

			actualOutput = display.getContent();
			expectedOutput = "";
			Assert::AreEqual(expectedOutput, actualOutput);
		}

	};
}