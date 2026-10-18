
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
TDataHolder TFBase::getReport() const
{
	return TDataHolder {
		.name = ShortNameEdit->Text,
		.login = LoginEdit->Text,
		.pword = PasswordEdit->Text
	};
}
//---------------------------------------------------------------------------
void __fastcall TFBase::SwitchPasswordHide(TObject *Sender)
{
    PasswordEdit->Password = PasswordHideCheck->IsChecked;
}
//---------------------------------------------------------------------------
void TFBase::LoadData(const TDataHolder& data)
{
	this->ShortNameEdit->Text = data.name;
	this->LoginEdit->Text = data.login;
	this->PasswordEdit->Text = data.pword;
}
//---------------------------------------------------------------------------

