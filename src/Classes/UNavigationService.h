//---------------------------------------------------------------------------

#ifndef UNavigationServiceH
#define UNavigationServiceH
//---------------------------------------------------------------------------
#include <optional>
#include "CustomDlgForm.h"
#include "ShowCaseService.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
class NavigationService {
	public:
		static void openAdding(TShowCaseService& ShowCaseService);
		static std::optional<String> openReading(const int id);
		static std::optional<TDataHolder> openEditing(const int id, const TDataHolder& data);
		static void openGenerator();
        static void openGenerator(TEdit* Edit);
};
//---------------------------------------------------------------------------
#endif
