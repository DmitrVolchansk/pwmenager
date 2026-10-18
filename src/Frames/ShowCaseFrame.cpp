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
__fastcall TFShowCase::TFShowCase(const TShowCaseParam& params)
	: TFrame(params.Parent), id(params.id)
{
    Parent = params.Parent->Content;
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
void __fastcall TFShowCase::OpenViewBtnClick(TObject *Sender)
{
	TDataHolder data = dbmenager::getFromDB( id );
	auto viewFrame = new TFViewing(nullptr, data);
	auto viewForm = new TFCustomDlg(nullptr, viewFrame);
	try
	{
		viewForm->ShowModal();
		if ( viewFrame->IsEdited() ) {

			TDataHolder ediedData = viewFrame->getReport();
            OpenViewBtn->Text = ediedData.name;
			dbmenager::updDB( id, ediedData);

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

