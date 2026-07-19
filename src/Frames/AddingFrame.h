//---------------------------------------------------------------------------
#ifndef AddingFrameH
#define AddingFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "BaseFrame.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
#include "UTypes.h"
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TFAdding : public TFBase
{
__published:	// IDE-managed Components
	TSpeedButton *OpenGeneratorButton;
	void __fastcall switchCompliteBtnEnable(TObject *Sender);
    void __fastcall OpenGeneratorButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAdding(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFAdding *FAdding;
//---------------------------------------------------------------------------
#endif
