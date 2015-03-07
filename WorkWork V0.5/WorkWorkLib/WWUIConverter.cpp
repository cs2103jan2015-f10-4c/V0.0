//@author A0097195N
#include "WWUIConverter.h"

WWUIConverter::WWUIConverter() {
}

//This method converts an integer value to PageType ( enumeration declared in WWUtilities)
WWUtilities::PageType WWUIConverter::changeFromIntToPageType(int PageIndex) {

	switch(PageIndex) {
		case 0: {
			_pageType = WWUtilities::PAGEALL;
			break;
		}
		case 1: {
			_pageType = WWUtilities::PAGEDEADLINE;
			break; 
		}
		case 2: {
			_pageType = WWUtilities::PAGETIMED;
			break;
		}
		case 3: {
			_pageType = WWUtilities::PAGEFLOATING;
			break; 
		}
		case 4: {
			_pageType = WWUtilities::PAGETODAY;
			break;
		}
		case 5: {
			_pageType = WWUtilities::PAGEDONE;
			break; 
		}
		case 6: {
			_pageType = WWUtilities::PAGEUNDONE;
			break;
		}
		case 7: {
			_pageType = WWUtilities::PAGEOVERDUE;
			break; 
		}
		case 8: {
			_pageType = WWUtilities::PAGESEARCH;
			break; 
		}
		default: {
			_pageType = WWUtilities::PAGEINVALID;
		 }
	}
	return _pageType;
}

