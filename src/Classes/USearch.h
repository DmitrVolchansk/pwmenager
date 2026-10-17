//---------------------------------------------------------------------------

#ifndef USearchH
#define USearchH

#include <vector>
#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------

class Searcher {
	public:
		static void searchByName(std::vector<TFShowCase*>& cases, const String& name) const noexcept;
		static void reset(std::vector<TFShowCase*>& cases) const noexcept;
};

#endif
