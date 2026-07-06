//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "GeneratorForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFGenerator *FGenerator;
//---------------------------------------------------------------------------
__fastcall TFGenerator::TFGenerator(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
