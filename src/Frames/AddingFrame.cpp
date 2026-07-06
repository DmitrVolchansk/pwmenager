//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AddingFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFAdding *FAdding;
//---------------------------------------------------------------------------
__fastcall TFAdding::TFAdding(TComponent* Owner)
	: TFBase(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFAdding::switchCompliteBtnEnable(TObject *Sender)
{
	CompliteBtn->Enabled = (ShortNameEdit->Text & 1) ||
		(LoginEdit->Text & 1) || (PasswordEdit->Text & 1);
}
//---------------------------------------------------------------------------
