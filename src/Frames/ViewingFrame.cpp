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
	TFBase(Owner)
{
	LoadData(data);
}
//---------------------------------------------------------------------------
void __fastcall TFViewing::SpeedButton1Click(TObject *Sender)
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

		}
	} __finally {
		delete editFrame;
        delete editForm;
	}
}
//---------------------------------------------------------------------------

