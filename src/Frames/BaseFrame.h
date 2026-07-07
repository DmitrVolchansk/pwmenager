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
	TEdit *LoginEdit;
	TEdit *ShortNameEdit;
	TEdit *PasswordEdit;
	TCheckBox *PasswordHideCheck;
	TGroupBox *NameGBox;
	TGroupBox *LoginGBox;
	TGroupBox *PWordGBox;
	TButton *CloseBtn;
	void __fastcall SwitchPasswordHide(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFBase(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFBase *FBase;
//---------------------------------------------------------------------------
#endif
