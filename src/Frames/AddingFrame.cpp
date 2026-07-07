//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AddingFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFAdding *FAdding;
//---------------------------------------------------------------------------
__fastcall TFAdding::TFAdding(TComponent* Owner)
	: TFBase(Owner)
{
}

TDataHolder* __fastcall TFAdding::getReport()
{
	auto dataHolder = new TDataHolder;
	dataHolder->name = AnsiString(ShortNameEdit->Text).c_str();
	dataHolder->login = AnsiString(LoginEdit->Text).c_str();
	dataHolder->pword = AnsiString(PasswordEdit->Text).c_str();
	return dataHolder;
}

//---------------------------------------------------------------------------
void __fastcall TFAdding::switchCompliteBtnEnable(TObject* Sender)
{
	CloseBtn->Enabled = !((ShortNameEdit->Text == "") ||
		(LoginEdit->Text == "") || (PasswordEdit->Text == ""));
}
//---------------------------------------------------------------------------
