//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
#include "UDBMenager.h"
#include "UNavigationService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFShowCase *FShowCase;
//---------------------------------------------------------------------------
__fastcall TFShowCase::TFShowCase(TScrollBox* Owner, const TShowCaseParam& params)
	: TFrame(Owner), id(params.id)
{
    Parent = Owner->Content;
	Name = "id" + IntToStr(id);
	ActionLbl->Visible = params.isOld;
	OpenViewBtn->Text = params.text;
}
//---------------------------------------------------------------------------

System::String TFShowCase::getCaseName() const noexcept
{
	return this->OpenViewBtn->Text;
}

//---------------------------------------------------------------------------

void __fastcall TFShowCase::DeleteBtnClick(TObject *Sender)
{
	dbmenager::delFromDB( id );
	auto ref = this;
	TThread::ForceQueue(nullptr, [ref]() {
		ref->Parent = nullptr;
		if (ref->OnFrameDeleted) {
			ref->OnFrameDeleted(ref);
		}
		delete ref;
	});
}
//---------------------------------------------------------------------------

void __fastcall TFShowCase::OpenViewBtnClick(TObject *Sender)
{
	auto name_text = NavigationService::openReading(id);
	if (name_text.has_value() && name_text == OpenViewBtn->Text)
		OpenViewBtn->Text = *name_text;
}
//---------------------------------------------------------------------------

