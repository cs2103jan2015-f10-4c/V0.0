//@author A0116363L

#include "stdafx.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(LoggerTest)
	{
	public:
		
		TEST_METHOD(addlog_test)
		{
			
		  RHLogger logger = RHLogger::getInstance();

		  logger.addLog("This is a test");
		  logger.addLog("This is another test");
		  vector<string> actualLogContent = logger.getLogContent();
		  vector<string> expectedLogContent;
		  expectedLogContent.push_back("This is a test");
		  expectedLogContent.push_back("This is another test");

		  Assert::AreEqual(expectedLogContent[0], actualLogContent[0]);
		  Assert::AreEqual(expectedLogContent[1], actualLogContent[1]);

		}


		TEST_METHOD(savelog_test)
		{  
			



		}

	};
}