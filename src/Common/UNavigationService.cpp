//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNavigationService.h"

#include "UFormShowMenager.h"
#include "ViewingFrame.h"
#include "EditFrame.h"
#include "GeneratorForm.h"

#include "UDBMenager.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
void NavigationService::openAdding(TShowCaseService& scs)
{
	TFAdding* addingFrame = nullptr;
	TFCustomDlg* customDlg = nullptr;
	try {
		addingFrame = new TFAdding(nullptr);
		customDlg = new TFCustomDlg(nullptr, addingFrame);
		FormShowMenager::openForAddition(scs, customDlg, addingFrame);
	} __finally {
		delete addingFrame;
		delete customDlg;
	}
}
//-----------------------------------------------------------------------
String NavigationService::openReading(const int id)
{
	auto data = dbmenager::getFromDB( id );
	TFViewing* viewFrame = nullptr;
	TFCustomDlg* viewForm = nullptr;
	try
	{
		viewFrame = new TFViewing(nullptr, data, id);
		viewForm = new TFCustomDlg(nullptr, viewFrame);
		return FormShowMenager::openForReading(viewForm, viewFrame);
	}
	__finally
	{
		delete viewFrame;
		delete viewForm;
	}
}
//-----------------------------------------------------------------------
std::optional<TDataHolder> NavigationService::openEditing(const int id, const TDataHolder& data)
{
	TFEdit* editFrame = nullptr;
	TFCustomDlg* editForm = nullptr;
	try
	{
		editFrame = new TFEdit(nullptr, data, id);
		editForm = new TFCustomDlg(nullptr, editFrame);
		return FormShowMenager::openForEditing(editForm, editFrame);
	} __finally {
		delete editFrame;
		delete editForm;
	}
}
//-----------------------------------------------------------------------
void NavigationService::openGenerator()
{
	TFGenerator* generator = nullptr;
	try {
		generator = new TFGenerator(nullptr);
		generator->ShowModal();
	} __finally {
		delete generator;
	}
}
//-----------------------------------------------------------------------
std::optional<String> NavigationService::openGenerator(const String& mode)
{
	TFGenerator* generator = nullptr;
	try {
		generator = new TFGenerator(nullptr, mode);
		return FormShowMenager::openForGeneration(generator);
	}
	__finally {
		delete generator;
	}
}
//---------------------------------------------------------------------------
