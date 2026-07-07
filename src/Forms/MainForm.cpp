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
	auto generator = std::make_unique<TFGenerator>(nullptr);
	generator->ShowModal();
}
//---------------------------------------------------------------------------


void __fastcall TFMain::AddClick(TObject *Sender)
{
	auto addingFrame = std::make_unique<TFAdding>(nullptr);
	auto addingForm = std::make_unique<TFCustomDlg>(nullptr, addingFrame.release());
	addingForm->ShowModal();

}
//---------------------------------------------------------------------------

