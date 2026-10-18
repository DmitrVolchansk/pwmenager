//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNavigationService.h"

#include "AddingFrame.h"
#include "ViewingFrame.h"
#include "EditFrame.h"
#include "UDBMenager.h"
#include "GeneratorForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void NavigationService::openAdding(TShowCaseService& ShowCaseService)
{
	auto addingFrame = new TFAdding(nullptr);
    auto customDlg = new TFCustomDlg(nullptr, addingFrame);
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
	}
}
//---------------------------------------------------------------------------
void NavigationService::openReading(const int id, TCornerButton* OpenViewBtn)
{
    TDataHolder data = dbmenager::getFromDB( id );
	auto viewFrame = new TFViewing(nullptr, data);
	auto viewForm = new TFCustomDlg(nullptr, viewFrame);
	try
	{
		viewForm->ShowModal();
		if ( viewFrame->IsEdited() ) {

			TDataHolder ediedData = viewFrame->getReport();
            OpenViewBtn->Text = ediedData.name;
			dbmenager::updDB( id, ediedData);

		}
	}
	__finally
	{
		delete viewFrame;
		delete viewForm;
	}
}
//---------------------------------------------------------------------------
void NavigationService::openEditing(const id, const TDataHolder& data)
{
	auto editFrame = new TFEdit(nullptr, data);
	auto editForm = new TFCustomDlg(nullptr, editFrame);
	try
	{
		if (editForm->ShowModal() == mrYes) {

			auto updData = editFrame->getReport();
			dbmenager::updDB(id, updData);
            return updData;

		}
	} __finally {
		delete editFrame;
        delete editForm;
	}
    return TDataHolder{};
}
//---------------------------------------------------------------------------
void NavigationService::openGenerator()
{
	auto generator = new TFGenerator(nullptr);
	generator->ShowModal();
	delete generator;
}
//---------------------------------------------------------------------------
void NavigationService::openGenerator(TEdit* Edit)
{
	auto generator = new TFGenerator(nullptr, "Select");
	if ( generator->ShowModal() == mrYes )
		Edit->Text = generator->getSelection();
	delete generator;
}
//---------------------------------------------------------------------------
