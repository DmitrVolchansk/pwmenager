//---------------------------------------------------------------------------

#ifndef ShowCaseFrameH
#define ShowCaseFrameH
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Classes.hpp>

#include <string>
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
	__fastcall TFShowCase(TComponent* Owner, const int id,
		TScrollBox* Parent, const std::string& text);
};
//---------------------------------------------------------------------------
extern PACKAGE TFShowCase *FShowCase;
//---------------------------------------------------------------------------
#endif
