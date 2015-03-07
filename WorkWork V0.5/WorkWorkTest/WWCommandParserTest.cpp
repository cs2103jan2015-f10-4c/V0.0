//@author A0097547M

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TEST_ADD_INPUT = "add test";
const string TEST_DELETE_INPUT = "delete test";
const string TEST_EDIT_INPUT = "edit test";
const string TEST_COMPLETE_INPUT = "complete test";
const string TEST_INCOMPLETE_INPUT = "incomplete test";
const string TEST_SEARCH_INPUT = "search test";
const string TEST_UNDO_INPUT = "undo test";
const string TEST_REDO_INPUT = "redo test";
const string TEST_QUIT_INPUT = "quit test";

const string TEST_VIEWALL_INPUT = "view all test";
const string TEST_VIEWDEADLINE_INPUT = "view deadline test";
const string TEST_VIEWTIMED_INPUT = "view timed test";
const string TEST_VIEWFLOATING_INPUT = "view floating test";
const string TEST_VIEWTODAY_INPUT = "view today test";
const string TEST_VIEWDONE_INPUT = "view complete test";
const string TEST_VIEWUNDONE_INPUT = "view incomplete test";
const string TEST_VIEWOVERDUE_INPUT = "view overdue test";
const string TEST_VIEWSEARCH_INPUT = "view search test";

const string TEST_CASE_SENSITIVE_INPUT = "AdD test";

const string EMPTY_INPUT = "";
const string INVALID_INPUT = "qwerty test";
const string INVALID_VIEW_INPUT = "view qwerty test";
const string WHITESPACE_TAB_INPUT = "	";

const string UNUSED_CONTENT = " test";
const string UNUSED_CONTENT_DELETE = "test";


namespace WorkWorkTest
{
	TEST_CLASS(WWCommandParserTest)
	{
	public:
		
		TEST_METHOD(addCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_ADD_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::ADD);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(deleteCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_DELETE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::DELETE);
			 Assert::AreEqual(UNUSED_CONTENT_DELETE, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(editCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_EDIT_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::EDIT);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(completeCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_COMPLETE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::DONE);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(incompleteCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_INCOMPLETE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::UNDONE);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(searchCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_SEARCH_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::SEARCH);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(undoCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_UNDO_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::UNDO);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(redoCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_REDO_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::REDO);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(quitCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_QUIT_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::EXIT);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(invalidCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(INVALID_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::INVALID);
			 Assert::AreEqual(EMPTY_INPUT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewAllCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWALL_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWALL);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewDeadlineCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWDEADLINE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWDEADLINE);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewTimedCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWTIMED_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWTIMED);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewFloatingCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWFLOATING_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWFLOATING);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewTodayCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWTODAY_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWTODAY);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewDoneCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWDONE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWDONE);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewUndoneCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWUNDONE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWUNDONE);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(viewSearchCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_VIEWSEARCH_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::VIEWSEARCH);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(invalidViewCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(INVALID_VIEW_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::INVALID);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(leadingWhitespaceCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(WHITESPACE_TAB_INPUT + TEST_ADD_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::ADD);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}

		TEST_METHOD(caseInsensitiveCommandParserTest)
		{
			 WWCommandParser testCommandParser;
			 testCommandParser.parseCommand(TEST_CASE_SENSITIVE_INPUT);

			 WWUtilities::CommandType parsedCommandType = testCommandParser.retrieveCommandType();

			 Assert::IsTrue(parsedCommandType == WWUtilities::ADD);
			 Assert::AreEqual(UNUSED_CONTENT, testCommandParser.retrieveUnusedContent());
		}
	};
}