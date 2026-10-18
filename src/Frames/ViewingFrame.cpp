//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ViewingFrame.h"
#include "EditFrame.h"
#include "CustomDlgForm.h"
#include "UNavigationService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFViewing *FViewing;
//---------------------------------------------------------------------------
__fastcall TFViewing::TFViewing(TComponent* Owner, const TDataHolder& data) :
	TFBase(Owner), isEdited(false)
{
	LoadData( data );
}
//---------------------------------------------------------------------------
bool TFViewing::IsEdited() const noexcept
{
    return this->isEdited;
}
//---------------------------------------------------------------------------
void __fastcall TFViewing::CopyLoginBtnClick(TObject *Sender)
{
	LoginEdit->SelectAll();
	LoginEdit->CopyToClipboard();
}
//---------------------------------------------------------------------------
void __fastcall TFViewing::CopyPWBtnClick(TObject *Sender)
{
	PasswordEdit->SelectAll();
    PasswordEdit->CopyToClipboard();
}
//---------------------------------------------------------------------------

void __fastcall TFViewing::EditBtnClick(TObject *Sender)
{
	auto data = getReport();
	data = NavigationService::openEditing(id, data);
	if (data != TDataHolder{})
		LoadData(data);
}
//---------------------------------------------------------------------------

