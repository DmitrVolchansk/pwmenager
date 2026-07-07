//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "ShowCaseFrame.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFShowCase *FShowCase;
//---------------------------------------------------------------------------
__fastcall TFShowCase::TFShowCase(TComponent* Owner, const int id,
		TScrollBox* Parent, const std::string& text)
	: TFrame(Owner)
{
	this->Name += id;
	this->Parent = Parent->Content;
    this->OpenViewBtn->Text = text.c_str();
}
//---------------------------------------------------------------------------
