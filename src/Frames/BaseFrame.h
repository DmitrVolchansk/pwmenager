//---------------------------------------------------------------------------

#ifndef BaseFrameH
#define BaseFrameH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TFBase : public TFrame
{
__published:	// IDE-managed Components
	TGroupBox *LoginHolderGroupBox;
	TPanel *NameHolderPanel;
	TPanel *LoginHolderPanel;
	TPanel *PasswordHolderPanel;
	TEdit *LoginEdit;
	TEdit *ShortNameEdit;
	TEdit *PasswordEdit;
private:	// User declarations
public:		// User declarations
	__fastcall TFBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBase *FBase;
//---------------------------------------------------------------------------
#endif
