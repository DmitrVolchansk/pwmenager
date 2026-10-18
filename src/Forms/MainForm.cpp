//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "AddingFrame.h"
#include "GeneratorForm.h"
#include "UDBMenager.h"
#include "USearcher.h"
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
	if (SearchPanel->Visible) {
		Searcher::reset(showCases);
        SearchEdit->Text = EmptyStr;
	}
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
	this->customDlg = new TFCustomDlg(nullptr, addingFrame);
	try {
		if (customDlg->ShowModal() == mrYes) {

			TUPtrDataHolder result = addingFrame->getReport();
			int id = TDBMenager::addToDB(result.get());
			showCases.push_back(new TFShowCase(this, id, ShowCaseLayout, result->name));

		}
	} __finally {
		delete addingFrame;
		delete customDlg;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	TInfoVector passwordNames = TDBMenager::getAllNames();
	for (const auto& item: passwordNames)
		showCases.push_back(new TFShowCase(this, item.id, ShowCaseLayout, item.name, item.isOld));
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SearchBtnClick(TObject *Sender)
{
	Searcher::searchByName(showCases, SearchEdit->Text);
}
//---------------------------------------------------------------------------
