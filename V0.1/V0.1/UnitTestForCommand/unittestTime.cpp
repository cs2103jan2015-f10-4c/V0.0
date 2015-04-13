//@author A0134921L

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string TEST_TIME1 = "1-3-2011";
const string TEST_TIME2 = "22-3-2012";
const string TEST_TIME3 = "3-12-2012";
const string TEST_TIME4 = "22-11-2012";
const string TEST_TIME5 = "3-2";
const string TEST_TIME6 = "23-7";
const string TEST_TIME7 = "9-12";
const string TEST_TIME8 = "23-12";
const string TEST_TIME9 = "1/3/2012";
const string TEST_TIME10 = "22/3/2012";
const string TEST_TIME11 = "8/10/2012";
const string TEST_TIME12 = "22/11/2012";
const string TEST_TIME13 = "8/1";
const string TEST_TIME14 = "24/5";
const string TEST_TIME15 = "4/12";
const string TEST_TIME16 = "30/10";
const string TEST_TIME17 = "11Jan2001";
const string TEST_TIME18 = "11JAN2001";
const string TEST_TIME19 = "11jan2001";
const string TEST_TIME20 = "11January2001";
const string TEST_TIME21 = "2Feb2002";
const string TEST_TIME22 = "3MAR2003";
const string TEST_TIME23 = "4apr2004";
const string TEST_TIME24 = "5May2005";
const string TEST_TIME25 = "6JUN2006";
const string TEST_TIME26 = "7jul2007";
const string TEST_TIME27 = "8Aug2008";
const string TEST_TIME28 = "9Sep2009";
const string TEST_TIME29 = "10OCT2010";
const string TEST_TIME30 = "11nov2011";
const string TEST_TIME31 = "12December2012";

const string TEST_TIME32 = "22/11/2012 1326";
const string TEST_TIME33 = "22/11/2012 805";

const string TEST_TIME34 = "22/11/2012 8:33";
const string TEST_TIME35 = "22/11/2012 8:02";
const string TEST_TIME36 = "22/11/2012 10:09";
const string TEST_TIME37 = "22/11/2012 11:34";

const string TEST_TIME38 = "22/11/2012 3.20";
const string TEST_TIME39 = "22/11/2012 3.09";
const string TEST_TIME40 = "22/11/2012 11.06";
const string TEST_TIME41 = "22/11/2012 10.26";

const string TEST_TIME42 = "22/11/2012 0853h";
const string TEST_TIME43 = "22/11/2012 1.34h";
const string TEST_TIME44 = "22/11/2012 15.37h";
const string TEST_TIME45 = "22/11/2012 12:47h";

const string TEST_TIME46 = "22/11/2012 0853am";
const string TEST_TIME47 = "22/11/2012 0853pm";
const string TEST_TIME48 = "22/11/2012 04.34am";
const string TEST_TIME49 = "22/11/2012 04.34pm";
const string TEST_TIME50 = "22/11/2012 11:29am";
const string TEST_TIME51 = "22/11/2012 11:29pm";

/*
const string TEST_TIME34 = "22/11/2012 03:51";
const string TEST_TIME35 = "22/11/2012 05.37";
const string TEST_TIME36 = "22/11/2012 0823h";
const string TEST_TIME37 = "22/11/2012 01.34h";
const string TEST_TIME38 = "22/11/2012 12:47h";
const string TEST_TIME39 = "22/11/2012 12:47h";
const string TEST_TIME40 = "12:47h";
const string TEST_TIME41 = "12:47h";
const string TEST_TIME42 = "12:47h";
const string TEST_TIME43 = "12:47h";
const string TEST_TIME44 = "12:47h";
*/


namespace UnitTeststorage
{		
	TEST_CLASS(UnitTestParser)
	{
	public:
		
		TEST_METHOD(testCommandWord)
		{
			TransformTime transformTime;
			string testInput, testOutput;
			int year, month, day;
			time_t time;
			
			testInput = TEST_TIME1;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 01);
			Assert::IsTrue(month == 03);
			Assert::IsTrue(year == 2011);

			testInput = TEST_TIME2;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 22);
			Assert::IsTrue(month == 03);
			Assert::IsTrue(year == 2012);
			
