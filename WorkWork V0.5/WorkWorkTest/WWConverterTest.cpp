//@author A0099689W
#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const int    SINGLE_DIGIT_INT               = 5;
const int    ZERO_INT                       = 0;
const int    DOUBLE_DIGIT_INT               = 12;
const int    FOUR_DIGIT_INT                 = 2014;

const string TEST_TIME_HOUR_ZERO                 = "0012";
const string TEST_TIME_MINUTE_ZERO               = "1200";
const string TEST_TIME_BOTH_ZERO                 = "0000";
const string TEST_TIME_SINGLE_DIGIT_HOUR         = "0512";
const string TEST_TIME_SINGLE_DIGIT_MINUTE       = "1205";
const string TEST_TIME_BOTH_SINGLE_DIGIT         = "0505";
const string TEST_TIME_BOTH_DOUBLE_DIGIT         = "1212";

const string TEST_DATE_MONTH_SINGLE_DIGIT        = "20140512";
const string TEST_DATE_DAY_SINGLE_DIGIT          = "20141205";
const string TEST_DATE_BOTH_DOUBLE_DIGIT         = "20141212";
const string TEST_DATE_BOTH_SINGLE_DIGIT         = "20140505";

const string TEST_DISPLAY_DATE_SINGLE_DIGIT_DAY  = "05 Dec 2014";
const string TEST_DISPLAY_DATE_DOUBLE_DIGIT_DAY  = "12 May 2014";

const string TEST_TIME_CASE_1                    = "0000";
const string TEST_TIME_CASE_2                    = "0025";
const string TEST_TIME_CASE_3                    = "0518";
const string TEST_TIME_CASE_4                    = "1200";
const string TEST_TIME_CASE_5                    = "1213";
const string TEST_TIME_CASE_6                    = "2359";
const string TEST_DISPLAY_TIME_1                 = "12:00mn";
const string TEST_DISPLAY_TIME_2                 = "12:25am";
const string TEST_DISPLAY_TIME_3                 = "05:18am";
const string TEST_DISPLAY_TIME_4                 = "12:00nn";
const string TEST_DISPLAY_TIME_5                 = "12:13pm";
const string TEST_DISPLAY_TIME_6                 = "11:59pm";

