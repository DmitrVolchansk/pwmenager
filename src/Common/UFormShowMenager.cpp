//---------------------------------------------------------------------------

#pragma hdrstop

#include "UFormShowMenager.h"

#include "UDBMenager.h"
//---------------------------------------------------------------------------


#pragma package(smart_init)

//---------------------------------------------------------------------------
void FormShowMenager::openForAddition(TShowCaseService& service, TFCustomDlg* form, TFAdding* frame)
{
	if (form->ShowModal() != mrYes) return;

	TDataHolder result = frame->getReport();
	int id = dbmenager::addToDB(result);
	auto showCaseData = TShowCaseParam {
		.id = id,
		.text = result.name
	};
	service.addNew(showCaseData);
}
//---------------------------------------------------------------------------
std::optional<TDataHolder> FormShowMenager::openForEditing(TFCustomDlg* form, TFEdit* frame)
{
	if (form->ShowModal() != mrYes)
        return std::nullopt;
	else
	{
		auto updData = frame->getReport();
		dbmenager::updDB(frame->getID(), updData);
		return updData;
	}
}
//---------------------------------------------------------------------------
System::String FormShowMenager::openForReading(TFCustomDlg* form, TFViewing* frame)
{
	form->ShowModal();
    return frame->getReport().name;
}
//---------------------------------------------------------------------------
std::optional<System::String> FormShowMenager::openForGeneration(TFGenerator* form)
{
	if (form->ShowModal() == mrYes)
		return form->getSelection();
	else
		return std::nullopt;
}

//---------------------------------------------------------------------------
