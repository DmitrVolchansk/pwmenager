#ifndef UFormShowMenagerH
#define UFormShowMenagerH

#include <optional>
#include "CustomDlgForm.h"
#include "ShowCaseService.h"
#include "GeneratorForm.h"
#include "UDBMenager.h"
//---------------------------------------------------------------------------
namespace FormShowMenager {

	template<typename T>
	void openForAddition(TShowCaseService& service, TFCustomDlg* form, T* frame)
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
	template<typename T>
	std::optional<TDataHolder> openForEditing(TFCustomDlg* form, T* frame)
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
	template<typename T>
	System::String openForReading(TFCustomDlg* form, T* frame)
	{
		form->ShowModal();
		return frame->getReport().name;
	}
	//---------------------------------------------------------------------------
	std::optional<System::String> openForGeneration(TFGenerator* form)
	{
		if (form->ShowModal() == mrYes)
			return form->getSelection();
		else
			return std::nullopt;
	}

}

#endif