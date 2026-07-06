//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ViewingFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "BaseFrame"
#pragma resource "*.fmx"
TFViewing *FViewing;
//---------------------------------------------------------------------------
__fastcall TFViewing::TFViewing(TComponent* Owner)
	: TFBase(Owner)
{
}
//---------------------------------------------------------------------------
