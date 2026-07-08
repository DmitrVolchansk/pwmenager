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
//---------------------------------------------------------------------------
class TFAdding : public TFBase
{
__published:	// IDE-managed Components
	void __fastcall switchCompliteBtnEnable(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAdding(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TFAdding *FAdding;
//---------------------------------------------------------------------------
#endif
