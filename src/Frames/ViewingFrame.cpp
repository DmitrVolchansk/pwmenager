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
	LoadData(data);
}
//---------------------------------------------------------------------------
bool TFViewing::IsEdited()
{
    return this->isEdited;
}
//---------------------------------------------------------------------------
void __fastcall TFViewing::EditBtnClick(TObject *Sender)
{
	TDataHolder* data = getReport();
	auto editFrame = new TFEdit(nullptr, data);
    delete data;
	auto editForm = new TFCustomDlg(nullptr, editFrame);
	try{
		if (editForm->ShowModal() == mrYes) {

			TDataHolder* updData = editFrame->getReport();
			LoadData(updData);
			delete updData;
            isEdited = true;

		}
	} __finally {
		delete editFrame;
        delete editForm;
	}
}
//---------------------------------------------------------------------------

