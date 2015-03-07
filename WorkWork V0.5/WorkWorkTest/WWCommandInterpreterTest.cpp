//@author A0099689W
#include "stdafx.h"
#include "CppUnitTest.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string EMPTY_CONTENT                = "";
const string NON_EMPTY_DATE               = "20140420";
const string NON_EMPTY_TIME               = "2209";
const string NON_EMPTY_TASKNAME           = "test";
const string EDITDETAIL_INDEX_AND_NAME    = "2 test";
const string EDITDETAIL_INDEX_AND_NO_NAME = "2";
const string EDITDETAIL_TASKNAME          = "test";
const int    EDITDETAIL_INDEX             = 2;
const int    EDITDETAIL_INVALID_INDEX     = -1;
const string TEST_INDEX_STRING            = "78";
const string TEST_INDEX_ZERO_STRING       = "0";
const string TEST_INDEX_NEGATIVE_STRING   = "-193";
const int    TEST_INDEX_INT               = 78;
const int    TEST_INDEX_ZERO_INT          = 0;
const int    TEST_INDEX_NEGATIVE_INT      = -193;



namespace WWCommandInterpreterTest
{		
	TEST_CLASS(WWCommandInterpreterTest)
	{
	public:
		
		TEST_METHOD(InterpretAddTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			WWTask testTask;
			std::string expectedDetail, expectedDate1, expectedDate2, expectedTime1, expectedTime2;
			//TC1 all 5 components non-empty
			expectedDetail = NON_EMPTY_TASKNAME;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = NON_EMPTY_TIME;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = NON_EMPTY_TIME;
			
			testCommand.setCommand(WWUtilities::CommandType::ADD);
			testCommand.setDetail(expectedDetail);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);
			
			testInterpreter.interpretAdd(testCommand, testTask);
			
			Assert::AreEqual(expectedDetail, testTask.getTaskName());
			Assert::AreEqual(expectedDate1, testTask.getStartDate());
			Assert::AreEqual(expectedTime1, testTask.getStartTime());
			Assert::AreEqual(expectedDate2, testTask.getEndDate());
			Assert::AreEqual(expectedTime2, testTask.getEndTime());
			//TC2 task with empty components
			expectedDetail = NON_EMPTY_TASKNAME;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = EMPTY_CONTENT;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = EMPTY_CONTENT;
			
			testCommand.setCommand(WWUtilities::CommandType::ADD);
			testCommand.setDetail(expectedDetail);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);

			testInterpreter.interpretAdd(testCommand, testTask);

