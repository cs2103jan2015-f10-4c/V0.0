//@author A0101014L
// WWTaskTimeTest.cpp

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

const string PAST_DATE     = "20140411";
const string PAST_TIME     = "0001";
const string FUTURE_DATE   = "20240411";
const string FUTURE_TIME   = "2359";

namespace WorkWorkTest
{
	TEST_CLASS(WWTaskTimeTest)
	{
	public:
		
		TEST_METHOD(checkOverdue) 
		{
			WWTaskTime taskTime;
			
			Assert::IsTrue(taskTime.isOverdue(PAST_DATE, PAST_TIME));
			Assert::IsTrue(taskTime.isOverdue(PAST_DATE, FUTURE_TIME));
			Assert::IsFalse(taskTime.isOverdue(FUTURE_DATE, PAST_TIME));
			Assert::IsFalse(taskTime.isOverdue(FUTURE_DATE, FUTURE_TIME));
		}
	};
}