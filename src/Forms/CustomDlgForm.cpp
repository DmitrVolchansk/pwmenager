//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "CustomDlgForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFCustomDlg *FCustomDlg;
//---------------------------------------------------------------------------
__fastcall TFCustomDlg::TFCustomDlg(TComponent* Owner, TFBase* frame)
	: TForm(Owner)
{
	frame->Parent = this;
}
//---------------------------------------------------------------------------
