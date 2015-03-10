//@author A0097195N
//Description: This class converts the current pageIndex (an integer received from WWGUI)
//             to PageType (enumeration declared in WWUtilities) and pass it to WWLogic

#ifndef WWUICONVERTER_H_
#define WWUICONVERTER_H_

#include "WWUtilities.h"

class WWUIConverter {
private:
	WWUtilities::PageType _pageType;
public:
	WWUIConverter();
	WWUtilities::PageType changeFromIntToPageType(int PageIndex);
};
#endif //WWUICONVERTER_H

