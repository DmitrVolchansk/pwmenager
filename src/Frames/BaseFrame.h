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
	TPanel *CloseBtnPnl;
	void __fastcall SwitchPasswordHide(TObject *Sender);
private: // User declarations

protected:	// User declarations
	void LoadData(const TUPtrDataHolder& data);
public:		// User declarations
	__fastcall TFBase(TComponent* Owner);
	TUPtrDataHolder getReport() const;
};
//---------------------------------------------------------------------------
extern PACKAGE TFBase *FBase;
//---------------------------------------------------------------------------
#endif
