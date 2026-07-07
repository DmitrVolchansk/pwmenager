//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "CustomDlgForm.h"
#include "AddingFrame.h"
#include "ShowCaseFrame.h"
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
	auto addingFrame = new TFAdding(nullptr);
	auto addingForm = std::make_unique<TFCustomDlg>(nullptr, addingFrame);
	if (addingForm->ShowModal() != mrYes) return;

	TDataHolder* result = addingFrame->getReport();
	delete addingFrame;
	auto newShowCase = new TFShowCase(this, cases_count++,
								ShowCaseContainer, result->name);
	delete result;
    // TODO: connect to db
}
//---------------------------------------------------------------------------

