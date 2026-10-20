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
__fastcall TFViewing::TFViewing(TComponent* Owner, const TDataHolder& data, const int id) :
	TFBase(Owner), id(id)
{
	LoadData( data );
}
//---------------------------------------------------------------------------
int TFViewing::getID() const noexcept
{
    return this->id;
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
	auto upData = NavigationService::openEditing<TFEdit>(id, getReport());
	if (upData.has_value())
		LoadData(*upData);
}
//---------------------------------------------------------------------------

