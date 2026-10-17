//---------------------------------------------------------------------------

#pragma hdrstop

#include "USearcher.h"
//---------------------------------------------------------------------------
void Searcher::searchByName(std::vector<TFShowCase*>& cases, const String& name) noexcept
{
	for (auto showCase: cases)
		showCase->Visible = (showCase->getCaseName().LowerCase().Pos(name.LowerCase()) > 0);
}
//---------------------------------------------------------------------------
void Searcher::reset(std::vector<TFShowCase*>& cases) noexcept
{
	for (auto showCase: cases)
        showCase->Visible = true;
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
