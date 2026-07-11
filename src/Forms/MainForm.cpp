//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "CustomDlgForm.h"
#include "AddingFrame.h"
#include "ShowCaseFrame.h"
#include "GeneratorForm.h"
#include "UDBMenager.h"
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
	auto generator = new TFGenerator(nullptr);
	generator->ShowModal();
    delete generator;
}
//---------------------------------------------------------------------------
void __fastcall TFMain::AddClick(TObject *Sender)
{
	auto addingFrame = new TFAdding(nullptr);
	auto addingForm = new TFCustomDlg(nullptr, addingFrame);
	try {
		if (addingForm->ShowModal() == mrYes) {

			TUPtrDataHolder result = std::move( addingFrame->getReport() );
			int id = TDBMenager::addToDB(result);
			new TFShowCase(this, id, ShowCaseContainer, result->name);

		}
	} __finally {
		delete addingFrame;
        delete addingForm;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	TUPtrMapIntStr passwordNames = std::move( TDBMenager::getAllNames() );
	for (const auto& pair: *passwordNames){
		new TFShowCase(this, pair.first, ShowCaseContainer, pair.second);
	}
}
//---------------------------------------------------------------------------

