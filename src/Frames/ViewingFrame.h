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
	TSpeedButton *EditBtn;
	TSpeedButton *CopyLoginBtn;
	TSpeedButton *CopyPWBtn;
	void __fastcall CopyLoginBtnClick(TObject *Sender);
	void __fastcall CopyPWBtnClick(TObject *Sender);
	void __fastcall EditBtnClick(TObject *Sender);
  private: // User declarations
    int id;
  public: // User declarations
	__fastcall TFViewing(TComponent* Owner, const TDataHolder& data, const int id);
    int getID() const noexcept;
};
//---------------------------------------------------------------------------
extern PACKAGE TFViewing* FViewing;
//---------------------------------------------------------------------------
#endif

