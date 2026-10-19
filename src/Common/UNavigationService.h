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

	void openAdding(TShowCaseService& ShowCaseService);
	std::optional<String> openReading(const int id);
	std::optional<TDataHolder> openEditing(const int id, const TDataHolder& data);
	void openGenerator();
    void openGenerator(TEdit* Edit);
};
//---------------------------------------------------------------------------
#endif
