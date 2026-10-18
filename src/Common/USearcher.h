//---------------------------------------------------------------------------

#ifndef USearcherH
#define USearcherH

#include <vector>
#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------
namespace searcher {
	void searchByName(std::vector<TFShowCase*>& cases, const String& name);
	void reset(std::vector<TFShowCase*>& cases);
};
//---------------------------------------------------------------------------

#endif
