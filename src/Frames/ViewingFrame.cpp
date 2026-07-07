//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ViewingFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFViewing *FViewing;
//---------------------------------------------------------------------------
__fastcall TFViewing::TFViewing(TComponent* Owner, const TDataHolder* data) :
	TFBase(Owner)
{
	this->ShortNameEdit->Text += data->name.c_str();
	this->LoginEdit->Text += data->login.c_str();
	this->PasswordEdit->Text += data->pword.c_str();
}
//---------------------------------------------------------------------------