			Assert::AreEqual(expectedDetail, testTask.getTaskName());
			Assert::AreEqual(expectedDate1, testTask.getStartDate());
			Assert::AreEqual(expectedTime1, testTask.getStartTime());
			Assert::AreEqual(expectedDate2,  testTask.getEndDate());
			Assert::AreEqual(expectedTime2, testTask.getEndTime());
		}

		TEST_METHOD(InterpretEditTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			int expectedIndex, actualIndex;
			WWTask testTask;
			std::string expectedDetail, expectedDate1, expectedDate2, expectedTime1, expectedTime2;
			std::string commandDetail;
			testCommand.setCommand(WWUtilities::CommandType::EDIT);
			//TC1 command detail contain both index and taskname
			commandDetail  = EDITDETAIL_INDEX_AND_NAME;
			expectedDetail = EDITDETAIL_TASKNAME;
			expectedIndex  = EDITDETAIL_INDEX;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = NON_EMPTY_TIME;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = NON_EMPTY_TIME;
			
			testCommand.setDetail(commandDetail);
		    testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);

			testInterpreter.interpretEdit(testCommand, actualIndex, testTask);
	  
			Assert::AreEqual(expectedIndex, actualIndex);
			Assert::AreEqual(expectedDetail, testTask.getTaskName());
			Assert::AreEqual(expectedDate1, testTask.getStartDate());
			Assert::AreEqual(expectedTime1, testTask.getStartTime());
			Assert::AreEqual(expectedDate2,  testTask.getEndDate());
			Assert::AreEqual(expectedTime2, testTask.getEndTime());
			//TC2 command detail contain index and no taskname
			commandDetail = EDITDETAIL_INDEX_AND_NO_NAME;
			expectedDetail = EMPTY_CONTENT;
			expectedIndex = EDITDETAIL_INDEX;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = NON_EMPTY_TIME;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = NON_EMPTY_TIME;
			
			testCommand.setDetail(commandDetail);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);
			
			testInterpreter.interpretEdit(testCommand, actualIndex, testTask);
	        
			Assert::AreEqual(expectedIndex, actualIndex);
			Assert::AreEqual(expectedDetail, testTask.getTaskName());
			Assert::AreEqual(expectedDate1, testTask.getStartDate());
			Assert::AreEqual(expectedTime1, testTask.getStartTime());
			Assert::AreEqual(expectedDate2,  testTask.getEndDate());
			Assert::AreEqual(expectedTime2, testTask.getEndTime());
			//TC3 command detail contain no index and taskname;
			commandDetail = EMPTY_CONTENT;
			expectedDetail = EMPTY_CONTENT;
			expectedIndex = EDITDETAIL_INVALID_INDEX;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = NON_EMPTY_TIME;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = NON_EMPTY_TIME;
			
			testCommand.setDetail(commandDetail);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);
			
			testInterpreter.interpretEdit(testCommand, actualIndex, testTask);
	        
			Assert::AreEqual(expectedIndex, actualIndex);
			Assert::AreEqual(expectedDetail, testTask.getTaskName());
			Assert::AreEqual(expectedDate1, testTask.getStartDate());
			Assert::AreEqual(expectedTime1, testTask.getStartTime());
			Assert::AreEqual(expectedDate2,  testTask.getEndDate());
			Assert::AreEqual(expectedTime2, testTask.getEndTime());
		} 
		TEST_METHOD(interpretSearchTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			std::vector<std::string> keywordStorage;
			std::string expectedKeyword, expectedDate1, expectedDate2, expectedTime1, expectedTime2;
			std::string actualKeyword, actualDate1, actualDate2, actualTime1, actualTime2;
			testCommand.setCommand(WWUtilities::CommandType::SEARCH);
			//TC1 command only contains keyword, no date and time
			expectedKeyword = NON_EMPTY_TASKNAME;
			expectedDate1  = EMPTY_CONTENT;
			expectedTime1  = EMPTY_CONTENT;
			expectedDate2  = EMPTY_CONTENT;
			expectedTime2  = EMPTY_CONTENT;
			
			testCommand.setDetail(expectedKeyword);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);
			
			testInterpreter.interpretSearch(testCommand, keywordStorage);
	       
			Assert::AreEqual(expectedKeyword, keywordStorage[0]);
			Assert::AreEqual(expectedDate1, keywordStorage[1]);
			Assert::AreEqual(expectedTime1, keywordStorage[2]);
			Assert::AreEqual(expectedDate2, keywordStorage[3]);  
			Assert::AreEqual(expectedTime2, keywordStorage[4]);
			//TC2 command has no keyword but a single date.
			expectedKeyword = EMPTY_CONTENT;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = EMPTY_CONTENT;
			expectedDate2  = EMPTY_CONTENT;
			expectedTime2  = EMPTY_CONTENT;
			
			testCommand.setDetail(expectedKeyword);
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);
			
			testInterpreter.interpretSearch(testCommand, keywordStorage);
	        
			Assert::AreEqual(expectedKeyword, keywordStorage[0]);
			Assert::AreEqual(expectedDate1, keywordStorage[1]);
			Assert::AreEqual(expectedTime1, keywordStorage[2]);
			Assert::AreEqual(expectedDate2, keywordStorage[3]);  
			Assert::AreEqual(expectedTime2, keywordStorage[4]);
			//TC3 command has all the keyword and starting and ending dates & times.
			expectedKeyword = NON_EMPTY_TASKNAME;
			expectedDate1  = NON_EMPTY_DATE;
			expectedTime1  = NON_EMPTY_TIME;
			expectedDate2  = NON_EMPTY_DATE;
			expectedTime2  = NON_EMPTY_TIME;
			
			testCommand.setDetail(expectedKeyword);
			
			testCommand.setDate1(expectedDate1);
			testCommand.setTime1(expectedTime1);
			testCommand.setDate2(expectedDate2);
			testCommand.setTime2(expectedTime2);

			testInterpreter.interpretSearch(testCommand, keywordStorage);

	        Assert::AreEqual(expectedKeyword, keywordStorage[0]);
			Assert::AreEqual(expectedDate1, keywordStorage[1]);
			Assert::AreEqual(expectedTime1, keywordStorage[2]);
			Assert::AreEqual(expectedDate2, keywordStorage[3]);  
			Assert::AreEqual(expectedTime2, keywordStorage[4]);
		}

		TEST_METHOD(interpretDeleteTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			int expectedIndex, actualIndex;
			testCommand.setCommand(WWUtilities::CommandType::DELETE);
			//TC1 positive index
			testCommand.setDetail(TEST_INDEX_STRING);
			expectedIndex = TEST_INDEX_INT;
			testInterpreter.interpretDelete(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);

			//TC2 zero index
			testCommand.setDetail(TEST_INDEX_ZERO_STRING);
			expectedIndex = TEST_INDEX_ZERO_INT;
			testInterpreter.interpretDelete(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
			
			//TC3 negative index
			testCommand.setDetail(TEST_INDEX_NEGATIVE_STRING);
			expectedIndex = TEST_INDEX_NEGATIVE_INT;
			testInterpreter.interpretDelete(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(interpretDoneTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			int expectedIndex, actualIndex;
			testCommand.setCommand(WWUtilities::CommandType::DONE);
			//TC1 positive index
			testCommand.setDetail(TEST_INDEX_STRING);
			expectedIndex = TEST_INDEX_INT;
			testInterpreter.interpretDone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);

			//TC2 zero index
			testCommand.setDetail(TEST_INDEX_ZERO_STRING);
			expectedIndex = TEST_INDEX_ZERO_INT;
			testInterpreter.interpretDone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
			
			//TC3 negative index
			testCommand.setDetail(TEST_INDEX_NEGATIVE_STRING);
			expectedIndex = TEST_INDEX_NEGATIVE_INT;
			testInterpreter.interpretDone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		TEST_METHOD(interpretUndoneTest)
		{
			WWCommandInterpreter testInterpreter;
			WWCommand testCommand;
			int expectedIndex, actualIndex;
			testCommand.setCommand(WWUtilities::CommandType::UNDONE);
			//TC1 positive index
			testCommand.setDetail(TEST_INDEX_STRING);
			expectedIndex = TEST_INDEX_INT;
			testInterpreter.interpretUndone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);

			//TC2 zero index
			testCommand.setDetail(TEST_INDEX_ZERO_STRING);
			expectedIndex = TEST_INDEX_ZERO_INT;
			testInterpreter.interpretUndone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
			
			//TC3 negative index
			testCommand.setDetail(TEST_INDEX_NEGATIVE_STRING);
			expectedIndex = TEST_INDEX_NEGATIVE_INT;
			testInterpreter.interpretUndone(testCommand, actualIndex);
			Assert::AreEqual(expectedIndex, actualIndex);
		}
		
		
	};
}