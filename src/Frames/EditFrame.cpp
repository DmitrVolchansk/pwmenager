//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "EditFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AddingFrame"
#pragma resource "*.fmx"
TFEdit *FEdit;
//---------------------------------------------------------------------------
__fastcall TFEdit::TFEdit(TComponent* Owner, const TDataHolder& data, const int id)
	: TFAdding(Owner), id(id)
{
    LoadData(data);
}

int TFEdit::getID() const noexcept
{
    return this->id;
}

//---------------------------------------------------------------------------
