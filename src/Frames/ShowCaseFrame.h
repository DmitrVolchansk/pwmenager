//---------------------------------------------------------------------------

#ifndef ShowCaseFrameH
#define ShowCaseFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFShowCase : public TFrame
{
__published:	// IDE-managed Components
	TCornerButton *OpenViewBtn;
	TSpeedButton *DeleteBtn;
private:	// User declarations
public:		// User declarations
	__fastcall TFShowCase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFShowCase *FShowCase;
//---------------------------------------------------------------------------
#endif
