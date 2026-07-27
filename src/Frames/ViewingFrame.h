//---------------------------------------------------------------------------

#ifndef ViewingFrameH
#define ViewingFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include "BaseFrame.h"
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "UTypes.h"
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TFViewing : public TFBase
{
  __published: // IDE-managed Components
	TCornerButton *EditBtn;
	TCornerButton *CopyLoginBtn;
	TCornerButton *CopyPWBtn;
	void __fastcall EditBtnClick(TObject *Sender);
	void __fastcall CopyLoginBtnClick(TObject *Sender);
	void __fastcall CopyPWBtnClick(TObject *Sender);
  private: // User declarations
    bool isEdited;
  public: // User declarations
	__fastcall TFViewing(TComponent* Owner, const TDataHolder* data);
    bool IsEdited() const noexcept;
};
//---------------------------------------------------------------------------
extern PACKAGE TFViewing* FViewing;
//---------------------------------------------------------------------------
#endif

