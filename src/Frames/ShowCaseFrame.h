//---------------------------------------------------------------------------

#ifndef ShowCaseFrameH
#define ShowCaseFrameH
#include <FMX.Controls.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <System.Classes.hpp>
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
	void __fastcall OpenViewBtnClick(TObject *Sender);
	void __fastcall DeleteBtnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	std::function<void(TFShowCase*)> OnRequestDelete;

	__fastcall TFShowCase(TComponent* Owner, const int id,
		TScrollBox* Parent, const String& text);
};
//---------------------------------------------------------------------------
extern PACKAGE TFShowCase *FShowCase;
//---------------------------------------------------------------------------
#endif
