//---------------------------------------------------------------------------

#ifndef USearcherH
#define USearcherH

#include <vector>
#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------
class Searcher {
	public:
		static void searchByName(std::vector<TFShowCase*>& cases, const String& name) noexcept;
		static void reset(std::vector<TFShowCase*>& cases) noexcept;
};
//---------------------------------------------------------------------------

#endif
