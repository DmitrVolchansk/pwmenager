//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFShowCase *FShowCase;
//---------------------------------------------------------------------------
__fastcall TFShowCase::TFShowCase(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------
