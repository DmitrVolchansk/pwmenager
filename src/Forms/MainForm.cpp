//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "CustomDlgForm.h"
#include "AddingFrame.h"
#include "GeneratorForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFMain *FMain;
//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMain::SwitchSearchPnlVisible(TObject *Sender)
{
    this->SearchPanel->Visible = !(this->SearchPanel->Visible);
}
//---------------------------------------------------------------------------
void __fastcall TFMain::GenerateClick(TObject *Sender)
{
	TFGenerator *generator = new TFGenerator(this);
	try {
		generator->ShowModal();
	} __finally {
		delete generator;
	}
}
//---------------------------------------------------------------------------


void __fastcall TFMain::AddClick(TObject *Sender)
{
	TCustomDlg *addingForm = new TCustomDlg(this);
}
//---------------------------------------------------------------------------

