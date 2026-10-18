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
#include <System.SysUtils.hpp>
//---------------------------------------------------------------------------
struct TShowCaseParam {
	int id;
	TScrollBox* Parent;
	const String& text;
    bool isOld = false;
};
//---------------------------------------------------------------------------
class TFShowCase : public TFrame
{
__published:	// IDE-managed Components
	TCornerButton *OpenViewBtn;
	TSpeedButton *DeleteBtn;
	TLabel *ActionLbl;
	void __fastcall OpenViewBtnClick(TObject *Sender);
	void __fastcall DeleteBtnClick(TObject *Sender);
private:	// User declarations
    const int id;
public:		// User declarations
	std::function<void(TFShowCase*)> OnFrameDeleted;
	void RequestDelete();
	__fastcall TFShowCase(const TShowCaseParam& params);

    String getCaseName() const noexcept;
};
//---------------------------------------------------------------------------
extern PACKAGE TFShowCase *FShowCase;
//---------------------------------------------------------------------------
#endif
