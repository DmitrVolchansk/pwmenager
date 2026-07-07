//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
#include "CustomDlgForm.h"
#include "ViewingFrame.h"

#include "UDataSendler.h" // remove
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
}
//---------------------------------------------------------------------------
void __fastcall TFShowCase::OpenViewBtnClick(TObject *Sender)
{
	TDataSendler* data = new TDataSendler();
	auto viewFrame = std::make_unique<TFViewing>(nullptr, data);
	auto viewForm = std::make_unique<TFCustomDlg>(nullptr, viewFrame.release());
	viewForm->ShowModal();
	delete data;
    // TODO: config connection to db
}
//---------------------------------------------------------------------------

