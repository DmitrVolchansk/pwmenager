//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "AddingFrame.h"
#include "GeneratorForm.h"
#include "UDBMenager.h"
#include "ShowCaseService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFMain *FMain;

//---------------------------------------------------------------------------
__fastcall TFMain::TFMain(TComponent* Owner)
	: TForm(Owner), ShowCaseService(showCases, ShowCaseLayout)
{
}
//---------------------------------------------------------------------------
void __fastcall TFMain::SwitchSearchPnlVisible(TObject *Sender)
{
	if (SearchPanel->Visible) {
        ShowCaseService.resetShowCaseFilter();
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

			auto showCaseData = TShowCaseParam {
				.id = id,
				.text = result.name
			};
			ShowCaseService.addNew(showCaseData);
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
		auto showCaseData = TShowCaseParam {
			.id = item.id,
			.text = item.name,
			.isOld = item.isOld
		};
        ShowCaseService.addNew(showCaseData);
	}
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SearchBtnClick(TObject *Sender)
{
	ShowCaseService.filterBy(Trim(SearchEdit->Text));
}
//---------------------------------------------------------------------------
