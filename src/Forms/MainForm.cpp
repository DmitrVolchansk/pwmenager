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
		searcher::reset(showCases);
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
            TDataHolder result = addingFrame->getReport();
			int id = dbmenager::addToDB(result);

			auto showCase = new TFShowCase( TShowCaseParam {
				.id = id,
				.Parent = ShowCaseLayout,
				.text = result.name
			});
			showCase->OnFrameDeleted = [this](TFShowCase* f) {
				auto it = std::find(showCases.begin(), showCases.end(), f);
				if (it != showCases.end()) {
					showCases.erase(it);
				}
			};
			showCases.push_back(showCase);
		}
	} __finally {
		delete addingFrame;
		delete customDlg;
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	TInfoVector passwordNames = dbmenager::getAllNames();
	for (const auto& item: passwordNames){
		auto t = new TFShowCase(TShowCaseParam {
			.id = item.id,
			.Parent = ShowCaseLayout,
			.text = item.name,
			.isOld = item.isOld
		});
		t->OnFrameDeleted = [this](TFShowCase* f) {
			auto it = std::find(showCases.begin(), showCases.end(), f);
			if (it != showCases.end()) {
				showCases.erase(it);
			}
		};
		showCases.push_back(t);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SearchBtnClick(TObject *Sender)
{
	searcher::searchByName(showCases, SearchEdit->Text);
}
//---------------------------------------------------------------------------
