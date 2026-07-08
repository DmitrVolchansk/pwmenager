//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
#include "CustomDlgForm.h"
#include "ViewingFrame.h"

#include "UTypes.h" // remove
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFShowCase *FShowCase;
//---------------------------------------------------------------------------
__fastcall TFShowCase::TFShowCase(TComponent* Owner, const int id,
		TScrollBox* Parent, const std::string& text)
	: TFrame(Owner)
{
	this->Name += id;
	this->Parent = Parent->Content;
	this->OpenViewBtn->Text = text.c_str();
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
	auto data = new TDataHolder;
    auto viewFrame = new TFViewing(nullptr, data);
	delete data;
    auto viewForm = new TFCustomDlg(nullptr, viewFrame);
	try {
		viewForm->ShowModal();
	} __finally {
        delete viewFrame;
    	delete viewForm;
	}
    // TODO: config connection to db
}
//---------------------------------------------------------------------------

void __fastcall TFShowCase::DeleteBtnClick(TObject *Sender)
{
	OnRequestDelete(this);
	// TODO: connection to db del
    // TODO: add confirm dlg
}
//---------------------------------------------------------------------------

