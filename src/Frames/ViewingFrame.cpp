//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ViewingFrame.h"
#include "EditFrame.h"
#include "CustomDlgForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFViewing *FViewing;
//---------------------------------------------------------------------------
__fastcall TFViewing::TFViewing(TComponent* Owner, const TDataHolder* data) :
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
void __fastcall TFViewing::EditBtnClick(TObject *Sender)
{
	TUPtrDataHolder data = std::move( getReport() );
	auto editFrame = new TFEdit(nullptr, data.get());
	auto editForm = new TFCustomDlg(nullptr, editFrame);
	try{
		if (editForm->ShowModal() == mrYes) {

			TUPtrDataHolder updData = std::move( editFrame->getReport() );
			LoadData(updData.get());
            isEdited = true;

		}
	} __finally {
		delete editFrame;
        delete editForm;
	}
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

