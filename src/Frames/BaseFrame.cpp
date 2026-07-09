
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
		.name = ShortNameEdit->Text,
		.login = LoginEdit->Text,
		.pword = PasswordEdit->Text
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
	this->ShortNameEdit->Text = data->name;
	this->LoginEdit->Text = data->login;
	this->PasswordEdit->Text = data->pword;
}
//---------------------------------------------------------------------------

