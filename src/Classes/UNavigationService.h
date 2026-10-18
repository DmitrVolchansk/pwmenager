//---------------------------------------------------------------------------

#ifndef UNavigationServiceH
#define UNavigationServiceH
//---------------------------------------------------------------------------
#include "CustomDlgForm.h"
#include "ShowCaseService.h"
#include "UTypes.h"
//---------------------------------------------------------------------------
class NavigationService {
	private:

	public:
		static void openAdding(TShowCaseService& ShowCaseService);
		static void openReading(const int id, TCornerButton* OpenViewBtn);
		static TDataHolder openEditing(const int id, const TDataHolder& data);
		static void openGenerator();
        static void openGenerator(TEdit* Edit);
};
//---------------------------------------------------------------------------
#endif
