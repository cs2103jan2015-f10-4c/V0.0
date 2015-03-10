//@author A0099689W
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const int    TEST_MONTH_INT                   = 5;
const int    TEST_INVALID_MONTH_INT           = 0;
const string TEST_UPPERCASE_MONTH_STRING      = "May";
const string TEST_LOWERCASE_MONTH_STRING      = "may";
const string TEST_INVALID_INPUT_MONTH_STRING  = "uri";
const string TEST_INVALID_MONTH_STRING        = "";

namespace WWUtilitiesTest
{		
	TEST_CLASS(WWUtilitiesTest) 
	{
	public:
		
		TEST_METHOD(convertMonthFromStringToIntTest)
		{
			WWUtilities testMonthUtility = WWUtilities::getInstance();
			std::string monthString;
			int expectedOutput, actualOutput;
			//TC1 valid input month string with uppercases
			monthString = TEST_UPPERCASE_MONTH_STRING;
			expectedOutput = TEST_MONTH_INT;
			actualOutput = testMonthUtility.convertMonthFromStringToInt(monthString);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 valid input month string with lowercases
			monthString = TEST_LOWERCASE_MONTH_STRING;
			expectedOutput = TEST_MONTH_INT;
			actualOutput = testMonthUtility.convertMonthFromStringToInt(monthString);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC3 invalid input month string
			monthString = TEST_INVALID_INPUT_MONTH_STRING;
			expectedOutput = TEST_INVALID_MONTH_INT;
			actualOutput = testMonthUtility.convertMonthFromStringToInt(monthString);
			Assert::AreEqual(expectedOutput, actualOutput);
		}
		TEST_METHOD(convertMonthFromIntToStringTest)
		{
			WWUtilities testMonthUtility = WWUtilities::getInstance();
			int monthInt;
			std::string expectedOutput, actualOutput;
			//TC1 test valid month
			monthInt = TEST_MONTH_INT;
			expectedOutput = TEST_UPPERCASE_MONTH_STRING;
			actualOutput = testMonthUtility.convertMonthFromIntToString(monthInt);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 test invalid month
			monthInt = TEST_INVALID_MONTH_INT;
			expectedOutput = TEST_INVALID_MONTH_STRING;
			actualOutput = testMonthUtility.convertMonthFromIntToString(monthInt);
			Assert::AreEqual(expectedOutput, actualOutput);
		}
	};
}