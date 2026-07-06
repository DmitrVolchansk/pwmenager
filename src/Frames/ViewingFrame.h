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
//---------------------------------------------------------------------------
class TFViewing : public TFBase
{
  __published: // IDE-managed Components
    TCornerButton* OpenEditBtn;
    TCornerButton* CopyLoginBtn;
    TCornerButton* CopyPasswordBtn;
    TButton* CloseBtn;
  private: // User declarations
  public: // User declarations
    __fastcall TFViewing(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFViewing* FViewing;
//---------------------------------------------------------------------------
#endif

