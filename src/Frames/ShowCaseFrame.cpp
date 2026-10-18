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
__fastcall TFShowCase::TFShowCase(TComponent* Owner, const TShowCaseParam& param)
	: TFrame(Owner), id(param.id)
{
	Name = "id" + IntToStr(param.id);
	ActionLbl->Visible = param.isOld;
	Parent = param.Parent->Content;
	OpenViewBtn->Text = param.text;

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
	OnRequestDelete(this);
}
//---------------------------------------------------------------------------

