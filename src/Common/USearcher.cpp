//---------------------------------------------------------------------------

#pragma hdrstop

#include "USearcher.h"
//---------------------------------------------------------------------------
namespace searcher {
	void searchByName(std::vector<TFShowCase*>& cases, const String& name)
	{
		for (auto showCase: cases)
			showCase->Visible = (showCase->getCaseName().LowerCase().Pos(name.LowerCase()) > 0);
	}
	//-----------------------------------------------------------------------
	void reset(std::vector<TFShowCase*>& cases)
	{
		for (auto showCase: cases)
			showCase->Visible = true;
	}
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
