//@author A0097195N
#include "stdafx.h"
#include "CppUnitTest.h"
#include "WWUtilities.h"
#include "WWUIConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(WWUIConverterTest)
	{
	public:
		//testing the conversion from integer to the corresponding PageType in Utilities
		TEST_METHOD(test_converter) {
			WWUIConverter _convert;
			WWUtilities::PageType pageType;

			pageType = _convert.changeFromIntToPageType(0);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEALL);

			pageType = _convert.changeFromIntToPageType(1);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEDEADLINE);

			pageType = _convert.changeFromIntToPageType(2);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGETIMED);

			pageType = _convert.changeFromIntToPageType(3);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEFLOATING);

			pageType = _convert.changeFromIntToPageType(4);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGETODAY);

			pageType = _convert.changeFromIntToPageType(5);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEDONE);

			pageType = _convert.changeFromIntToPageType(6);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEUNDONE);

			pageType = _convert.changeFromIntToPageType(7);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEOVERDUE);

			pageType = _convert.changeFromIntToPageType(8);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGESEARCH);

			pageType = _convert.changeFromIntToPageType(9);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEINVALID);

			pageType = _convert.changeFromIntToPageType(100);
			Assert::AreEqual((int)pageType,(int)WWUtilities::PAGEINVALID);
		}
	};
}