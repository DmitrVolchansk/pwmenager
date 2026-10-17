//---------------------------------------------------------------------------

#pragma hdrstop

#include "USearch.h"
//---------------------------------------------------------------------------
void Searcher::searchByName(std::vector<TFShowCase*>& cases, const String& name) const noexcept
{
	for (auto showCase: cases)
		if ( showCase->getCaseName().Pos( name ) <= 0 )
			showCase->Visible = false;
}
//---------------------------------------------------------------------------
void Searcher::reset(std::vector<TFShowCase*>& cases) const noexcept
{
	for (auto i: cases)
        i->Visible = true;
}

#pragma package(smart_init)
