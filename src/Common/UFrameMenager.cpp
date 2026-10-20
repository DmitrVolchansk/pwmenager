//---------------------------------------------------------------------------

#pragma hdrstop

#include "UFrameMenager.h"

#include "AddingFrame.h"
#include "UNavigationService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


void FrameMenager::launch(TShowCaseService& scs, const mode_t mode)
{
	NavigationService::openAdding<TFAdding>(scs);
}
