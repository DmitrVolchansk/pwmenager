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


__fastcall TFViewing::TFViewing(TComponent* Owner, const TDataSendler* data) :
	TFBase(Owner)
{
	this->ShortNameEdit->Text += data->get_shortName().c_str();
	this->LoginEdit->Text += data->get_login().c_str();
	this->PasswordEdit->Text += data->get_password().c_str();
}

