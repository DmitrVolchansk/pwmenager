
//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "BaseFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFBase *FBase;
//---------------------------------------------------------------------------
__fastcall TFBase::TFBase(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
TDataHolder* __fastcall TFBase::getReport()
{
	return new TDataHolder {
		.name = AnsiString(ShortNameEdit->Text).c_str(),
		.login = AnsiString(LoginEdit->Text).c_str(),
		.pword = AnsiString(PasswordEdit->Text).c_str()
	};
}

//---------------------------------------------------------------------------
void __fastcall TFBase::SwitchPasswordHide(TObject *Sender)
{
    PasswordEdit->Password = !(PasswordEdit->Password);
}
//---------------------------------------------------------------------------
void __fastcall TFBase::LoadData(const TDataHolder* data)
{
	this->ShortNameEdit->Text = data->name.c_str();
	this->LoginEdit->Text = data->login.c_str();
	this->PasswordEdit->Text = data->pword.c_str();
}
//---------------------------------------------------------------------------