			testInput = TEST_TIME3;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 03);
			Assert::IsTrue(month == 12);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME4;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 22);
			Assert::IsTrue(month == 11);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME5;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 03);
			Assert::IsTrue(month == 02);
			
			testInput = TEST_TIME6;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 23);
			Assert::IsTrue(month == 07);

			testInput = TEST_TIME7;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 9);
			Assert::IsTrue(month == 12);

			testInput = TEST_TIME8;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 23);
			Assert::IsTrue(month == 12);

			testInput = TEST_TIME9;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 01);
			Assert::IsTrue(month == 03);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME10;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 22);
			Assert::IsTrue(month == 03);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME11;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 8);
			Assert::IsTrue(month == 10);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME12;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 22);
			Assert::IsTrue(month == 11);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME13;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 8);
			Assert::IsTrue(month == 01);
			
			testInput = TEST_TIME14;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 24);
			Assert::IsTrue(month == 5);

			testInput = TEST_TIME15;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 4);
			Assert::IsTrue(month == 12);

			testInput = TEST_TIME16;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 30);
			Assert::IsTrue(month == 10);

			testInput = TEST_TIME17;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 11);
			Assert::IsTrue(month == 1);
			Assert::IsTrue(year == 2001);

			testInput = TEST_TIME18;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 11);
			Assert::IsTrue(month == 1);
			Assert::IsTrue(year == 2001);
			
			testInput = TEST_TIME19;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 11);
			Assert::IsTrue(month == 1);
			Assert::IsTrue(year == 2001);

			testInput = TEST_TIME20;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 11);
			Assert::IsTrue(month == 1);
			Assert::IsTrue(year == 2001);

			testInput = TEST_TIME21;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 2);
			Assert::IsTrue(month == 2);
			Assert::IsTrue(year == 2002);

			testInput = TEST_TIME22;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 3);
			Assert::IsTrue(month == 3);
			Assert::IsTrue(year == 2003);

			testInput = TEST_TIME23;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 4);
			Assert::IsTrue(month == 4);
			Assert::IsTrue(year == 2004);

			testInput = TEST_TIME24;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 5);
			Assert::IsTrue(month == 5);
			Assert::IsTrue(year == 2005);

			testInput = TEST_TIME25;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 6);
			Assert::IsTrue(month == 6);
			Assert::IsTrue(year == 2006);

			testInput = TEST_TIME26;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 7);
			Assert::IsTrue(month == 7);
			Assert::IsTrue(year == 2007);

			testInput = TEST_TIME27;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 8);
			Assert::IsTrue(month == 8);
			Assert::IsTrue(year == 2008);

			testInput = TEST_TIME28;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 9);
			Assert::IsTrue(month == 9);
			Assert::IsTrue(year == 2009);

			testInput = TEST_TIME29;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 10);
			Assert::IsTrue(month == 10);
			Assert::IsTrue(year == 2010);

			testInput = TEST_TIME30;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 11);
			Assert::IsTrue(month == 11);
			Assert::IsTrue(year == 2011);

			testInput = TEST_TIME31;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			year = transformTime.getYear(time);
			month = transformTime.getMonth(time);
			day = transformTime.getDay(time);
			Assert::IsTrue(day == 12);
			Assert::IsTrue(month == 12);
			Assert::IsTrue(year == 2012);

			testInput = TEST_TIME32;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 13:26");
			
			testInput = TEST_TIME33;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 08:05");

			testInput = TEST_TIME34;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 08:33");

			testInput = TEST_TIME35;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 08:02");

			testInput = TEST_TIME36;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 10:09");

			testInput = TEST_TIME37;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 11:34");

			testInput = TEST_TIME38;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 03:20");

			testInput = TEST_TIME39;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 03:09");

			testInput = TEST_TIME40;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 11:06");

			testInput = TEST_TIME41;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 10:26");

			testInput = TEST_TIME42;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 08:53");

			testInput = TEST_TIME43;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 01:34");

			testInput = TEST_TIME44;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 15:37");

			testInput = TEST_TIME45;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 12:47");

			testInput = TEST_TIME46;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 08:53");

			testInput = TEST_TIME47;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 20:53");

			testInput = TEST_TIME48;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 04:34");

			testInput = TEST_TIME49;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 16:34");

			testInput = TEST_TIME50;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 11:29");

			testInput = TEST_TIME51;
			testOutput = transformTime.convertTime(testInput);
			time = transformTime.stringToTime(testOutput);
			Assert::IsTrue(testOutput == "22-11-2012 23:29");

		}
		
		
		
	};
}

	