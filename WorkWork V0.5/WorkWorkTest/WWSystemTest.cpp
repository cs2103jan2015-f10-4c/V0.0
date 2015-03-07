//@author A0097195N
//Description: All available commands to user are being tested
//             Each test case will include the testing of page index, system response,
//             and the list of tasks that will be displayed to the user
//             Different options of viewing will have a different page index 
//             System Response will display the feedback to inform the user 
//             the outcome of the last input he entered.
//             List of tasks contains all the tasks that the user has entered

#include "stdafx.h"
#include "CppUnitTest.h"
#include "WWUtilities.h"
#include "WWUI.h"

const int ALL_PAGE_INDEX                  = 0;
const int DEADLINE_PAGE_INDEX             = 1;
const int TIMED_PAGE_INDEX                = 2;
const int FLOATING_PAGE_INDEX             = 3;
const int TODAY_PAGE_INDEX                = 4;
const int COMPLETE_PAGE_INDEX             = 5;
const int INCOMPLETE_PAGE_INDEX           = 6;
const int OVERDUE_PAGE_INDEX              = 7;
const int SEARCH_PAGE_INDEX               = 8;

const std::string COMPLETE                = "complete";
const std::string INCOMPLETE              = "incomplete";
const std::string OVERDUE                 = "overdue";

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace WorkWorkTest
{
	TEST_CLASS(WWSystemTest)
	{
	public:
		//TC1: adding deadline task
		TEST_METHOD(test_addDeadline) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1 23nov", ALL_PAGE_INDEX);
			//checking of page index
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expected = "All floating task done!";
			std::string actual = WorkWork.getFloatingTask();
			Assert::AreEqual(expected, actual);
			//checking for appropriate system response
			std::string expectedSysResp = "taskname 1 created";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			//checking for the list of tasks shown to user
			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			//clearing all tasks previously entered
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC2: adding timed task
		TEST_METHOD(test_addTimed) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expected = "All floating task done!";
			std::string actual = WorkWork.getFloatingTask();
			Assert::AreEqual(expected,actual);

			std::string expectedSysResp = "taskname 2 created";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC3: adding floating task
		TEST_METHOD(test_addFloating) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 3", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expected = "taskname 3";
			std::string actual = WorkWork.getFloatingTask();
			Assert::AreEqual(expected, actual);

			std::string expectedSysResp = "taskname 3 created";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 3", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC4: deleting a negative index
		TEST_METHOD(test_delete_NegativeIndex) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 4", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete -1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expected = "taskname 4";
			std::string actual = WorkWork.getFloatingTask();
			Assert::AreEqual(expected, actual);

			std::string expectedSysResp = "Index not found";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			
			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 4", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC5: deleting an index that is out of range (only has 4 tasks but the user delete no.5)
		TEST_METHOD(test_delete_OutOfRangeIndex) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4", ALL_PAGE_INDEX);
			//trying to delete an invalid index(at the boundary)
			WorkWork.runProgram("delete 5", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);
			
			std::string expectedSysResp = "Index not found";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			//trying to delete an invalid index(not at the boundary)
			WorkWork.runProgram("delete 25", ALL_PAGE_INDEX);
			expectedSysResp = "Index not found";
			actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = { "taskname 1", "", INCOMPLETE};
			std::string array2[] = { "taskname 2", "", INCOMPLETE};
			std::string array3[] = { "taskname 3", "", INCOMPLETE};
			std::string array4[] = { "taskname 4", "", INCOMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3 );
			std::vector<std::string> test2 (array2, array2 + 3);
			std::vector<std::string> test3 (array3, array3 + 3);
			std::vector<std::string> test4 (array4, array4 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			expectedListOfTasks.push_back(test3);
			expectedListOfTasks.push_back(test4);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0], actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1], actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2], actualListOfTasks[1][2]);
			Assert::AreEqual(expectedListOfTasks[2][0], actualListOfTasks[2][0]);
			Assert::AreEqual(expectedListOfTasks[2][1], actualListOfTasks[2][1]);
			Assert::AreEqual(expectedListOfTasks[2][2], actualListOfTasks[2][2]);
			Assert::AreEqual(expectedListOfTasks[3][0], actualListOfTasks[3][0]);
			Assert::AreEqual(expectedListOfTasks[3][1], actualListOfTasks[3][1]);
			Assert::AreEqual(expectedListOfTasks[3][2], actualListOfTasks[3][2]);

			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC6: deleting an index that is valid 
		TEST_METHOD(test_delete_ValidIndex) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 2 deleted";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC7: editing the taskname of a task  
		TEST_METHOD(test_editTaskname) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("edit 1 taskname 3", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 3 edited";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 3", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC8: editing the task to a deadline task
		TEST_METHOD(test_edit_TaskToDeadlineTask) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("edit 1 23nov", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 1 edited";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC9: editing the task to a timed task
		TEST_METHOD(test_edit_TaskToTimedTask) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("edit 1 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 1 edited";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC10: testing the complete command
		TEST_METHOD(test_complete) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 3 23 Nov 2014", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 3 is marked as completed";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 3", "Due  : 23 Nov 2014", COMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);

			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			expectedSysResp = "taskname 3 is already completed";
			actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			actualListOfTasks = WorkWork.display();
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC11: testing the incomplete command
		TEST_METHOD(test_incomplete) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("incomplete 1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "taskname 4 is already incomplete";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 4", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);

			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("incomplete 1", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			expectedSysResp = "taskname 4 is marked as incomplete";
			actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);
			actualListOfTasks = WorkWork.display();
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC12: viewing different modes of display: in this case viewing all tasks
		TEST_METHOD(test_viewAll) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("view all", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0],actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1],actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2],actualListOfTasks[0][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}

		//TC13: viewing deadline tasks
		TEST_METHOD(test_viewDeadline) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("view deadline", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEDEADLINE);

			std::string expectedSysResp = "You have 1 deadline tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 4", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("view all", DEADLINE_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC14: viewing timed tasks
		TEST_METHOD(test_viewTimed) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1600h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("view timed", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGETIMED);

			std::string expectedSysResp = "You have 2 timed tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp, actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 3", "From: 11 Jan 2014, 06:00am\nTo     : 23 Jan 2014, 04:00pm", OVERDUE};
			std::string array2[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0], actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1], actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2], actualListOfTasks[1][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC15: viewing floating tasks
		TEST_METHOD(test_viewFloating) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("view floating", ALL_PAGE_INDEX);

			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEFLOATING);
			std::string expectedSysResp = "You have 1 floating tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array[] = {"taskname 1", "", INCOMPLETE};
			std::vector<std::string> test (array, array + 3);
			expectedListOfTasks.push_back(test);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC16: viewing completed tasks
		TEST_METHOD(test_viewComplete) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1400h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 3", ALL_PAGE_INDEX);
			WorkWork.runProgram("view complete", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEDONE);

			std::string expectedSysResp = "You have 2 completed tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 1","", COMPLETE};
			std::string array2[] = {"taskname 3", "From: 11 Jan 2014, 06:00am\nTo     : 23 Jan 2014, 02:00pm", COMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			Assert::AreEqual(expectedListOfTasks[0][0], actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1], actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2], actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0], actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1], actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2], actualListOfTasks[1][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC17: viewing incompleted tasks
		TEST_METHOD(test_viewIncomplete) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1400h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 3", ALL_PAGE_INDEX);
			WorkWork.runProgram("view incomplete", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEUNDONE);

			std::string expectedSysResp = "You have 2 incomplete tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::string array2[] = {"taskname 4", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			Assert::AreEqual(expectedListOfTasks[0][0],actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1],actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2],actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0],actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1],actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2],actualListOfTasks[1][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
		//TC18: viewing overdue tasks
		TEST_METHOD(test_viewOverdue) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1400h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("complete 3", ALL_PAGE_INDEX);
			WorkWork.runProgram("view overdue", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEOVERDUE);

			std::string expectedSysResp = "You have 2 overdue tasks in total";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::string array2[] = {"taskname 3", "From: 11 Jan 2014, 06:00am\nTo     : 23 Jan 2014, 02:00pm", COMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			Assert::AreEqual(expectedListOfTasks[0][0],actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1],actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2],actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0],actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1],actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2],actualListOfTasks[1][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);	
		}
		
		//TC19: testing the redo command
		TEST_METHOD(test_redo) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1400h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("undo", ALL_PAGE_INDEX);
			WorkWork.runProgram("redo", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "Redo successful";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::string array3[] = {"taskname 1", "", INCOMPLETE};
			std::string array2[] = {"taskname 4", "Due  : 23 Nov 2014", INCOMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			std::vector<std::string> test3 (array3, array3 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			expectedListOfTasks.push_back(test3);
			Assert::AreEqual(expectedListOfTasks[0][0],actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1],actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2],actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0],actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1],actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2],actualListOfTasks[1][2]);
			Assert::AreEqual(expectedListOfTasks[2][0],actualListOfTasks[2][0]);
			Assert::AreEqual(expectedListOfTasks[2][1],actualListOfTasks[2][1]);
			Assert::AreEqual(expectedListOfTasks[2][2],actualListOfTasks[2][2]);
			WorkWork.runProgram("view all", TIMED_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);		
		}

		//TC20: testing the uno command
		TEST_METHOD(test_undo) {
			WWUI WorkWork;
			WorkWork.runProgram("add taskname 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 2 11mar2014 0800h 23mar2014 2200h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 3 11jan2014 0600h 23jan2014 1400h", ALL_PAGE_INDEX);
			WorkWork.runProgram("add taskname 4 23nov", ALL_PAGE_INDEX);
			WorkWork.runProgram("undo", ALL_PAGE_INDEX);
			Assert::AreEqual(WorkWork.getPageIndex(), (int)WWUtilities::PAGEALL);

			std::string expectedSysResp = "Undo successful";
			std::string actualSysResp = WorkWork.displaySystemResponse();
			Assert::AreEqual(expectedSysResp,actualSysResp);

			std::vector<std::vector<std::string>> expectedListOfTasks; 
			std::vector<std::vector<std::string>> actualListOfTasks = WorkWork.display();
			std::string array1[] = {"taskname 3", "From: 11 Jan 2014, 06:00am\nTo     : 23 Jan 2014, 02:00pm", OVERDUE};
			std::string array2[] = {"taskname 2", "From: 11 Mar 2014, 08:00am\nTo     : 23 Mar 2014, 10:00pm", OVERDUE};
			std::string array3[] = {"taskname 1", "", INCOMPLETE};
			std::vector<std::string> test1 (array1, array1 + 3);
			std::vector<std::string> test2 (array2, array2 + 3);
			std::vector<std::string> test3 (array3, array3 + 3);
			expectedListOfTasks.push_back(test1);
			expectedListOfTasks.push_back(test2);
			expectedListOfTasks.push_back(test3);
			Assert::AreEqual(expectedListOfTasks[0][0],actualListOfTasks[0][0]);
			Assert::AreEqual(expectedListOfTasks[0][1],actualListOfTasks[0][1]);
			Assert::AreEqual(expectedListOfTasks[0][2],actualListOfTasks[0][2]);
			Assert::AreEqual(expectedListOfTasks[1][0],actualListOfTasks[1][0]);
			Assert::AreEqual(expectedListOfTasks[1][1],actualListOfTasks[1][1]);
			Assert::AreEqual(expectedListOfTasks[1][2],actualListOfTasks[1][2]);
			Assert::AreEqual(expectedListOfTasks[2][0],actualListOfTasks[2][0]);
			Assert::AreEqual(expectedListOfTasks[2][1],actualListOfTasks[2][1]);
			Assert::AreEqual(expectedListOfTasks[2][2],actualListOfTasks[2][2]);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
			WorkWork.runProgram("delete 1", ALL_PAGE_INDEX);
		}
		
	};
}