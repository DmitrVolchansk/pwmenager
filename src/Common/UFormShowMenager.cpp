//---------------------------------------------------------------------------

#pragma hdrstop

#include "UFormShowMenager.h"

#include "UDBMenager.h"
//---------------------------------------------------------------------------


#pragma package(smart_init)


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

