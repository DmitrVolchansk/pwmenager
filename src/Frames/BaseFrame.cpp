
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
void __fastcall TFBase::SwitchPasswordHide(TObject *Sender)
{
    PasswordEdit->Password = !(PasswordEdit->Password);
}
//---------------------------------------------------------------------------

