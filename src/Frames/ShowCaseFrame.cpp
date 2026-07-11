//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
#include "CustomDlgForm.h"
#include "ViewingFrame.h"
#include "UDBMenager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFShowCase *FShowCase;
//---------------------------------------------------------------------------
__fastcall TFShowCase::TFShowCase(TComponent* Owner, const int id,
		TScrollBox* ScllBox, const String& text)
	: TFrame(Owner), id(id)
{
	Name = "id" + IntToStr(id);
	Parent = ScllBox->Content;
	OpenViewBtn->Text = text;
    OnRequestDelete = [this](TFShowCase* f) {
		auto ref = f;
		TThread::ForceQueue(nullptr, [ref]() {
			ref->Parent = nullptr;
			delete ref;
		});
	};
}
//---------------------------------------------------------------------------

System::String TFShowCase::getCaseName() const noexcept
{
	return this->OpenViewBtn->Text;
}

//---------------------------------------------------------------------------
void __fastcall TFShowCase::OpenViewBtnClick(TObject *Sender)
{
	TUPtrDataHolder data = TDBMenager::getFromDB( id );
	auto viewFrame = new TFViewing(nullptr, data);
	auto viewForm = new TFCustomDlg(nullptr, viewFrame);
	try
	{
		viewForm->ShowModal();
		if ( viewFrame->IsEdited() ) {

			TUPtrDataHolder ediedData = viewFrame->getReport();
            OpenViewBtn->Text = ediedData->name;
			TDBMenager::updDB( id, ediedData );

		}
	}
	__finally
	{
		delete viewFrame;
		delete viewForm;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFShowCase::DeleteBtnClick(TObject *Sender)
{
	TDBMenager::delFromDB( id );
	OnRequestDelete(this);
}
//---------------------------------------------------------------------------

