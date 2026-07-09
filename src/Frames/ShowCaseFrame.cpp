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
		TScrollBox* Parent, const String& text)
	: TFrame(Owner)
{
	this->Name = "id" + IntToStr(id);
	this->Parent = Parent->Content;
	this->OpenViewBtn->Text = text;
    OnRequestDelete = [this](TFShowCase* f) {
		auto ref = f;
		TThread::ForceQueue(nullptr, [ref]() {
			ref->Parent = nullptr;
			delete ref;
		});
	};
}
//---------------------------------------------------------------------------
void __fastcall TFShowCase::OpenViewBtnClick(TObject *Sender)
{
	TDataHolder* data = TDBMenager::getFromDB( OpenViewBtn->Text );
	auto viewFrame = new TFViewing(nullptr, data);
	auto viewForm = new TFCustomDlg(nullptr, viewFrame);
	try {
		viewForm->ShowModal();
	} __finally {
        delete data;
		delete viewFrame;
		delete viewForm;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFShowCase::DeleteBtnClick(TObject *Sender)
{
	TDBMenager::delFromDB( OpenViewBtn->Text );
	OnRequestDelete(this);
}
//---------------------------------------------------------------------------