namespace WWConverterTest
{		
	TEST_CLASS(WWConverterTest)
	{
	public:
		
		TEST_METHOD(convertIntTimeToStringTest)
		{
			WWConverter testConverter;
			int hour, minute;
			std::string expectedOutput, actualOutput;
			//TC1 hour is 0, minute non-zero
			hour = ZERO_INT;
			minute = DOUBLE_DIGIT_INT;
			expectedOutput = TEST_TIME_HOUR_ZERO;
			testConverter.convertIntTimeToString(hour, minute,actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 minute is 0, hour non-zero
			hour  = DOUBLE_DIGIT_INT;
			minute = ZERO_INT;
			expectedOutput = TEST_TIME_MINUTE_ZERO;
			testConverter.convertIntTimeToString(hour,minute,actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC3 neither hour nor minute is 0
			hour  = DOUBLE_DIGIT_INT;
			minute = DOUBLE_DIGIT_INT;
			expectedOutput = TEST_TIME_BOTH_DOUBLE_DIGIT;
			testConverter.convertIntTimeToString(hour,minute,actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC4 both hour and minute are 0
			hour  = ZERO_INT;
			minute = ZERO_INT;
			expectedOutput = TEST_TIME_BOTH_ZERO;
			testConverter.convertIntTimeToString(hour,minute,actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(convertIntDateToStringTest)
		{
			WWConverter testConverter;
			int day, month, year;
			std::string expectedOutput, actualOutput;
			//TC1 single digit day, double digit month
			day = SINGLE_DIGIT_INT; 
			month = DOUBLE_DIGIT_INT;
			year = FOUR_DIGIT_INT;
			expectedOutput = TEST_DATE_DAY_SINGLE_DIGIT;
			testConverter.convertIntDateToString(day, month, year, actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 single digit month, double digit day
			day = DOUBLE_DIGIT_INT;
			month = SINGLE_DIGIT_INT;
			year = FOUR_DIGIT_INT;
			expectedOutput = TEST_DATE_MONTH_SINGLE_DIGIT;
			testConverter.convertIntDateToString(day, month, year, actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC3 both day and month single digit
			day = SINGLE_DIGIT_INT;
			month = SINGLE_DIGIT_INT;
			year = FOUR_DIGIT_INT;
			expectedOutput = TEST_DATE_BOTH_SINGLE_DIGIT;
			testConverter.convertIntDateToString(day, month, year, actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC4 neither day nor month is single digit
			day = DOUBLE_DIGIT_INT;
			month = DOUBLE_DIGIT_INT;
			year = FOUR_DIGIT_INT;
			expectedOutput = TEST_DATE_BOTH_DOUBLE_DIGIT;
			testConverter.convertIntDateToString(day, month, year, actualOutput);
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(convertDateStringToIntTest)
		{
			WWConverter testConverter;
			std::string dateString;
			int day, month, year, expectedday, expectedmonth, expectedyear;
			//TC1 single digit month, double digit day
			dateString = TEST_DATE_MONTH_SINGLE_DIGIT;
			expectedday   = DOUBLE_DIGIT_INT;
			expectedmonth = SINGLE_DIGIT_INT;
			expectedyear  = FOUR_DIGIT_INT;
			testConverter.convertDateStringToInt(dateString, day, month, year);
			Assert::AreEqual(day, expectedday);
			Assert::AreEqual(month, expectedmonth);
			Assert::AreEqual(year, expectedyear);
			//TC2 single digit day, double digit month
			dateString = TEST_DATE_DAY_SINGLE_DIGIT;
			expectedday   = SINGLE_DIGIT_INT;
			expectedmonth = DOUBLE_DIGIT_INT;
			expectedyear  = FOUR_DIGIT_INT;
			testConverter.convertDateStringToInt(dateString, day, month, year);
			Assert::AreEqual(day, expectedday);
			Assert::AreEqual(month, expectedmonth);
			Assert::AreEqual(year, expectedyear);
			//TC3 both day and month single digit
			dateString = TEST_DATE_BOTH_SINGLE_DIGIT;
			expectedday   = SINGLE_DIGIT_INT;
			expectedmonth = SINGLE_DIGIT_INT;
			expectedyear  = FOUR_DIGIT_INT;
			testConverter.convertDateStringToInt(dateString, day, month, year);
			Assert::AreEqual(day, expectedday);
			Assert::AreEqual(month, expectedmonth);
			Assert::AreEqual(year, expectedyear);
			//TC4 neither day nor month single digit
			dateString = TEST_DATE_BOTH_DOUBLE_DIGIT;
			expectedday   = DOUBLE_DIGIT_INT;
			expectedmonth = DOUBLE_DIGIT_INT;
			expectedyear  = FOUR_DIGIT_INT;
			testConverter.convertDateStringToInt(dateString, day, month, year);
			Assert::AreEqual(day, expectedday);
			Assert::AreEqual(month, expectedmonth);
			Assert::AreEqual(year, expectedyear);
		}

		TEST_METHOD(convertTimeStringToIntTest)
		{
			WWConverter testConverter;
			std::string timeString;
			int hour, minute, expectedhour, expectedminute;
			//TC1 hour is 0, minute non-zero
			timeString = TEST_TIME_HOUR_ZERO;
			expectedhour   = ZERO_INT;
			expectedminute = DOUBLE_DIGIT_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC2 minute is zero, hour non-zero
			timeString = TEST_TIME_MINUTE_ZERO;
			expectedhour   = DOUBLE_DIGIT_INT;
			expectedminute = ZERO_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC3 both hour and minute zero
			timeString = TEST_TIME_BOTH_ZERO;
			expectedhour   = ZERO_INT;
			expectedminute = ZERO_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC4 single digit hour, double-digit minute
			timeString = TEST_TIME_SINGLE_DIGIT_HOUR;
			expectedhour   = SINGLE_DIGIT_INT;
			expectedminute = DOUBLE_DIGIT_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC5 single digit minute, double digit hour
			timeString = TEST_TIME_SINGLE_DIGIT_MINUTE;
			expectedhour   = DOUBLE_DIGIT_INT;
			expectedminute = SINGLE_DIGIT_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC6 both hour and minute single digit
			timeString = TEST_TIME_BOTH_SINGLE_DIGIT;
			expectedhour   = SINGLE_DIGIT_INT;
			expectedminute = SINGLE_DIGIT_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			//TC7 neither hour nor minute single digit
			timeString = TEST_TIME_BOTH_DOUBLE_DIGIT;
			expectedhour   = DOUBLE_DIGIT_INT;
			expectedminute = DOUBLE_DIGIT_INT;
			testConverter.convertTimeStringToInt(timeString, hour, minute);
			Assert::AreEqual(hour, expectedhour);
			Assert::AreEqual(minute, expectedminute);
			
		}
		TEST_METHOD(formatDateForDisplayTest)
		{
			WWConverter testConverter;
			std::string expectedOutput, actualOutput;
			//TC1 non-single digit day
			actualOutput = TEST_DATE_MONTH_SINGLE_DIGIT;
			testConverter.formatDateForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_DATE_DOUBLE_DIGIT_DAY;
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 single digit day
			actualOutput = TEST_DATE_DAY_SINGLE_DIGIT;
			testConverter.formatDateForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_DATE_SINGLE_DIGIT_DAY;
			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(formatTimeForDisplayTest)
		{
			WWConverter testConverter;
			std::string expectedOutput, actualOutput;
			//TC1 midnight
			actualOutput = TEST_TIME_CASE_1;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_1;
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC2 00:01 - 00:59
			actualOutput = TEST_TIME_CASE_2;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_2;
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC3 01:00 - 11:59
			actualOutput = TEST_TIME_CASE_3;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_3;
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC4 noon
			actualOutput = TEST_TIME_CASE_4;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_4;
			Assert::AreEqual(expectedOutput, actualOutput); 
			//TC5 12:01 - 12:59
			actualOutput = TEST_TIME_CASE_5;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_5;
			Assert::AreEqual(expectedOutput, actualOutput);
			//TC6 13:00 - 23:59
			actualOutput = TEST_TIME_CASE_6;
			testConverter.formatTimeForDisplay(actualOutput);
			expectedOutput = TEST_DISPLAY_TIME_6;
			Assert::AreEqual(expectedOutput, actualOutput);
			}


			
	};
}