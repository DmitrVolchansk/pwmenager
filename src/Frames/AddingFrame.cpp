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

TDataSendler* __fastcall TFAdding::getReport()
{
	std::string name = AnsiString(ShortNameEdit->Text).c_str();
	std::string login = AnsiString(LoginEdit->Text).c_str();
	std::string pw = AnsiString(PasswordEdit->Text).c_str();
	return new TDataSendler(name, login, pw);
}

//---------------------------------------------------------------------------
void __fastcall TFAdding::switchCompliteBtnEnable(TObject* Sender)
{
	CompliteBtn->Enabled = !((ShortNameEdit->Text == "") ||
		(LoginEdit->Text == "") || (PasswordEdit->Text == ""));
}
//---------------------------------------------------------------------------
