//---------------------------------------------------------------------------

#pragma hdrstop

#include "ShowCaseService.h"

#include "UDBMenager.h"
//---------------------------------------------------------------------------
TShowCaseService::TShowCaseService(std::vector<TFShowCase*>& vector, TScrollBox* pare) :
	showCaseVector(vector), layout(pare)
{}
//---------------------------------------------------------------------------
TFShowCase* TShowCaseService::createCase(const TShowCaseParam& params)
{
	auto showCase = new TFShowCase(layout, params);
	showCase->OnFrameDeleted = [this](TFShowCase* f) {
		auto it = std::find(showCaseVector.begin(), showCaseVector.end(), f);
		if (it != showCaseVector.end()) {
			showCaseVector.erase(it);
		}
	};
	return showCase;
}
//---------------------------------------------------------------------------
void TShowCaseService::addNew(const TShowCaseParam& params)
{
    showCaseVector.push_back(createCase(params));
}
//---------------------------------------------------------------------------
bool TShowCaseService::contains(const String& str1, const String& str2) const noexcept
{
	return str1.LowerCase().Pos(str2.LowerCase());
}
//---------------------------------------------------------------------------
void TShowCaseService::filterBy(const String& name) const noexcept
{
	for (auto showCase: showCaseVector)
		showCase->Visible = contains(showCase->getCaseName(), name);
}
//---------------------------------------------------------------------------
void TShowCaseService::resetShowCaseFilter() const noexcept
{
    for (auto showCase: showCaseVector)
		showCase->Visible = true;
}

void TShowCaseService::load()
{
    TMetaDTOVector records = dbmenager::getAllNames();
	for (const auto& item: records){
		auto showCaseData = TShowCaseParam {
			.id = item.id,
			.text = item.name,
			.isOld = item.isOld
		};
        addNew(showCaseData);
	}
}

//---------------------------------------------------------------------------
#pragma package(smart_init)
