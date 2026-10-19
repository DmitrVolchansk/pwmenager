//---------------------------------------------------------------------------

#ifndef UFormShowMenagerH
#define UFormShowMenagerH

#include <optional>

#include "CustomDlgForm.h"
#include "AddingFrame.h"
#include "EditFrame.h"
#include "ViewingFrame.h"
#include "ShowCaseService.h"
#include "GeneratorForm.h"
//---------------------------------------------------------------------------
namespace FormShowMenager {

	void openForAddition(TShowCaseService& service, TFCustomDlg* form, TFAdding* frame);
	std::optional<TDataHolder> openForEditing(TFCustomDlg* form, TFEdit* frame);
	String openForReading(TFCustomDlg* form, TFViewing* frame);
	std::optional<String> openForGeneration(TFGenerator* form);
}
#endif
