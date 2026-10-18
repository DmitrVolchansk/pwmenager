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
#include "Utypes.h"
#include <FMX.Layouts.hpp>
//---------------------------------------------------------------------------
class TFBase : public TFrame
{
__published:	// IDE-managed Components
	TEdit *LoginEdit;
	TEdit *ShortNameEdit;
	TEdit *PasswordEdit;
	TCheckBox *PasswordHideCheck;
	TGroupBox *NameGBox;
	TGroupBox *LoginGBox;
	TGroupBox *PWordGBox;
	TButton *CloseBtn;
	TPanel *CloseBtnPnl;
	TLayout *AuthLayout;
	TLayout *PWHelpLayout;
	void __fastcall SwitchPasswordHide(TObject *Sender);
private: // User declarations
protected:	// User declarations
	void LoadData(const TDataHolder& data);
public:		// User declarations
	__fastcall TFBase(TComponent* Owner);
	TDataHolder getReport() const;
};
//---------------------------------------------------------------------------
extern PACKAGE TFBase *FBase;
//---------------------------------------------------------------------------
#endif
