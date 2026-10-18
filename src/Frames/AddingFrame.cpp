//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "AddingFrame.h"
//---------------------------------------------------------------------------
#include "UNavigationService.h"
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
//---------------------------------------------------------------------------
void __fastcall TFAdding::switchCompliteBtnEnable(TObject* Sender)
{
	CloseBtn->Enabled = !((ShortNameEdit->Text == "") ||
		(LoginEdit->Text == "") || (PasswordEdit->Text == ""));
}
//---------------------------------------------------------------------------
void __fastcall TFAdding::OpenGeneratorButtonClick(TObject *Sender)
{
	NavigationService::openGenerator(PasswordEdit);
    switchCompliteBtnEnable(Sender);
}
//---------------------------------------------------------------------------
