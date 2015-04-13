//@author A0134921L

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TEST_ADD_TIMED_TASK = "add;pj meeting;1/1/2012 1000;1-1-2012 1300";
const string TEST_ADD_TIMED_TASK1 = "add;pj meeting;3/3/2013 1000;1-1-2012 1300";
const string TEST_ADD_DEADLINE_TASK = "add;assignment1;1/1/2011 1300";
const string TEST_ADD_FLOATING_TASK = "add;reply email";
const string TEST_ADD_TASK = "add";

const string TEST_EDIT_TIMED_TASK = "edit;1;hw meeting;3/3/2013 1333;4/4/2014 1444";
const string TEST_EDIT_TIMED_TASK1 = "edit;1;hw meeting;5/5/2015 1500;4/4/2014 1400";
const string TEST_EDIT_DEADLINE_TASK = "edit;2;assignment2;5MAY2015 1555";
const string TEST_EDIT_FLOATING_TASK = "edit;3;send email";

const string TEST_DELETE_TASK = "delete;1";

const string TEST_SEARCH_TASK = "search;assignment";

const string TEST_MARKDONE_TASK = "mark done;2";

const string TEST_DISPLAY_TASK = "display;all";

const string TEST_UNDO_TASK = "undo;";

const string TEST_REDO_TASK = "redo;";

const string TEST_DIRECTORY_TASK = "directory;desktop";

const string TEST_CLEAR_TASK = "clear;";

const string TEST_EXIT_TASK = "exit;";

const string TEST_INVALID_INPUT = "2012-01-01;";

namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestParser)
	{
	public:
		
		TEST_METHOD(testCommandWord)
		{
			Parser parser;
			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "add");
			
			testInput = TEST_ADD_DEADLINE_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "add");

			testInput = TEST_ADD_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "add");

			testInput = TEST_EDIT_TIMED_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "edit");

			testInput = TEST_EDIT_DEADLINE_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "edit");

			testInput = TEST_EDIT_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "edit");
			
			testInput = TEST_DELETE_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "delete");

			testInput = TEST_SEARCH_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "search");

			testInput = TEST_MARKDONE_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "mark done");

			testInput = TEST_DISPLAY_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "display");

			testInput = TEST_UNDO_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "undo");

			testInput = TEST_REDO_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "redo");

			testInput = TEST_DIRECTORY_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "directory");

			testInput = TEST_CLEAR_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "clear");
			
			testInput = TEST_EXIT_TASK;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "exit");

			testInput = TEST_INVALID_INPUT;
			testOutput = parser.getCommandWord(testInput);
			Assert::IsTrue(testOutput == "Invalid Command");
			
		}
		
		TEST_METHOD(testTaskType)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "timed");
			
			testInput = TEST_ADD_DEADLINE_TASK ;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "deadline");

			testInput = TEST_ADD_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "floating");

			testInput = TEST_EDIT_TIMED_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "timed");
			
			testInput = TEST_EDIT_DEADLINE_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "deadline");

			testInput = TEST_EDIT_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "floating");

			testInput = TEST_DISPLAY_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "all");

			testInput = TEST_DIRECTORY_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskType();
			Assert::IsTrue(testOutput == "desktop");
		}
		
		TEST_METHOD(testTaskName)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "pj meeting");
			
			testInput = TEST_ADD_DEADLINE_TASK ;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "assignment1");

			testInput = TEST_ADD_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "reply email");

			testInput = TEST_EDIT_TIMED_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "hw meeting");
			
			testInput = TEST_EDIT_DEADLINE_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "assignment2");

			testInput = TEST_EDIT_FLOATING_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getTaskName();
			Assert::IsTrue(testOutput == "send email");

		}
		
		TEST_METHOD(testStartTime)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getStartTime();
			Assert::IsTrue(testOutput == "01-01-2012 10:00");
			
			testInput = TEST_EDIT_TIMED_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getStartTime();
			Assert::IsTrue(testOutput == "03-03-2013 13:33");
			
		}

		TEST_METHOD(testEndTime)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getEndTime();
			Assert::IsTrue(testOutput == "01-01-2012 13:00");
			
			testInput = TEST_ADD_DEADLINE_TASK ;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getEndTime();
			Assert::IsTrue(testOutput == "01-01-2011 13:00");
			
			testInput = TEST_EDIT_TIMED_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getEndTime();
			Assert::IsTrue(testOutput == "04-04-2014 14:44");
			
			testInput = TEST_EDIT_DEADLINE_TASK;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getEndTime();
			Assert::IsTrue(testOutput == "05-05-2015 15:55");
			
		}

		TEST_METHOD(testIndex)
		{
			Parser parser;

			string testInput;
			testInput = TEST_EDIT_TIMED_TASK;
			string output;
			int testOutput;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIndex();
			Assert::IsTrue(testOutput == 1);

			testInput = TEST_EDIT_DEADLINE_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIndex();
			Assert::IsTrue(testOutput == 2);

			testInput = TEST_EDIT_FLOATING_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIndex();
			Assert::IsTrue(testOutput == 3);

			testInput = TEST_DELETE_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIndex();
			Assert::IsTrue(testOutput == 1);
			
			testInput = TEST_MARKDONE_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIndex();
			Assert::IsTrue(testOutput == 2);
			
		}
		
		TEST_METHOD(testSearchWord)
		{
			Parser parser;

			string testInput;
			testInput = TEST_SEARCH_TASK;
			string testOutput;
			testOutput = parser.getCommandWord(testInput);
			testOutput = parser.getSearchWord();
			Assert::IsTrue(testOutput == "assignment");
			
		}
		
		TEST_METHOD(testValidTime)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TIMED_TASK;
			string output;
			bool testOutput;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getvalidTime();;
			Assert::IsTrue(testOutput);

			testInput = TEST_ADD_TIMED_TASK1;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getvalidTime();;
			Assert::IsTrue(!testOutput);

			testInput = TEST_EDIT_TIMED_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getvalidTime();;
			Assert::IsTrue(testOutput);

			testInput = TEST_EDIT_TIMED_TASK1;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getvalidTime();;
			Assert::IsTrue(!testOutput);
			
		}
		
		TEST_METHOD(testIsCorrectFormat)
		{
			Parser parser;

			string testInput;
			testInput = TEST_ADD_TASK;
			string output;
			bool testOutput;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIsCorrectFormat();
			Assert::IsTrue(!testOutput);

			testInput = TEST_ADD_FLOATING_TASK;
			output = parser.getCommandWord(testInput);
			testOutput = parser.getIsCorrectFormat();
			Assert::IsTrue(testOutput);
			
		}
		
		
	};
}

	