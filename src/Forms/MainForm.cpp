//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "UFrameMenager.h"
#include "UNavigationService.h"
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
	NavigationService::openGenerator();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::FormCreate(TObject *Sender)
{
	ShowCaseService.load();
}
//---------------------------------------------------------------------------

void __fastcall TFMain::SearchBtnClick(TObject *Sender)
{
	ShowCaseService.filterBy(Trim(SearchEdit->Text));
}
//---------------------------------------------------------------------------
void __fastcall TFMain::AddClick(TObject *Sender)
{
    FrameMenager::launch(ShowCaseService, FrameMenager::mode_t::lgn);
}
//---------------------------------------------------------------------------

