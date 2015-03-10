//@author A0097547M

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TEST_INPUT = "Test";
const string EMPTY_INPUT = "";

namespace UnitTest
{
	TEST_CLASS(WWCommandTest)
	{
	public:
		
		TEST_METHOD(setValidCommandTest)
		{
			WWCommand testWWCommand;
			
			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());
			
			WWUtilities::CommandType inputCommand = WWUtilities::ADD;
			testWWCommand.setCommand(inputCommand);

			Assert::IsTrue(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::IsTrue(inputCommand == testWWCommand.getCommand());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setInvalidCommandTest)
		{
			WWCommand testWWCommand;
			
			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());
			
			WWUtilities::CommandType inputCommand = WWUtilities::INVALID;
			testWWCommand.setCommand(inputCommand);

			Assert::IsTrue(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::IsTrue(inputCommand == testWWCommand.getCommand());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setDetailTest)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setDetail(TEST_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsTrue(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::AreEqual(TEST_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setDate1Test)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setDate1(TEST_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsTrue(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setTime1Test)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setTime1(TEST_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsTrue(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setDate2Test)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setDate2(TEST_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsTrue(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setTime2Test)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setTime2(TEST_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsTrue(testWWCommand.hasTime2());

			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(setMultipleEmptyTest)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			testWWCommand.setDetail(EMPTY_INPUT);
			testWWCommand.setDate1(EMPTY_INPUT);
			testWWCommand.setTime1(EMPTY_INPUT);
			testWWCommand.setDate2(EMPTY_INPUT);
			testWWCommand.setTime2(EMPTY_INPUT);

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(EMPTY_INPUT, testWWCommand.getTime2());
		}
			
		TEST_METHOD(setMultipleTest)
		{
			WWCommand testWWCommand;

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());

			WWUtilities::CommandType inputCommand = WWUtilities::ADD;
			testWWCommand.setCommand(inputCommand);

			testWWCommand.setDetail(TEST_INPUT);
			testWWCommand.setDate1(TEST_INPUT);
			testWWCommand.setTime1(TEST_INPUT);
			testWWCommand.setDate2(TEST_INPUT);
			testWWCommand.setTime2(TEST_INPUT);

			Assert::IsTrue(testWWCommand.hasCommand());
			Assert::IsTrue(testWWCommand.hasDetail());
			Assert::IsTrue(testWWCommand.hasDate1());
			Assert::IsTrue(testWWCommand.hasTime1());
			Assert::IsTrue(testWWCommand.hasDate2());
			Assert::IsTrue(testWWCommand.hasTime2());

			Assert::IsTrue(inputCommand == testWWCommand.getCommand());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getDetail());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getDate1());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getTime1());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getDate2());
			Assert::AreEqual(TEST_INPUT, testWWCommand.getTime2());
		}

		TEST_METHOD(clearCommandTest)
		{
			WWCommand testWWCommand;

			WWUtilities::CommandType inputCommand = WWUtilities::ADD;
			testWWCommand.setCommand(inputCommand);

			testWWCommand.setDetail(TEST_INPUT);
			testWWCommand.setDate1(TEST_INPUT);
			testWWCommand.setTime1(TEST_INPUT);
			testWWCommand.setDate2(TEST_INPUT);
			testWWCommand.setTime2(TEST_INPUT);

			Assert::IsTrue(testWWCommand.hasCommand());
			Assert::IsTrue(testWWCommand.hasDetail());
			Assert::IsTrue(testWWCommand.hasDate1());
			Assert::IsTrue(testWWCommand.hasTime1());
			Assert::IsTrue(testWWCommand.hasDate2());
			Assert::IsTrue(testWWCommand.hasTime2());

			testWWCommand.clearCommand();

			Assert::IsFalse(testWWCommand.hasCommand());
			Assert::IsFalse(testWWCommand.hasDetail());
			Assert::IsFalse(testWWCommand.hasDate1());
			Assert::IsFalse(testWWCommand.hasTime1());
			Assert::IsFalse(testWWCommand.hasDate2());
			Assert::IsFalse(testWWCommand.hasTime2());
		}
	};
}