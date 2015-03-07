//@author A0105476E

//**************************************************************
//			    Unit Test: SystemResponse Class
//					  Author: AI YUE
//
//			      File: testSystemResponse.cpp
//**************************************************************

#include "stdafx.h"
#include "CppUnitTest.h"
#include "WWSystemResponse.h"
#include "WWUtilities.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ExecutorUnitTest
{
	TEST_CLASS(testSystemResponse)
	{
	public:
		
		TEST_METHOD(TestAddResponse) 
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of add successed
			systemResponse.setSystemResponse(WWUtilities::ADD, "taskName", true);
			expectedSystemResponse = "taskName created";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//negative test, test the case of add failed
			systemResponse.setSystemResponse(WWUtilities::ADD, "taskName", false);
			expectedSystemResponse = "Please input task name";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//boundary test, test the case of long taskName
			systemResponse.setSystemResponse(WWUtilities::ADD, "taskName01taskName02taskName03taskName04taskName05taskName06taskName07", true);
			expectedSystemResponse = "taskName01taskName02taskName03taskName04taskName05... created";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

		}
	
		TEST_METHOD(TestDeleteResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of delete succeed
			systemResponse.setSystemResponse(WWUtilities::DELETE, "taskName", true);
			expectedSystemResponse = "taskName deleted";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//negative test, test the case of delete failed
			systemResponse.setSystemResponse(WWUtilities::DELETE, "taskName", false);
			expectedSystemResponse = "Index not found";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestEditResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of edit successed
			systemResponse.setSystemResponse(WWUtilities::EDIT, "taskName", true);
			expectedSystemResponse = "taskName edited";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//negative test, test the case of edit failed
			systemResponse.setSystemResponse(WWUtilities::EDIT, "taskName", false);
			expectedSystemResponse = "Index not found";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestDoneResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of done successed
			systemResponse.setSystemResponse(WWUtilities::DONE, "taskName", true);
			expectedSystemResponse = "taskName is marked as completed";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//negative test, test the case of done failed
			systemResponse.setSystemResponse(WWUtilities::DONE, "taskName", false);
			expectedSystemResponse = "taskName is already completed";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestUndoneResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of undone successed
			systemResponse.setSystemResponse(WWUtilities::UNDONE, "taskName", true);
			expectedSystemResponse = "taskName is marked as incomplete";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);

			//negative test, test the case of undone failed
			systemResponse.setSystemResponse(WWUtilities::UNDONE, "taskName", false);
			expectedSystemResponse = "taskName is already incomplete";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestInvalidResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//positive test, test the case of undone successed
			systemResponse.setSystemResponseInvalid();
			expectedSystemResponse = "Invalid command";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestSearchResponse)
		{
			WWSystemResponse systemResponse;
			std::string expectedSystemResponse;
			std::string actualSystemResponse;

			//test the response of search
			systemResponse.setSystemResponseSearch(1);
			expectedSystemResponse = "1 results are found";			
			actualSystemResponse = systemResponse.getSystemResponse();
			Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewAllResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWALL, 5);
			 std::string expectedSystemResponse = "You have 5 tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewTodayResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWTODAY, 5);
			 std::string expectedSystemResponse = "You have 5 tasks for today";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewOverdueResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWOVERDUE, 5);
			 std::string expectedSystemResponse = "You have 5 overdue tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewUndoneResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWUNDONE, 5);
			 std::string expectedSystemResponse = "You have 5 incomplete tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewDoneResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWDONE, 5);
			 std::string expectedSystemResponse = "You have 5 completed tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewFloatingResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWFLOATING, 5);
			 std::string expectedSystemResponse = "You have 5 floating tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewTimedResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWTIMED, 5);
			 std::string expectedSystemResponse = "You have 5 timed tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}

		TEST_METHOD(TestViewDeadlineResponse)
		{
			 WWSystemResponse systemResponse;
			 systemResponse.setSystemResponseView(WWUtilities::VIEWDEADLINE, 5);
			 std::string expectedSystemResponse = "You have 5 deadline tasks in total";
			 std::string actualSystemResponse = systemResponse.getSystemResponse();
			 Assert::AreEqual(expectedSystemResponse, actualSystemResponse);
		}
	};
} 