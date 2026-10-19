//---------------------------------------------------------------------------

#ifndef UNavigationServiceH
#define UNavigationServiceH
//---------------------------------------------------------------------------
#include <optional>
#include "CustomDlgForm.h"
#include "ShowCaseService.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
namespace NavigationService {

	void openAdding(TShowCaseService& scs);
	String openReading(const int id);
	std::optional<TDataHolder> openEditing(const int id, const TDataHolder& data);
	void openGenerator();
    std::optional<String> openGenerator(const String& mode);
};
//---------------------------------------------------------------------------
#endif
