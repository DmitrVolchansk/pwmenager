//---------------------------------------------------------------------------

#ifndef UNavigationServiceH
#define UNavigationServiceH
//---------------------------------------------------------------------------
#include <optional>
#include "CustomDlgForm.h"
#include "ShowCaseService.h"
#include "UTypes.h"
#include "UFormShowMenager.h"

#include "UFormShowMenager.h"
#include "ViewingFrame.h"
#include "EditFrame.h"
#include "GeneratorForm.h"
#include "UDBMenager.h"
//---------------------------------------------------------------------------
namespace NavigationService {

	template<typename T>
	void openAdding(TShowCaseService& scs)
	{
		T* addingFrame = nullptr;
		TFCustomDlg* customDlg = nullptr;
		try {
			addingFrame = new T(nullptr);
			customDlg = new TFCustomDlg(nullptr, addingFrame);
			FormShowMenager::openForAddition(scs, customDlg, addingFrame);
		} __finally {
			delete addingFrame;
			delete customDlg;
		}
	}

	//-----------------------------------------------------------------------
	template<typename T>
	String openReading(const int id)
	{
		auto data = dbmenager::getFromDB( id );
		T* viewFrame = nullptr;
		TFCustomDlg* viewForm = nullptr;
		try
		{
			viewFrame = new T(nullptr, data, id);
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
	template<typename T>
	std::optional<TDataHolder> openEditing(const int id, const TDataHolder& data)
	{
		T* editFrame = nullptr;
		TFCustomDlg* editForm = nullptr;
		try
		{
			editFrame = new T(nullptr, data, id);
			editForm = new TFCustomDlg(nullptr, editFrame);
			return FormShowMenager::openForEditing(editForm, editFrame);
		} __finally {
			delete editFrame;
			delete editForm;
		}
	}
	//-----------------------------------------------------------------------
	void openGenerator()
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
	std::optional<String> openGenerator(const String& mode)
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
};
//---------------------------------------------------------------------------
#endif
